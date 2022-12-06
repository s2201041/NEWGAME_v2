#include "Result.h"

Result::Result(const InitData& init)
	: IScene{ init }
{
	if (getData().kill >= getData().norma_kill)
		win = true;
	else
		win = false;
}

void Result::update(){

	if (MouseL.down())
	{
		changeScene(State::Title);
	}
}

void Result::draw() const {

	if(win)
		t_font(U"進級！").drawAt(400, 100, Palette::White);
	else
		t_font(U"留年…").drawAt(400, 100, Palette::White);

	font(U"ステージ："+ stage).draw(300, 300, Palette::White);
	font(U"スコア：" + score).draw(300, 400, Palette::White);
	font(U"必要単位数：" + kill + U"/" + norma_kill).draw(300, 500, Palette::White);
}
