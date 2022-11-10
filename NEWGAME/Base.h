#pragma once

//インクルードガード
#ifndef BASE_H
#define BASE_H

#include "common.h"

class Player;
class Entity;
class Item;
class Shot;
class Game;


class Base {

public:

	//コンストラクタ
	Base(Vec2 pos,int typ,Rect are);

	//ショット用コンストラクタのoverroad
	Base(Vec2 pos, Vec2 dir, int vel, int typ, Rect are);

	Base(Game* gam, Vec2 pos,int typ,Rect are);

	//１フレーム毎の処理
	virtual void update();

	//描画
	virtual void draw() const ;

	//諸突処理関数
	void cla(Base* en);

	//コライダー
	Circle Col;

	//仮死状態
	bool Det;

	//消去判定
	bool Del;

	//座標の定義
	Vec2 Pos;

	//直近座標
	Vec2 NearPos;

	//種類の定義
	int Typ;

	//HPの定義
	int Hp;

	//名前の定義
	String Nam;

protected:

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

	//ゲームシーンのポインタ
	Game* game;
};

#endif
