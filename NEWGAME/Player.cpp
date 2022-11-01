#include "Player.h"
#include "Game.h"

Player::Player(Game * gam,Vec2 pos,int typ,Rect are) : Base(pos, typ, are)
{

	game = gam;

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
		if (KeyShift.pressed()) {
			shot << Shot{ Pos ,{0,-1} ,500 ,2 ,Are };
		}
		else
			shot << Shot{ Pos ,{0,-1} ,500 ,1 ,Are};
	}

	//ショットの動作処理
	for (auto& sh : shot){
		sh.GoPos = NearPos;
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
	TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	if (inputRight.pressed())
		TextureAsset(U"player_1_right").scaled(2.0).drawAt(Pos);
	else if (inputLeft.pressed())
		TextureAsset(U"player_1_left").scaled(2.0).drawAt(Pos);
	else if (inputDown.pressed())
		TextureAsset(U"player_1_down").scaled(2.0).drawAt(Pos);
	else 
		TextureAsset(U"player_1_up").scaled(2.0).drawAt(Pos);

	//ショットの描画
	for (auto& en : shot)
		en.draw();

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });

}

//void Player::sh_cla(int typ) {
//	if(!(Hp <= 0))
//		Hp -= 5;
//}

void Player::en_cla(int typ) {
	switch (typ) {
	case 100:
		Vel = 1000;
		break;
	}
}
