﻿#include "Entity.h"
#include "Game.h"

Entity::Entity(Game* gm, Vec2 pos, int typ, Rect are) : Base(gm, pos, typ, are)

{
	game = gm;

	Dir = { 0,1 };
	Vel = 1100;
	Hp = 100;
	Max_Hp = 100;
	size = 45;
	GoPos = { Random(1,100),Random(1,100) };

	//タイプ別の初期値の初期化
	switch (Typ) {
	case 11:
		Nam = U"敵_A";
		Hp = 400;
		Max_Hp = 400;
		break;

	case 12:
		Nam = U"敵_B";
		Hp = 200;
		Max_Hp =200;
		break;

	case 13:
		Nam = U"敵_C";
		Hp = 400;
		Max_Hp =400;
		break;

	case 14:
		Nam = U"敵_D";
		Hp = 400;
		Max_Hp =400;
		break;

	}
}

void Entity::sub_update()
{

	//タイプ別の動作処理の分岐
	switch (Typ) {
	case 11:

		Pos = Pos.lerp(GoPos, 0.1);

		if (Timer > 0.5) {
			game->en_shot << Shot{game, this,Pos ,{0,1} ,900 ,5 ,Are};
			GoPos = { NearPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

	case 12:

		Pos = Pos.lerp(GoPos, 0.2);

		if (Timer > 0.5) {
			game->en_shot << Shot{game, this,Pos ,dir(NearPos,Pos) ,900 ,1 ,Are};
			GoPos = { NearPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

	case 13:

		Pos.x = 300 + Sin(Time/2)*300;

		if (Timer > 0.1) {

			game->en_shot << Shot{ game, this,Pos ,Dir,300 ,1 ,Are };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		Dir.rotate(Scene::DeltaTime()*3);

		break;

	case 14:

		Pos = Pos.lerp(GoPos, 0.1);
		if (Timer > 1.5) {
			game->en_shot << Shot{game, this,Pos ,dir(NearPos,Pos) ,310 ,4 ,Are};
			GoPos = { NearPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

	}

	if (Time > 15)
		Del = true;

	//すり抜け防止
	Pos.clamp(Are);

	//Hp0以下の敵の消去
	if (0 >= Hp) {
		Del = !Del;
		game->Kill++;
		game->effect.add<BubbleEffect>(Pos, Random(0.0, 360.0));
	}

	//コライダーの更新
	Col = Circle{ Pos, size };

}

void Entity::sub_draw() const
{

	switch (Typ) {
	case 11:
		TextureAsset(U"enemy_1").scaled(2.0).drawAt(Pos);
		break;

	case 12:
		TextureAsset(U"enemy_2").scaled(2.0).drawAt(Pos);
		break;

	case 13:
		TextureAsset(U"enemy_3").scaled(2.0).drawAt(Pos);
		break;

	case 14:
		TextureAsset(U"ki").scaled(2.0).drawAt(Pos);
		break;
	}
}

void Entity::cla(Shot* en) {
	const int dma = Random(10, 20);
	game->Score += dma;
	game->effect.add<ScoreEffect>(Pos, dma);
}

void Entity::cla(Base* en) {
}
