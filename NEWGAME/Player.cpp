#include "Player.h"

Player::Player(Vec2 pos,int typ,Rect are)
	:m_texture{ U"texture/player/player.png" }
{
	Pos = pos;
	//Vel = vel;
	Typ = typ;
	Are = are;
	Dir = { 0,0 };
	Hp = 100;

	EnPos = { 0,0 };

	Del = false;

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
	.setLength(Scene::DeltaTime() * 550 * (KeyShift.pressed() ? 0.5 : 1.0));

	Pos.moveBy(move).clamp(Scene::Rect()).clamp(Are);

	if (inputShot.down()) {
		if (KeyShift.pressed())
			shot << Shot{ Pos ,{0,-1} ,500 ,3 ,Are};
		else
			shot << Shot{ Pos ,{0,-1} ,500 ,1 ,Are};
	}
	//ショットの動作処理
	for (auto& sh : shot){
		sh.GoPos = EnPos;
		sh.update();
	}

	//ショットの消滅処理
	shot.remove_if([](const Shot& sh) { return sh.Del == true;  });

	//Hp0以下の処理
	if (0 >= Hp)
		Del = true;



	//コライダーの更新
	Col = Circle{ Pos, 30 };
}

void Player::draw() const
{
	m_texture.scaled(2.0).drawAt(Pos);


	TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	//ショットの描画
	for (auto& en : shot)
		en.draw();

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });


	//HPゲージの描画
	//RectF{ 610 , 550, Hp * 1.8, 20 }.draw(Palette::Red);;
	//RectF{ 610 , 550, 180, 20 }.draw(Palette::Orange);;

}

void Player::sh_cla() {
	if(!(Hp <= 0))
		Hp -= 5;
}

void Player::en_cla(int typ) {
	switch (typ) {
	case 2:
		break;
	}
}
