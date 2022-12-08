#include "Base.h"
#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Shot.h"

Base::Base() {};

Base::Base(Game* gm, Base* ent, Vec2 pos, Vec2 dir, int vel, int typ, Rect are)
	:game(gm),Pos(pos),Dir(dir),Vel(vel),Typ(typ),Are(are),Del(false)
{
	p_Dam = 100;
	Time = 0;
	Timer = 0;
	NearPos = { 300,300 };
}

Base::Base(Game* gm, Vec2 pos, int typ, Rect are)
	:game(gm),Pos(pos),Typ(typ),Are(are),Del(false)
{
	p_Dam = 100;
	Time = 0;
	Timer = 0;
	NearPos = { 300,300 };
}

Base::Base(Game* gm, Vec2 pos, int typ, Rect are,int vel)
	:game(gm),Pos(pos),Typ(typ),Are(are),Del(false),Vel(vel)
{
	p_Dam = 100;
	Time = 0;
	Timer = 0;
	NearPos = { 300,300 };
}

void Base::update()
{
	Time += Scene::DeltaTime();

	//派生処理の実行
	sub_update();
}

void Base::draw() const
{
	//派生処理の実行
	sub_draw();
}

void Base::cla(Base* en) {
}

Vec2 Base::dir(Vec2 PosA,Vec2 PosB)
{
	Vec2 N = PosA - PosB;

	double M = 1 / sqrt(N.x * N.x + N.y * N.y);
	
	return { N.x * M,N.y * M };
}
