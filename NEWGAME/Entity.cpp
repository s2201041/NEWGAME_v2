#include "Entity.h"
#include "Game.h"

Entity::Entity(Array<Shot>* sh, Vec2 pos, int typ, Rect are) : Base(pos, typ, are)

{

	shot = sh;

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
		m_texture = Texture{ U"texture/entity/enemy.png"  };
		Nam = U"敵_A";

		break;

	case 2:
		m_texture = Texture{ U"texture/entity/enemys.png" };
		Nam = U"敵_B";

		break;

	}


}

void Entity::update()
{
	//タイプ別の動作処理の分岐
	switch (Typ) {
	case 1:

		Pos = Pos.lerp(GoPos, 0.1);
		if (Timer > 0.05) {
			*shot << Shot{ Pos ,{0,1},900,1,Are };
			//game->tes();
			//game->entity.emplace_back(new Player{ { 100 , 100 },1 ,Are });
			//shot << Shot{ Pos ,{0,1} ,900 ,1 ,Are};
			GoPos = { NearPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

	case 2:

		Pos = Pos.lerp(GoPos, 0.2);

		if (Timer > 0.5) {
			//shot << Shot{ Pos ,{0,1} ,1200 ,2 ,Are };
			GoPos = { NearPos.x,Random(20,280) };
			Timer = 0;
		}
		//タイマーの加算
		Timer += Scene::DeltaTime();

		break;

	}

	
	//すり抜け防止
	Pos.clamp(Are);

	//Hp0以下の敵の消去
	if (0 >= Hp)
		Del = !Del;

	//コライダーの更新
	Col = Circle{ Pos, size };

}

void Entity::draw() const
{

	switch (Typ) {
	case 1:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

	case 2:
		m_texture.scaled(2.0).drawAt(Pos);
		break;

	}

	//コライダー確認用
	Col.draw(ColorF{ 0.0, 0.5, 1.0, 0.4 });

	//HPゲージの描画
	//RectF{ 50 , 50, 300, 10 }.draw(Palette::Orange);;
	//RectF{ 50 , 50, Hp * 3, 10 }.draw(Palette::Red);;

	effect.update();
}

void Entity::sh_cla(int typ,int dma) {
	Hp -= dma;
}

void Entity::en_cla(int typ) {
	switch(typ){
	}
}
