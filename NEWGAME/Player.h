#pragma once

//インクルードガード
#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"
#include "Shot.h"

class Player : public Base{

public:

	//コンストラクタ
	Player(Array<Shot>* sh, Vec2 pos,int typ ,Rect are);


	//１フレーム毎の処理
	void update();

	//描画
	void draw() const;

	//諸突処理関数
	//void sh_cla(int typ);
	void en_cla(int typ);

	//ショットの定義
	Array<Shot>* shot;
	Array<Shot>* en_shot;

	//Keyconfigの定義
	InputGroup inputLeft;
	InputGroup inputRight;
	InputGroup inputUp;
	InputGroup inputDown;
	InputGroup inputShot;

};

#endif
