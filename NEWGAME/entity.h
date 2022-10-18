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
	Entity(Game* gam,Vec2 pos,int typ,Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const ;

	//諸突処理関数
	void sh_cla();
	void pl_cla();

	//ショットの定義
	Array<Shot> shot;

	Game* game;
};

#endif
