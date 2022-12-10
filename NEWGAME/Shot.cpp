#include "Shot.h"

#include "Entity.h"
#include "Player.h"
#include "Game.h"

Shot::Shot(Game* gm, Base* ent, Vec2 pos, Vec2 dir, int vel,int typ ,Rect are):Base(gm, ent, pos, dir , vel,typ, are)
{
	entity = ent;

	NearPos = { 300,300 };

	//コライダーの初期化
	Col = Circle{ Pos, 5 };

	switch (Typ) {
	case 1:
		//直線
		Dam = 10;
		break;
	case 2:
		Dam = 10;
		break;
	case 3:
		Dam = 10;
		break;
	case 4:
		//追跡 自動消滅
		Dam = 10;
		break;
	case 5:
		//直線 速度二倍
		Dam = 15;
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

		Timer += Scene::DeltaTime();

		if (Timer > 2)
			Del = true;

		break;

	case 3:
		
		Pos += Dir * (Scene::DeltaTime()*100);

		Pos.y -= Scene::DeltaTime() * Vel;

		Dir.rotate(Scene::DeltaTime()*50);

		Timer += Scene::DeltaTime();


		break;

	case 4:
		if (Time > 2.0)
			Del = true;

		/*
		const Vec2 pPos = Pos.lerp(NearPos, 0.05);

		Pos.moveBy((pPos - Pos).setLength( Scene::DeltaTime() * Vel ));
		*/

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
	Col = Circle{ Pos, 5 };

}

void Shot::sub_draw() const
{

	switch (Typ) {

	case 1:
		//TextureAsset(U"hinotama").scaled(2.0).drawAt(Pos.x+Sin(Time*50)*10, Pos.y);
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

		TextureAsset(U"blue_hinotama").scaled(2.0).drawAt(Pos,ColorF{ 1.0, 1/Time });
		break;

	case 5:
		TextureAsset(U"kaminari").scaled(2.0).drawAt(Pos);
		break;
	}
}


void Shot::cla(Base* en) {
	AudioAsset(U"cla_sound").playOneShot();

	if(en!=entity) {
		Del = true;
		en->Hp -= (Dam * en->p_Dam) / 100;
	}
}

void Shot::cla(Player* en) {
	AudioAsset(U"cla_sound").playOneShot();

	game->effect.add<HitEffect>( Random(0.0, 360.0));

	if (en != entity) {
		Del = true;
		en->Hp -= Dam;
	}
}
