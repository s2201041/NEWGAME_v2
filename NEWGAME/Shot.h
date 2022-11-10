#pragma once

//インクルードガード
#ifndef SHOT_H
#define SHOT_H

#include "Base.h"

class Entity;
class Player;

class Shot : public Base {

public:

	//コンストラクタ
	Shot( Base* ent,Vec2 pos, Vec2 dir, int vel,int typ ,Rect are);

	//１フレーム毎の処理
	void update();

	//描画
	void draw() const;

	//衝突関数
	void cla(Base* en);

	//コライダー
	Circle Col;

	//目的座標
	Vec2 GoPos;

	//ダメージの定義
	int Dam;

private:

	Texture m_texture;
	//タイマー変数の定義

	Base* entity;

};

#endif
