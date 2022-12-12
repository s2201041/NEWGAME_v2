#include "Stage_1.h"

Stage_1::Stage_1(const InitData& init)
	: Game{ init },
	Entity_List{
		{Entity{ this, { 300 , 50 },11 ,Are ,100,15}, 5 },
		{Entity{ this, { 300 , 50 },13 ,Are ,100,15}, 15 },
		{Entity{ this, { 300 , 50 },12 ,Are ,100,15}, 25 },
		{Entity{ this, { 300 , 50 },13 ,Are ,100,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,130,15}, 45 },
		{Entity{ this, { 300 , 50 },13 ,Are ,100,20}, 50 },
		{Entity{ this, { 300 , 50 },11 ,Are ,160,20}, 55 },
		{Entity{ this, { 300 , 50 },12 ,Are ,220,20}, 60 },
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,330};

	if (getData().player_data == 1) {
		player << Player{ this, { 300 , 500 } ,2 ,Are ,330 };
	}

	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 70;

	norma_Kill = 5;

	kaihuku = true;
}

void Stage_1::sub_update() {

	if (0 < Time) standby = false;

	if (Time_Left <= 0) game_over = true;

	if (Entity_List.size() != 0&&Entity_List[0].num <= Time) {
			entity << Entity_List[0].entity;
			Entity_List.erase(Entity_List.begin());
	}


	/*/敵の出現
	if (Time >= Entity_Time) {
		entity << Entity{ this, { 300 , 50 },Random(11,14) ,Are };
		Entity_Time += 10;
	}
	*/

	if (Time > Time_Left / 2 && kaihuku == true) {
		item << Item{ this, { Random(0,600) , Random(150,600)},4 ,Are };
		kaihuku = false;
	}
		

	//アイテムの出現
	if (Time >= Item_Time) {
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,4) ,Are };
		Item_Time += 10;
	}
}

void Stage_1::sub_draw() const{
}
