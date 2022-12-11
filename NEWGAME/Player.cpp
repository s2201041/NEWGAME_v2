#include "Player.h"
#include "Game.h"

Player::Player(Game* gm, Vec2 pos,int typ,Rect are,int vel) : Base(gm, pos, typ, are, vel)
{
	Are = Rect{0,150,600,450};

	game = gm;

	base_vel = vel;

	Dir.clear();
	Hp = 100;
	Max_Hp = 100;
	Vel2.clear();

	shot_cool = 0;

	NearPos.clear();

	//コライダーの初期化
	Col = Circle{ Pos, 30 };

	//キー操作
		switch (Typ){
		case 1:
			inputLeft = KeyLeft;
			inputRight = KeyRight;
			inputUp = KeyUp;
			inputDown = KeyDown;
			inputShot = KeySpace;
			inputItem = KeyZ;
	Nam = U"プレイヤー1";
			break;
		case 2:
			inputLeft = KeyA;
			inputRight = KeyD;
			inputUp = KeyW;
			inputDown = KeyS;
			inputShot = KeyZ;
			inputItem = KeyZ;
	Nam = U"プレイヤー2";
			break;
		}

	linework
		.setThickness(minThickness, maxThickness)
		.setLineCount(static_cast<size_t>(lineCount))
		.setOffsetRange(offsetRange);

}


void Player::sub_update()
{
	//クールタイム
	if (shot_cool >= 0) shot_cool -= Scene::DeltaTime();

	auto controller = XInput(playerIndex);

	const Vec2 m_c = Vec2{ controller.leftThumbX,-controller.leftThumbY } * Scene::DeltaTime() * zero(Vel);

	const Vec2 s_c = Vec2{ controller.rightThumbX, -controller.rightThumbY }.setLength(1);

	//移動処理
	const Vec2 move = Vec2{ (inputRight.pressed() - inputLeft.pressed()), (inputDown.pressed() - inputUp.pressed()) }
	.setLength(Scene::DeltaTime() * zero(Vel) * (KeyShift.pressed() ? 0.5 : 1.0));

	if(move.x!=0||move.y!=0)
		Pos.moveBy(move).clamp(Are);
	else	
		Pos.moveBy(m_c).clamp(Are);

	//ショットの処理
	if (inputShot.down() || controller.buttonB.down()) {
		game->pl_shot << Shot{ game, this, Pos ,{0,-1},500 ,1 , game->Are };
		shot_cool = 0.2;
	}
	else if ((controller.leftTrigger||inputShot.pressed()||controller.buttonB.pressed())&&shot_cool<=0) {
		if(controller.leftTrigger)
			game->pl_shot << Shot{game, this, Pos ,s_c,500 ,1 , game->Are};
		else
			game->pl_shot << Shot{game, this, Pos ,{0,-1},500 ,1 , game->Are};
		shot_cool = 0.25;
	}

	//アイテムの使用処理
	if (inputItem.down()||controller.buttonA.down())
		if(item.size()!=0)
			item[0].use(this);

	//Hp0以下の処理
	if (0 >= Hp) 
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 30 };

	for (int i = 0; i < item.size(); i++)
		item[i].has_update(i);

	item.remove_if([](const Item& it) { return it.Del == true; });

	effect.update();

	if (Vel > base_vel) {
		offsetRange = Random(0.60);
		linework.setOffsetRange(offsetRange);
	}
}

void Player::sub_draw() const
{
	if (Typ == 10) {
		Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });
		return;
	}

	TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	if (inputRight.pressed())
		TextureAsset(U"player_1_right").scaled(2.0).drawAt(Pos);
	else if (inputLeft.pressed())
		TextureAsset(U"player_1_left").scaled(2.0).drawAt(Pos);
	else if (inputDown.pressed())
		TextureAsset(U"player_1_down").scaled(2.0).drawAt(Pos);
	else 
		TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	for (int i = 0; i < item.size(); i++)
		item[i].sub_draw();

	if(Vel>base_vel)
		linework.draw(ColorF{ 0,0,0,0.1});

}

void Player::cla(Shot* it) {
}

void Player::cla(Base* en) {
}

int Player::zero(int i) {
	if (0 > i)
		return 0;
	else
		return i;
}

