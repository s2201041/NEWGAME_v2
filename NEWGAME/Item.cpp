#include "Item.h"

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

void Item::sh_cla(int typ, int dma) {
	Hp -= dma;
}

void Item::en_cla(int typ,Player* pl) {
	switch (Typ) {
	case 1:
		Del = true;
		pl->effect.add<Speed_Up>(&Vel,10);
		return;
	}
}


