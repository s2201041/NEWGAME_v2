#include "Stage_1.h"

Stage_1::Stage_1(const InitData& init) 
	: Game{init}
{
	//経過時間の初期化
	Time = 0;

	Time_2 = 0;

	Time_Left = 100;
	
	winner = Texture{ U"texture/winner.png" };

	// オーディオを再生
	audio.play();


}

void Stage_1::sub_update() {

	//クリア処理
	if (Kill >= 10) {
		win = true;
		Score = 0;
		stopwatch.start();
	}

	if (win)
		changeScene(State::Title);

	//経過時間
	Time += Scene::DeltaTime();
	Time_2 += Scene::DeltaTime();


	if (Time_Left <= 0) win = true;

	//敵の出現
	if (Time >= 5) {
		entity << Entity{ this, { 600 , 50 },Random(1,3) ,Are };
		Time = 0;
	}
	//アイテムの出現
	if (Time_2 >= 5) {

		item << Item{this, { Random(0,600) , Random(150,600)},Random(1,2) ,Are };
		Time_2 = 0;
	}



}

void Stage_1::sub_draw() const{
	if(win){
		winner.scaled(0.75).drawAt(400,300);
	}

}
