#pragma once

//インクルードガード
#ifndef SHOT_H
#define SHOT_H

#include "common.h"

class Shot {

public:

	//コンストラクタ
	Shot( Vec2 pos, Vec2 dir, int vel,int typ);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const;

	//衝突処理関数
	void cla();

	//座標と向きの定義
	Vec2 Pos, Dir;

	//コライダー
	Circle Col;

	//消去判定
	bool Del;

	Vec2 GoPos;

private:

	Texture m_texture;

	//速度の定義
	int Vel;

	//球の種類の定義
	int Typ;

	//タイマー変数の定義
	double Time;
};

#endif
