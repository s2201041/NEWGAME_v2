#include "Item.h"
#include "Game.h"

Item::Item(Game* gm, Vec2 pos, int typ, Rect are):Base(gm,pos,typ,are)
{
	t = 0;

	switch (Typ) {
	case 1:
		Nam = U"加速";
		break;
	case 2:
		Nam = U"回復";
		break;
	}
}

Item::Item(Player* ent, int typ) {
	Typ = typ;
	whose = ent;
};

void Item::sub_update() {

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
	Pos.clamp(Are);

	Col = Circle{ Pos,8 };

	t += Scene::DeltaTime();
}

void Item::has_update(int n) {

	Pos = {650 + n % 3 * 50,350 + n / 3 * 50};
	
	Rec = RectF{ Arg::center(Pos), 64, 64};

	if (Rec.leftClicked()||(KeyZ.down()&&n == 0)){
		use(whose);
		Del = true;
	}
}

void Item::sub_draw() const
{
	switch (Typ) {
	case 1:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;
	case 2:
		TextureAsset(U"item_2").scaled(2.0).drawAt(Pos);
		break;
	}
}

void Item::has_draw(int n) const {
	
	switch (Typ) {
	case 1:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;
	case 2:
		TextureAsset(U"item_2").scaled(2.0).drawAt(Pos);
		break;
	}
}

void Item::cla(Player* pl) {
	Del = true;
	whose = pl;
}

void Item::use(Player* pl) {
	switch (Typ) {
	case 1:
		Del = true;
		whose->effect.add<Speed_Up>(&whose->Vel,10);
		return;
	case 2:
		Del = true;
		//game->effect.add<Speed_Up>(&Vel, 10);
		whose->Hp += 10;
		return;
	}
}



