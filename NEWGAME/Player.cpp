﻿#include "Player.h"
#include "Game.h"

Player::Player(Game* sh, Vec2 pos,int typ,Rect are) : Base(pos, typ, are)
{
	m_texture = Texture{ U"texture/player/player.png" };

	Dir = { 0,0 };
	Hp = 100;

	NearPos = { 0,0 };

	//コライダーの初期化
	Col = Circle{ Pos, 30 };

	shot = sh;
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
	.setLength(Scene::DeltaTime() * 550 * (KeyShift.pressed() ? 0.5 : 1.0));

	Pos.moveBy(move).clamp(Scene::Rect()).clamp(Are);

	if (inputShot.down()) {
		if (KeyShift.pressed())
			shot->shot << Shot{ Pos ,{0,-1} ,900 ,2 ,0 ,Are };
		else
			shot->shot << Shot{ Pos ,{0,-1} ,500 ,1 ,0 ,Are};
	}

	//Hp0以下の処理
	if (0 >= Hp)
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 30 };
}

void Player::draw() const
{
	m_texture.scaled(2.0).drawAt(Pos);

	if(inputRight.pressed())
		TextureAsset(U"player_1_right").scaled(2.0).drawAt(Pos);
	else if (inputLeft.pressed())
		TextureAsset(U"player_1_left").scaled(2.0).drawAt(Pos);
	else if (inputDown.pressed())
		TextureAsset(U"player_1_down").scaled(2.0).drawAt(Pos);
	else 
		TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });

}

//void Player::sh_cla(int typ) {
//	if(!(Hp <= 0))
//		Hp -= 5;
//}

void Player::en_cla(int typ) {
	switch (typ) {
	case 2:

		break;
	}
}
