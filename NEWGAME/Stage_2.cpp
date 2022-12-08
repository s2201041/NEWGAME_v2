﻿#include "Stage_2.h"

Stage_2::Stage_2(const InitData& init)
	: Game{init}
{
	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 120;

	norma_Kill = 4;

}

void Stage_2::sub_update() {

	if (0 < Time) 
		standby = false;

	if (Time_Left <= 0) game_over = true;

	//敵の出現
	if (Time >= Entity_Time) {
		//entity << Entity{ this, { 300 , 50 },Random(11,14) ,Are };
		Entity_Time += 10;
	}

	//アイテムの出現
	if (Time >= Item_Time) {
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,5) ,Are };
		Item_Time += 5;
	}


}

void Stage_2::sub_draw() const {

}
