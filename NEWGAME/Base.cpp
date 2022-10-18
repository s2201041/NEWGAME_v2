#include "Base.h"

//Base::Base(Vec2 pos,int typ,Rect are)
//	:Pos(pos),Typ(typ),Are(are),Del(false)
//{
//}

Base::Base(Vec2 pos,int typ,Rect are)
	:Pos(pos),Typ(typ),Are(are),Del(false)
{
}

Base::Base(Vec2 pos, Vec2 dir, int vel, int typ, Rect are)
	:Pos(pos),Typ(typ),Are(are),Del(false),Dir(dir),Vel(vel)
{
}

void Base::update()
{
}

void Base::draw() const
{
}

void Base::sh_cla() {
}

void Base::pl_cla() {
}

