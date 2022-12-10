#include "stdafx.h"
#include "Stage_4.h"
Stage_4::Stage_4(const InitData& init)
	: Game{init},
	Entity_List{
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 1 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,15}, 10 },
		{Entity{ this, { 300 , 50 },14 ,Are ,200,15}, 10 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 15 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,10}, 25 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },11 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,400,15}, 45 },
		{Entity{ this, { 300 , 50 },14 ,Are ,400,15}, 65 },
		{Entity{ this, { 300 , 50 },12 ,Are ,500,15}, 70 },
		{Entity{ this, { 300 , 50 },11 ,Are ,500,15}, 80 },
		{Entity{ this, { 300 , 50 },13 ,Are ,500,15}, 90 },
		{Entity{ this, { 300 , 50 },14 ,Are ,600,15}, 100 },
		{Entity{ this, { 300 , 50 },13 ,Are ,600,15}, 110 },
		{Entity{ this, { 300 , 50 },12 ,Are ,500,15}, 140 },
		{Entity{ this, { 300 , 50 },11 ,Are ,400,15}, 140 }
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,250};

	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 160;

	norma_Kill = 9;
}

void Stage_4::sub_update() {
if (0 < Time) 
		standby = false;

	if (Time_Left <= 0) game_over = true;

	if (Entity_List.size() != 0&&Entity_List[0].num <= Time) {
			entity << Entity_List[0].entity;
			Entity_List.erase(Entity_List.begin());
	}

	//アイテムの出現
	if (Time >= Item_Time) {
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,4) ,Are };
		Item_Time += 5;
	}
}

void Stage_4::sub_draw() const {

}
