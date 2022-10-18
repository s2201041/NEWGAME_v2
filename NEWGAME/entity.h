#pragma once

//インクルードガード
#ifndef ENTITY_H
#define ENTITY_H

#include "Base.h"
#include "Shot.h"

class Entity {
	
public:

	//コンストラクタ
	Entity(Vec2 pos,int typ,Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const ;

	//諸突処理関数
	void sh_cla();
	void pl_cla();

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

	//直近座標
	Vec2 PlPos;

	//種類の定義
	int Typ;

	//HPの定義
	int Hp;

	//敵の名前の定義
	String Nam;
	
private:

	Texture m_texture;

	//座標と向きの定義
	Vec2 Dir, GoPos;

	//速度の定義
	int Vel;

	//コライダーサイズの定義
	double size;

	//タイマー変数の定義
	double Timer;

	//動作範囲
	Rect Are;

	Effect effect;

};

#endif
