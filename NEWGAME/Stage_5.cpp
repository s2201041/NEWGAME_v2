#include "stdafx.h"
#include "Stage_5.h"
Stage_5::Stage_5(const InitData& init)
	: Game{init},
	Entity_List{
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 }
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,200};
	
	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 120;

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
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,4) ,Are };
		Item_Time += 10;
	}
}

void Stage_5::sub_draw() const {

}
