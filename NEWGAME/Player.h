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
	Player(Game* game, Vec2 pos, int typ, Rect are, int vel);

	//１フレーム毎の処理
	void sub_update() override;

	//描画
	void sub_draw() const override;

	//0以下の切捨て関数
	int zero(int i);

	//アイテム
	Array<Item> item;

	double shot_cool;

	//諸突処理関数
	void cla(Shot* it);
	void cla(Base* en);

	//Keyconfigの定義
	InputGroup inputLeft;
	InputGroup inputRight;
	InputGroup inputUp;
	InputGroup inputDown;
	InputGroup inputShot;
	InputGroup inputItem;

	size_t playerIndex = 0;

	XInputVibration vibration;

	Effect effect;

	int base_vel;

	//集中線の描画関連
	Ellipse target{ 300, 300, 180, 120 };

	Rect outer = Are;

	double minThickness = 3.0, maxThickness = 10.0;
	double lineCount = 150;
	double offsetRange = 60.0;

	SaturatedLinework<Ellipse> linework{ target, outer };


private:
	Vec2 Vel2;
};

#endif
