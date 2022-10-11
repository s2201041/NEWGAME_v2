#pragma once

//インクルードガード
#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"
#include "Shot.h"

class Entity {

public:

	//コンストラクタ
	Entity(Vec2 pos, int typ);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const ;

	//諸突処理関数
	void cla();

	//ショットの定義
	Array<Shot> shot;

	//コライダー
	Circle Col;

	//仮死状態
	bool Det;

	//消去判定
	bool Del;

	//座標の定義
	Vec2 Pos;

	//直近のプレイヤー座標
	Vec2 PlPos;

	//敵の種類の定義
	int Typ;

private:

	Texture m_texture;

	//座標と向きの定義
	Vec2 Dir, GoPos;

	//速度の定義
	int Vel;

	//敵のHPの定義
	int Hp;

	//コライダーサイズの定義
	double size;

	//タイマー変数の定義
	double Timer;
};

#endif
