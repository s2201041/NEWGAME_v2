#include "Base.h"
#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Shot.h"



Base::Base(Game* gam, Base* ent, Vec2 pos, Vec2 dir, int vel, int typ, Rect are)
	:Pos(pos),Dir(dir),Vel(vel),Typ(typ),Are(are),Del(false)
{
	Timer = 0;
	NearPos = { 0,0 };
}

Base::Base(Game* gam, Vec2 pos, int typ, Rect are)
	:game(gam),Pos(pos),Typ(typ),Are(are),Del(false)
{
	game = gam;
	Timer = 0;
	NearPos = { 0,0 };
}

void Base::update()
{
	sub_update();
}

void Base::draw() const
{
	sub_draw();
}

void Base::cla(Base* en) {
}

