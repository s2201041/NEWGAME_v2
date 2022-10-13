#pragma once

//インクルードガード
#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include "Shot.h"

class Player {

public:

	//コンストラクタ
	Player(Vec2 pos,int typ ,Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const;

	//諸突処理関数
	void sh_cla();
	void en_cla(int typ);

	//ショットの定義
	Array<Shot> shot;

	//コライダー
	Circle Col;

	//消去判定
	bool Del;

	//座標の定義
	Vec2 Pos;

	//直近の敵座標
	Vec2 EnPos;

	Texture m_texture;

	//向きの定義
	Vec2 Dir;

	//速度の定義
	int Vel;

	//プレイヤーの種類の定義
	int Typ;

	//HPの定義
	int Hp;

	//動作範囲
	Rect Are;

	//Keyconfigの定義
	InputGroup inputLeft;
	InputGroup inputRight;
	InputGroup inputUp;
	InputGroup inputDown;
	InputGroup inputShot;

};

#endif
