#include "stdafx.h"
#include "Stage_3.h"
Stage_3::Stage_3(const InitData& init)
	: Game{init},
	Entity_List{
		{Entity{ this, { 300 , 50 },12 ,Are ,200,15}, 1 },
		{Entity{ this, { 300 , 50 },15 ,Are ,250,15}, 5 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,15}, 15 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,15}, 25 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,200,15}, 45 },
		{Entity{ this, { 300 , 50 },11 ,Are ,400,20}, 50 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 60 },
		{Entity{ this, { 300 , 50 },15 ,Are ,220,10}, 70 },
		{Entity{ this, { 300 , 50 },14 ,Are ,200,10}, 80 },
		{Entity{ this, { 300 , 50 },14 ,Are ,280,10}, 90 },
		{Entity{ this, { 300 , 50 },14 ,Are ,240,10}, 110 },
		{Entity{ this, { 300 , 50 },12 ,Are ,240,10}, 110 },
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,330};

	if(getData().player_data == 1)
		player << Player{ this, { 300 , 500 } ,2 ,Are ,330};

	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 10;

	Time_Left = 120;

	norma_Kill = 10;
}

void Stage_3::sub_update() {

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
		if (item_time % 30 == 0)
			item << Item{this, { Random(0,600) , Random(150,600)},4 ,Are };
		else
			item << Item{this, { Random(0,600) , Random(150,600)},Random(1,3) ,Are };
		Item_Time += 10;
	}

}

void Stage_3::sub_draw() const {

}
