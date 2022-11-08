#include "Base.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Shot.h"


Base::Base(Vec2 pos,int typ,Rect are)
	:Pos(pos),Typ(typ),Are(are),Del(false)
{
	Timer = 0;
	NearPos = { 0,0 };
}

Base::Base(Vec2 pos, Vec2 dir, int vel, int typ, Rect are)
	:Pos(pos),Dir(dir),Vel(vel),Typ(typ),Are(are),Del(false)
{
	Timer = 0;
	NearPos = { 0,0 };
}

void Base::update()
{
}

void Base::draw() const
{
}

void Base::cla(Base* en) {
}

void Base::Set_NearPos(Vec2 np) {
	NearPos = np;
}

