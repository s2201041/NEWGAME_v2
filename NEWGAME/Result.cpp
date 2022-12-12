#include "Result.h"

Result::Result(const InitData& init)
	: IScene{ init }
{
	if (getData().kill >= getData().norma_kill) {
		win = true;
		getData().tani = getData().stage;
	}
	else
		win = false;

	/*
	JSON json;

	json = getData().ranking;
	
	json.save(U"score.json");
	*/
}

void Result::update(){

	auto controller = XInput(0);

	if (MouseL.down()||KeySpace.pressed()||KeySpace.pressed()||controller.buttonA.down())
	{
		changeScene(State::Title);
	}
}

void Result::draw() const {

	if(win)
		t_font(U"進級！").drawAt(400, 100, Palette::White);
	else
		t_font(U"留年…").drawAt(400, 100, Palette::White);

	font(U"ステージ："+ stage).draw(300, 200, Palette::White);

	font(name + U"スコア：" + score).draw(250, 300, Palette::White);
	if(getData().player_data == 1)
		font(name2 + U"スコア：" + score2).draw(250, 400, Palette::White);

	font(U"必要単位数：" + kill + U"/" + norma_kill).draw(300, 500, Palette::White);
}
