#include "Player.h"
#include "Game.h"

Player::Player(Game* gm, Vec2 pos,int typ,Rect are) : Base(pos, typ, are)
{

	game = gm;

	Dir = { 0,0 };
	Hp = 100;
	Vel = 550;

	NearPos = { 0,0 };

	//コライダーの初期化
	Col = Circle{ Pos, 30 };

}

void Player::update() 
{
	//キー操作
		switch (Typ){
		case 1:
			inputLeft = KeyLeft;
			inputRight = KeyRight;
			inputUp = KeyUp;
			inputDown = KeyDown;
			inputShot = KeySpace;
			break;
		case 2:
			inputLeft = KeyA;
			inputRight = KeyD;
			inputUp = KeyW;
			inputDown = KeyS;
			inputShot = KeyZ;
			break;
		}


	const Vec2 move = Vec2{ (inputRight.pressed() - inputLeft.pressed()), (inputDown.pressed() - inputUp.pressed()) }
	.setLength(Scene::DeltaTime() * Vel * (KeyShift.pressed() ? 0.5 : 1.0));

	Pos.moveBy(move).clamp(Scene::Rect()).clamp(Are);

	if (inputShot.down()) {
		if (KeyShift.pressed())
			game->pl_shot << Shot{this, Pos, { 0, -1 }, 1000, 2, Are };
		else
			game->pl_shot << Shot{this, Pos ,{ 0, -1 } ,500 ,1 ,Are};
	}

	//Hp0以下の処理
	if (0 >= Hp) 
		Del = true;


	//コライダーの更新
	Col = Circle{ Pos, 30 };

	for (int i = 0; i < item.size(); i++)
		item[i].update(i);
}

void Player::draw() const
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

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });
	
	for (int i = 0; i < item.size(); i++)
		item[i].draw(i);

	effect.update();

	Print << item.size();

}

void Player::cla(Item* it) {
	item << *it;
}

void Player::cla(Base* en) {
}



