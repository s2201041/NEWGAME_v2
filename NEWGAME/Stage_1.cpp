#include "Stage_1.h"

Stage_1::Stage_1(const InitData& init) 
	: Game{init}
{
	//経過時間の初期化
	Time = 0;

	Time_2 = 0;

	Time_Left = 120;

	norma_Kill = 4;
	
	winner = Texture{ U"texture/winner.png" };

	// オーディオを再生
	audio.play();

}

void Stage_1::sub_update() {


	if (0 < Time) {
		standby = false;
	}

	//ゲームオーバー時の処理
	if (game_over) {
		AudioAsset(U"clear_sound").playOneShot();
		Game_Over();
		changeScene(State::Result);
	}

	//経過時間
	Time += Scene::DeltaTime();
	Time_2 += Scene::DeltaTime();

	if (Time_Left <= 0) game_over = true;

	//敵の出現
	if (Time >= 10) {
		entity << Entity{ this, { 300 , 50 },Random(11,14) ,Are };
		Time = 0;
	}

	//アイテムの出現
	if (Time_2 >= 5) {
		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,5) ,Are };
		Time_2 = 0;
	}



}

void Stage_1::sub_draw() const{
}
