#include "stdafx.h"
#include "Stage_5.h"
Stage_5::Stage_5(const InitData& init)
	: Game{init},
	Entity_List{
		{Entity{ this, { 300 , 50 },13 ,Are ,1000,180}, 1 },
		{Entity{ this, { 300 , 50 },11 ,Are ,150,15}, 10 },
		{Entity{ this, { 300 , 50 },14 ,Are ,150,15}, 10 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 15 },
		{Entity{ this, { 300 , 50 },11 ,Are ,200,10}, 25 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },11 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,400,15}, 45 },
		{Entity{ this, { 300 , 50 },14 ,Are ,1000,115}, 65 },
		{Entity{ this, { 300 , 50 },15 ,Are ,500,15}, 70 },
		{Entity{ this, { 300 , 50 },11 ,Are ,500,15}, 80 },
		{Entity{ this, { 300 , 50 },13 ,Are ,500,15}, 90 },
		{Entity{ this, { 300 , 50 },14 ,Are ,600,15}, 100 },
		{Entity{ this, { 300 , 50 },13 ,Are ,600,15}, 110 },
		{Entity{ this, { 300 , 50 },12 ,Are ,500,15}, 140 },
		{Entity{ this, { 300 , 50 },15 ,Are ,100,15}, 150 },
		{Entity{ this, { 300 , 50 },12 ,Are ,500,15}, 170 },
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,210};
	
	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 10;

	Time_Left = 180;

	norma_Kill = 10;
}

void Stage_5::sub_update() {
if (0 < Time) 
		standby = false;

	if (Time_Left <= 0) game_over = true;

	if (Entity_List.size() != 0&&Entity_List[0].num <= Time) {
			entity << Entity_List[0].entity;
			Entity_List.erase(Entity_List.begin());
	}

	//アイテムの出現
	if (Time >= Item_Time) {
		const int item_time = Item_Time;
		if (item_time % 20 == 0)
			item << Item{this, { Random(0,600) , Random(150,600)},4 ,Are };
		else
			item << Item{this, { Random(0,600) , Random(150,600)},Random(1,3) ,Are };
		Item_Time += 10;
	}
}

void Stage_5::sub_draw() const {

}
