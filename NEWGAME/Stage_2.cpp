#include "Stage_2.h"

Stage_2::Stage_2(const InitData& init)
	: Game{init},
	Entity_List{
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 5 },
		{Entity{ this, { 300 , 50 },13 ,Are ,150,15}, 15 },
		{Entity{ this, { 300 , 50 },12 ,Are ,150,15}, 25 },
		{Entity{ this, { 300 , 50 },13 ,Are ,150,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,170,15}, 45 },
		{Entity{ this, { 300 , 50 },11 ,Are ,150,10}, 50 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,10}, 60 },
		{Entity{ this, { 300 , 50 },14 ,Are ,200,10}, 70 },
		{Entity{ this, { 300 , 50 },11 ,Are ,150,10}, 80 },
		{Entity{ this, { 300 , 50 },12 ,Are ,170,10}, 50 }
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,300};

	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 90;

	norma_Kill = 7;

}

void Stage_2::sub_update() {

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

void Stage_2::sub_draw() const {

}
