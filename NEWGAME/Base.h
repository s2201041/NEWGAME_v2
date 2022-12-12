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

	Base();

	//ショット用コンストラクタのoverroad
	Base(Game* gm, Base* ent, Vec2 pos, Vec2 dir, int vel, int typ, Rect are);


	Base(Game* gm, Vec2 pos, int typ, Rect are);

	//
	Base(Game* gm, Vec2 pos, int typ, Rect are, int vel);

	//１フレーム毎の処理
	void update();

	virtual void sub_update() = 0;
	
	//描画
	void draw() const ;

	virtual void sub_draw() const = 0;

	//諸突処理関数
	void cla(Base* en);
	
	//二点の座標の角度計算
	Vec2 dir(Vec2 posA, Vec2 posB);

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

	//HPの最大値の定義
	int Max_Hp;

	//名前の定義
	String Nam;

	//速度の定義
	int Vel;

	//無敵状態の定義
	int p_Dam;

	//インスタンス化からの時間
	double Time;

	int score;

protected:

	//座標と向きの定義
	Vec2 Dir, GoPos;

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
