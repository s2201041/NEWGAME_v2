#pragma once

//インクルードガード
#ifndef ENTITY_H
#define ENTITY_H

#include "Base.h"
#include "Shot.h"

class Game;

class Entity: public Base {
	
public:

	//コンストラクタ
	Entity(Game* gm,Vec2 pos,int typ,Rect are);

	//１フレーム毎の処理
	void sub_update() override;

	//描画
	void sub_draw() const override;

	//残り時間
	int Time_Left;

	//諸突処理関数
	void cla(Shot* en);
	void cla(Base* en);
	
};
 
#endif
