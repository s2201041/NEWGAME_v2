#include "Player.h"
#include "Game.h"

Player::Player(Game* gm, Vec2 pos,int typ,Rect are) : Base(gm, pos, typ, are)
{
	Are = Rect{0,150,600,450};

	game = gm;

	Nam = U"プレイヤー1";

	Dir.clear();
	Hp = 100;
	Max_Hp = 100;
	Vel = 350;
	Vel2.clear();

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
			break;
		case 2:
			inputLeft = KeyA;
			inputRight = KeyD;
			inputUp = KeyW;
			inputDown = KeyS;
			inputShot = KeyZ;
			inputItem = KeyZ;
			break;
		}

}

void Player::sub_update() 
{
	//移動処理
	const Vec2 move = Vec2{ (inputRight.pressed() - inputLeft.pressed()), (inputDown.pressed() - inputUp.pressed()) }
	.setLength(Scene::DeltaTime() * zero(Vel) * (KeyShift.pressed() ? 0.5 : 1.0));

	Pos.moveBy(move).clamp(Are);

	/*
	Vel2.x += inputRight.pressed() - inputLeft.pressed();
	if (Vel2.x > 0) Vel2.x -= 0.5; else if (Vel2.x < 0) Vel2.x += 0.5;
	Vel2.y += inputDown.pressed() - inputUp.pressed();
	if (Vel2.y > 0) Vel2.y -= 0.5; else if (Vel2.y < 0) Vel2.y += 0.5;

	Vel2.clamp(Rect{-10,-10,20,20});

	Pos.moveBy(Vel2).clamp(Are);

	ClearPrint();
	Print << Vel2;
	*/

	/*/ショットの角度調節
	const Vec2 shot_dir = Vec2{ (KeyD.pressed() - KeyA.pressed()), (KeyS.pressed() - KeyW.pressed()) }
	.setLength(1);
	*/

	//ショットの処理
	if (inputShot.down()) {
		if (KeyShift.pressed()) {
			game->pl_shot << Shot{ game, this, Pos,dir(NearPos,Pos),1000, 1, game->Are };
		}
		else
			game->pl_shot << Shot{game, this, Pos ,{0,-1},500 ,3 , game->Are};
	}

	//アイテムの使用処理
	if (inputItem.down()) 
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
}

void Player::sub_draw() const
{

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
		item[i].has_draw(i);


}

void Player::cla(Item* it) {
}

void Player::cla(Base* en) {
}

int Player::zero(int i) {
	if (0 > i)
		return 0;
	else
		return i;
}

