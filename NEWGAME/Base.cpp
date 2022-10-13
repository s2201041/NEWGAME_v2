#include "Base.h"

Base::Base(Vec2 pos, Vec2 dir, int vel,int typ,Rect are)
{
	Pos = pos;	
	Typ = typ;
	Are = are;
	Del = false;

	//タイマーの初期化
	Timer = 0;

	//コライダーの初期化
	Col = Circle{ Pos, size };

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

