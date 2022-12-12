#include "Entity.h"
#include "Game.h"

Entity::Entity(Game* gm, Vec2 pos, int typ, Rect are,int hp,int time_left) : Base(gm, pos, typ, are)

{
	game = gm;

	Dir = { 0,1 };
	Vel = 1100;
	Hp = 100;
	Max_Hp = 100;
	size = 45;
	GoPos = { Random(1,100),Random(1,100) };
	Time_Left = 0;

	Hp = hp;
	Max_Hp = hp;
	Time_Left = time_left;

		;
	//タイプ別の初期値の初期化
	switch (Typ) {
	case 11:
		//直線
		break;

	case 12:
		//向き追跡
		Nam = U"敵_B";
		break;

	case 13:
		//弾幕
		Nam = U"敵_C";
		break;

	case 14:
		Nam = U"敵_D";
		break;

	case 15:
		Nam = U"敵_E";
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

	case 15:

		Pos = Pos.lerp(NearPos, 0.05);

		if (Timer > 1.5) {
			game->item << Item{ game,Pos,2,Are };
			Timer = 0;
		}

		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;
	}

	//自動消滅	
	if (Time > Time_Left&&Time_Left!=0)
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
	const Vec2 Pos_D = Pos - GoPos;
	const Vec2 Pos_E = Pos - NearPos;

	switch (Typ) {
	case 11:
		if(Pos_D.x<-10)
			TextureAsset(U"enemy_3_right").scaled(2.0).drawAt(Pos);
		else if(Pos_D.x>10)
			TextureAsset(U"enemy_3_left").scaled(2.0).drawAt(Pos);
		else if(0>=Pos_D.y)
			TextureAsset(U"enemy_3_down").scaled(2.0).drawAt(Pos);
		else 
			TextureAsset(U"enemy_3_up").scaled(2.0).drawAt(Pos);
		break;
	case 12:
		if(Pos_D.x<-10)
			TextureAsset(U"enemy_2_right").scaled(2.0).drawAt(Pos);
		else if(Pos_D.x>10)
			TextureAsset(U"enemy_2_left").scaled(2.0).drawAt(Pos);
		else if(0>=Pos_D.y)
			TextureAsset(U"enemy_2_down").scaled(2.0).drawAt(Pos);
		else 
			TextureAsset(U"enemy_2_up").scaled(2.0).drawAt(Pos);
		break;
	case 13:
			TextureAsset(U"enemy_1").scaled(2.0).drawAt(Pos);
		break;

	case 14:
		TextureAsset(U"ki").scaled(2.0).drawAt(Pos);
		break;
	case 15:
		if(Pos_E.x<0)
			TextureAsset(U"enemy_4_right").scaled(2.0).drawAt(Pos);
		else
			TextureAsset(U"enemy_4_left").scaled(2.0).drawAt(Pos);
	}
}

void Entity::cla(Shot* en) {
	const int dma = Random(8, 12) + ((Time_Left - Time)/Time_Left) * 20;
	en->entity->score += dma;
	game->effect.add<ScoreEffect>(Pos, dma);
}

void Entity::cla(Base* en) {
}
