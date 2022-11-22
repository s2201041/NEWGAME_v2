#pragma once

//インクルードガード
#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"
#include "Shot.h"
#include "Effect.cpp"

class Game;

class Player : public Base{

public:

	//コンストラクタ
	Player(Game* game, Vec2 pos,int typ ,Rect are);


	//１フレーム毎の処理
	void sub_update() override;

	//描画
	void sub_draw() const override;

	//0以下の切捨て関数
	int zero(int i);

	//アイテム
	Array<Item> item;

	//諸突処理関数
	void cla(Item* it);
	void cla(Base* en);

	//Keyconfigの定義
	InputGroup inputLeft;
	InputGroup inputRight;
	InputGroup inputUp;
	InputGroup inputDown;
	InputGroup inputShot;
	InputGroup inputItem;

	Effect effect;

private:
	Vec2 Vel2;
};

#endif
