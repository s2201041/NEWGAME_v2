#include "Item.h"
#include "Game.h"

Item::Item(Game* gm, Vec2 pos, int typ, Rect are):Base(gm,pos,typ,are)
{
	t = 0;

	switch (Typ) {
	case 1:
		Nam = U"魔材";
		break;
	case 2:
		Nam = U"回復";
		break;
	case 3:
		Nam = U"過去問";
		break;
	case 4:
		Nam = U"レポート";
		break;
	case 5:
		Nam = U"ダメージ半減";
		break;
	case 6:
		Nam = U"敵ダメージ";
		break;
	}
}

Item::Item(Player* ent, int typ):Item(game,Pos,Typ,Are) {
	Typ = typ;
	whose = ent;
};

void Item::sub_update() {

	/*
	switch (Typ) {
	case 1:
		if (t > 5)
			Del = true;
		break;
	case 2:
		if (t > 5)
			Del = true;
		break;
	}
	*/

	if (t > 5)
		Del = true;

	Pos.clamp(Are);

	Col = Circle{ Pos,8 };

	t += Scene::DeltaTime();
}

void Item::has_update(int n) {

	Pos = {650 + n % 3 * 50,300 + n / 3 * 65};
	
	Rec = RectF{ Arg::center(Pos), 64, 64};

	if (Rec.leftClicked()){
		//use(whose);
	}
}

void Item::sub_draw() const
{
	switch (Typ) {
	case 1:
		TextureAsset(U"mazai").scaled(2.0).drawAt(Pos);
		break;
	case 2:
		TextureAsset(U"item_2").scaled(2.0).drawAt(Pos);
		break;
	case 3:
		TextureAsset(U"kakomon").scaled(2.0).drawAt(Pos);
		break;
	case 4:
		TextureAsset(U"report").scaled(2.0).drawAt(Pos);
		break;
	case 5:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;

	}
}

void Item::cla(Player* pl) {
	Del = true;
	whose = pl;

	switch (Typ) {
	case 4:
		use(pl);
		return;
	}
	
	if(pl->item.size()<6)
		pl->item << Item{pl,Typ};
}

void Item::use(Player* pl) {
	//whose->effect.add<Effect_Name>(1,Nam);
	switch (Typ) {
	case 1:
		Del = true;
		whose->effect.add<Mazai>(&whose->Vel,10);
		return;
	case 2:
		Del = true;
		whose->Hp = 100;
		return;
	case 3:
		Del = true;
		whose->effect.add<Speed_Up>(&whose->Vel,5);
		return;
	case 4:
		Del = true;
		whose->effect.add<Speed_Down>(&whose->Vel,5);
		return;
	case 5:
		Del = true;
		whose->effect.add<Damage_Down>(&whose->p_Dam,5);
		return;
	}
}



