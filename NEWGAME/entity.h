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
	void update();

	//描画
	void draw() const ;

	//諸突処理関数
	void cla(Shot* en);
	void cla(Base* en);
	
	Game* game;

};

#endif
