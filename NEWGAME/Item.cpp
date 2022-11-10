﻿#include "Item.h"

Item::Item(Vec2 pos, int typ, Rect are):Base(pos,typ,are)
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

void Item::update() {

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

	Col = Circle{ Pos,size };

	t += Scene::DeltaTime();
}

void Item::update(int n) {

	Pos = {630 + n % 3 * 50,350 + n / 3 * 50};
	
	Rec = RectF{ Arg::center(Pos), 64, 64};

	if (Rec.leftClicked()) {
		use(whose);
		Del = true;
	}
}

void Item::draw() const
{
	switch (Typ) {
	case 1:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;
	case 2:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;
	}
}

void Item::draw(int n) const {
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		Rec.draw();
}

void Item::cla(Player* pl) {
	Print << U"Cla"+Format(this);
	Del = true;
}

void Item::use(Player* pl) {
	Print << pl;
	switch (Typ) {
	case 1:
		Del = true;
		//player->effect.add<Speed_Up>(&Vel,10);
		return;
	case 2:
		Del = true;
		//game->effect.add<Speed_Up>(&Vel, 10);
		//player->Hp += 10;
		return;
	}
}



