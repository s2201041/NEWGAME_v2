#include "Player.h"
#include "Game.h"

Player::Player(Game* gm, Vec2 n,int typ,Rect are) : Base(gm, Pos, typ, are)
{
	Are = Rect{0,150,600,550};

	game = gm;

	Dir = { 0,0 };
	Hp = 100;
	Max_Hp = 100;
	Vel = 350;

	NearPos = { 0,0 };

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
			break;
		case 2:
			inputLeft = KeyA;
			inputRight = KeyD;
			inputUp = KeyW;
			inputDown = KeyS;
			inputShot = KeyZ;
			break;
		}

}

void Player::sub_update() 
{
	const Vec2 move = Vec2{ (inputRight.pressed() - inputLeft.pressed()), (inputDown.pressed() - inputUp.pressed()) }
	.setLength(Scene::DeltaTime() * Vel * (KeyShift.pressed() ? 0.5 : 1.0));

	Pos.moveBy(move);

	Pos.clamp(Are);

	N = Cursor::Pos() - Pos;

	M = sqrt(N.x * N.x + N.y * N.y);

	O = 1 / M;

	Dir = { N.x * O,N.y * O };

	if (inputShot.down()) {
		if (KeyShift.pressed())
			game->pl_shot << Shot{game, this, Pos,{0,-1}, 1000, 4, game->Are};
		else
			game->pl_shot << Shot{game, this, Pos ,Dir,500 ,1 , game->Are};
	}

	//Hp0以下の処理
	if (0 >= Hp) 
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 30 };

	for (int i = 0; i < item.size(); i++)
		item[i].has_update(i);

	item.remove_if([](const Item& it) { return it.Del == true; });
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

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });

	for (int i = 0; i < item.size(); i++)
		item[i].has_draw(i);

	effect.update();

}

void Player::cla(Item* it) {
	item << Item{this,it->Typ};
}

void Player::cla(Base* en) {
}



