#include "Shot.h"

Shot::Shot( Vec2 pos, Vec2 dir, int vel,int typ,Rect are)
{
	Pos = pos;
	Dir = dir;
	Vel = vel;
	Typ = typ;
	Are = are;

	Del = false;

	//ストップウォッチの初期化
	Time = 0;

	//コライダーの初期化
	Col = Circle{ Pos, 8 };

	switch (Typ) {
	case 1:

		m_texture = Texture{ U"texture/shot/shot_1.png" };
		break;

	case 2:

		m_texture = Texture{ U"texture/shot/shot_2.png" };
		break;

	}
}

void Shot::update()
{
	switch (Typ) {
	case 1:

		const Circle Col{ Pos, 8 };

		Pos += Dir * (Scene::DeltaTime() * Vel );

		break;

	case 2:

		Pos = Pos.lerp(GoPos, 0.05);

		Pos += Dir * (Scene::DeltaTime() * Vel);

		break;

	case 3:

		Time += Scene::DeltaTime();

		Pos.x = Pos.x + cos(Time * 2)* Time;

		Pos.y = Pos.y + sin(Time * 2)* Time;

		break;
	}

	//範囲外のショットの消去
	if (false == Col.intersects(Are))
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 8 };
}

void Shot::draw() const
{

	switch (Typ) {

	case 1:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

	case 2:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

	case 3:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

	}

}

void Shot::cla() {
	Del = true;
}
