#include "Item.h"

Item::Item(Vec2 pos, int typ, Rect are):Base(pos,typ,are)
{
	switch (Typ) {
	case 1:
		Nam = U"加速";
		break;
	}
}

void Item::update() {

	switch (Typ) {
	case 1:
		break;
	}
	Pos.clamp(Are);

	Col = Circle{ Pos,size };
}

void Item::draw() const
{
	switch (Typ) {
	case 1:
		TextureAsset(U"item_1").scaled(2.0).drawAt(Pos);
		break;
	}
}

void Item::sh_cla(int typ, int dma) {
	Hp -= dma;
}

void Item::en_cla(int typ) {
	switch (Typ) {
	case 1:
		Del = true;
		return;
	}
}


