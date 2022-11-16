#include "Shot.h"

#include "Entity.h"
#include "Player.h"
#include "Game.h"

Shot::Shot(Game* gm, Base* ent, Vec2 pos, Vec2 dir, int vel,int typ ,Rect are):Base(gm, ent, pos, dir , vel,typ, are)
{
	entity = ent;



	NearPos = { 300,300 };

	//コライダーの初期化
	Col = Circle{ Pos, 8 };

	switch (Typ) {
	case 1:
		Dam = 4;
		break;

	case 2:
		Dam = 10;
		break;

	case 3:
		Dam = 10;
		break;

	case 4:
		Dam = 100;
		break;

	case 5:
		Dam = 100;
		break;

	}

}

void Shot::sub_update()
{
	switch (Typ) {
	case 1:

		Pos += Dir * (Scene::DeltaTime() * Vel );

		break;

	case 2:

		Pos = Pos.lerp(NearPos, 0.05);

		Pos += Dir * (Scene::DeltaTime() * Vel);

		break;

	case 3:

		Pos += Dir * (Scene::DeltaTime() * Vel);

		Dir.rotate(Scene::DeltaTime()*5);

		Timer += Scene::DeltaTime();

		break;

	case 4:
		Pos = Pos.lerp(NearPos, 0.05);

		break;

	case 5:

		Pos += Dir * (Scene::DeltaTime() * Vel * 2 );

		break;
	}

	//範囲外のショットの消去
	if (false == Col.intersects(Are))
		Del = true;

	//コライダーの更新
	Col = Circle{ Pos, 8 };

}

void Shot::sub_draw() const
{

	switch (Typ) {

	case 1:
		TextureAsset(U"hinotama").scaled(2.0).drawAt(Pos);
		break;

	case 2:
		TextureAsset(U"blue_hinotama").scaled(2.0).drawAt(Pos);
		//Line{ Pos, NearPos }.draw(4, Palette::Yellow);
		break;

	case 3:
		TextureAsset(U"blue_hinotama").scaled(2.0).drawAt(Pos);
		break;

	case 4:

		TextureAsset(U"blue_hinotama").scaled(2.0).drawAt(Pos);
		break;

	case 5:
		TextureAsset(U"kaminari").scaled(2.0).drawAt(Pos);
		break;
	}
}


void Shot::cla(Base* en) {
	if(en!=entity) {
		Del = true;
		en->Hp -= Dam;
	}
}
