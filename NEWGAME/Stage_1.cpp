#include "Stage_1.h"

Stage_1::Stage_1(const InitData& init)
	: Game{ init },
	Entity_List{
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 5 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,15}, 10 },
		{Entity{ this, { 300 , 50 },14 ,Are ,200,15}, 10 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,10}, 15 },
		{Entity{ this, { 300 , 50 },13 ,Are ,200,10}, 25 },
		{Entity{ this, { 300 , 50 },12 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },11 ,Are ,200,15}, 35 },
		{Entity{ this, { 300 , 50 },14 ,Are ,400,15}, 45 },
		{Entity{ this, { 300 , 50 },14 ,Are ,400,15}, 65 },
		{Entity{ this, { 300 , 50 },13 ,Are ,400,15}, 65 },
}
{
	player << Player{ this, { 300 , 400 } ,1 ,Are ,330};

	//経過時間の初期化
	Entity_Time = 10;

	Item_Time = 5;

	Time_Left = 90;

	norma_Kill = 6;
	
	// オーディオを再生
	audio.play();

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

	//アイテムの出現
	if (Time >= Item_Time) {
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,4) ,Are };
		Item_Time += 10;
	}
}

void Stage_1::sub_draw() const{
}
