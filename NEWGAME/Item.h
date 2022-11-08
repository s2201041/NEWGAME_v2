#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Base.h"

#include "Player.h"

class Item :  public Base
{
public:
	//コンストラクタ
	Item(Vec2 pos, int typ, Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const ;

	//諸突処理関数
	void cla(Player *pl);


private:
	double t;
};

#endif ITEM_H
