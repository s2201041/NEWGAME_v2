#include "Shot.h"

#include "Entity.h"
#include "Player.h"

Shot::Shot( Vec2 pos, Vec2 dir, int vel,int typ ,Rect are):Base(pos, dir , vel,typ, are)
{
	NearPos = { 300,300 };

	//コライダーの初期化
	Col = Circle{ Pos, 8 };

	switch (Typ) {
	case 1:
		Dam = 10;
		m_texture = Texture{ U"texture/shot/shot_1.png" };
		break;

	case 2:
		Dam = 10;
		m_texture = Texture{ U"texture/shot/shot_2.png" };
		break;

	case 3:
		Dam = 1145141919810;
		m_texture = Texture{ U"texture/shot/shot_2.png" };
	}

}

Shot::Shot(Entity* ent, Vec2 pos, Vec2 dir, int vel, int typ, Rect are) :Shot(pos, dir, vel, typ, are) {
	entity = ent;
};

Shot::Shot(Player* pla, Vec2 pos, Vec2 dir, int vel, int typ, Rect are):Shot(pos,dir,vel,typ,are){
	entity = pla;
};

void Shot::update()
{
	switch (Typ) {
	case 1:

		Pos += Dir * (Scene::DeltaTime() * Vel );

		Col = Circle{ Pos, 8 };

		break;

	case 2:

		Pos = Pos.lerp(NearPos, 0.05);

		Pos += Dir * (Scene::DeltaTime() * Vel);

		Col = Circle{ Pos, 8 };

		break;

	case 3:

		Print << NearPos;

		Print << U"Sho" + Format( &NearPos);

		Pos = Pos.lerp(NearPos, 0.05);

		Pos += Dir * (Scene::DeltaTime() * Vel);

		Col = Circle{ Pos, 8 };

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
		//Line{ Pos, NearPos }.draw(4, Palette::Yellow);
		break;

	case 3:
		m_texture.scaled(2.0).drawAt(Pos);
		break;
	}
	//effect.update();
}

//void Shot::cla(Player* pl) {
//	if(pl!=entity) {
//		Del = true;
//		pl->Hp -= 10;
//	}
//
//}

void Shot::cla(Base* en) {
	AudioAsset(U"cla_sound").playOneShot();

	if(en!=entity) {
		Del = true;
		en->Hp -= 10;
	}
}


