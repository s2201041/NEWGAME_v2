#include "Base.h"
#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Shot.h"

Base::Base() {};

Base::Base(Game* gm, Base* ent, Vec2 pos, Vec2 dir, int vel, int typ, Rect are)
	:Pos(pos),Dir(dir),Vel(vel),Typ(typ),Are(are),Del(false)
{
	game = gm;
	Timer = 0;
	NearPos = { 0,0 };
}

Base::Base(Game* gm, Vec2 pos, int typ, Rect are)
	:game(gm),Pos(pos),Typ(typ),Are(are),Del(false)
{
	game = gm;
	Timer = 0;
	NearPos = { 0,0 };
}

void Base::update()
{
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

