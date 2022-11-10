#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Base.h"

#include "Player.h"

class Item : public Base
{
public:
	//コンストラクタ
	Item(Vec2 pos, int typ, Rect are);

	//１フレーム毎の処理
	void update();

	void update(int n);

	//描画
	void draw() const;

	void draw(int n) const;
	
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
