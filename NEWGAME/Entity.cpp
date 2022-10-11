#include "Entity.h"

Entity::Entity(Vec2 pos, int typ)
{
	Pos = pos;
	Typ = typ;
	Del = false;

	//タイマーの初期化
	Timer = 0;

	//コライダーの初期化
	Col = Circle{ Pos, size };

	//デバッグ用
	//Print << Typ;

	Dir = { 0,1 };
	Vel = 1100;
	Hp = 100;
	size = 45;
	GoPos = { Random(1,100),Random(1,100) };

	//タイプ別の初期値の初期化
	switch (Typ) {
	case 1:
		m_texture = Texture{ U"example/windmill.png" };

		break;

		////////////////////////////////////////////////////
		///////////////以下のコードを変更///////////////////

	case 2:

		Dir = { 0,1 };

		Vel = 1100;

		Hp = 100;

		size = 45;

		break;

		///////////////以上のコードを変更///////////////////
		////////////////////////////////////////////////////

	}


}

void Entity::update()
{

	//タイプ別の動作処理の分岐
	switch (Typ) {
	case 1:

		Pos = Pos.lerp(GoPos, 0.1);

		if (Timer > 0.5) {
			shot << Shot{ Pos ,{0,1} ,600 ,2 };
			GoPos = { PlPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;


		////////////////////////////////////////////////////
		///////////////以下のコードを変更///////////////////

	case 2:
		
		Pos.y += -1;

		Dir.rotate(Scene::DeltaTime());

		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

		///////////////以上のコードを変更///////////////////
		////////////////////////////////////////////////////
	}

	
	Pos.clamp(Scene::Rect());

	//すり抜け防止
	//Pos.clamp(Rect{ 20, 20, 450, 560 });

	//ショットの処理
	for (auto& sh : shot) {
		sh.GoPos = PlPos;
		sh.update();
	}

	//ショットの消滅処理
	shot.remove_if([](const Shot& sh) { return sh.Del == true;  });

	//Hp0以下の敵の消去
	if (0 >= Hp)
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, size };

}

void Entity::draw() const
{



	switch (Typ) {
	case 1:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

		////////////////////////////////////////////////////
		///////////////以下のコードを変更///////////////////

	case 2:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

		///////////////以上のコードを変更///////////////////
		////////////////////////////////////////////////////

	}



	//ショットの描画
	for (auto& sh : shot) 
		sh.draw();

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.4 });

	//HPゲージの描画
	RectF{ Pos.x - 50 , Pos.y - 50, 100, 10 }.draw(Palette::Orange);;
	RectF{ Pos.x - 50 , Pos.y - 50, Hp, 10 }.draw(Palette::Red);;
}

void Entity::cla() {
	Hp -= 10;
}

