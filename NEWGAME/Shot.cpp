#include "Shot.h"

Shot::Shot( Vec2 pos, Vec2 dir, int vel,int typ)
	:m_texture{ U"texture/shot/Shot.png" }
{
	Pos = pos;
	Dir = dir;
	Vel = vel;
	Typ = typ;

	Del = false;

	//ストップウォッチの初期化
	Time = 0;

	//コライダーの初期化
	Col = Circle{ Pos, 8 };
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

		Pos.x = Pos.x +  cos(Time*2)* Time;

		Pos.y = Pos.y + sin(Time * 2)* Time ;

		break;
	}

	//範囲外のショットの消去
	//if (false == Col.intersects(Scene::Rect()))
	//	Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 8 };
}

void Shot::draw() const
{
	switch (Typ) {

	case 1:
		const Circle Col{ Pos, 8 };
		//Col.draw();
		m_texture.scaled(Time).drawAt(Pos);
		break;

	case 2:
		m_texture.scaled(4.0).drawAt(Pos);
		break;

	case 3:
		m_texture.scaled(1.0).drawAt(Pos);
		break;

	}

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.8 });
}

void Shot::cla() {
	Del = true;
}
