#pragma once

//インクルードガード
#ifndef SHOT_H
#define SHOT_H

#include "Base.h"

//#include "Effect.cpp"

class Entity;

class Player;

class Shot : public Base {

public:

	//コンストラクタ
	Shot( Entity* ent,Vec2 pos, Vec2 dir, int vel,int typ ,Rect are);

	Shot( Player* pla,Vec2 pos, Vec2 dir, int vel,int typ ,Rect are);

	Shot( Vec2 pos, Vec2 dir, int vel,int typ ,Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const;

	//衝突処理関数
	//void cla(Player* pl);

	void cla(Base* en);

	//コライダー
	Circle Col;

	//目的座標
	Vec2 GoPos;

	//呼び出し元の定義
	int Par;

	//ダメージの定義
	int Dam;



private:

	Texture m_texture;
	//タイマー変数の定義

	//エフェクト
	//Effect effect;

	Base* entity;

};

#endif
