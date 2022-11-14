﻿#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Base.h"

class Game;

class Item : public Base
{
public:
	//コンストラクタ
	Item(Game* gm, Vec2 pos, int typ, Rect are);

	//１フレーム毎の処理
	void sub_update() override;

	void has_update(int n);

	//描画
	void sub_draw() const override;

	void has_draw(int n) const;
	
	//諸突処理関数
	void cla(Player *pl);

	//使用時の動作
	void use(Player *pl);

	RectF Rec;

private:
	double t;

	Player* whose;
};

#endif ITEM_H
