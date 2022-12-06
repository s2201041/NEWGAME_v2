#include "Result.h"

Result::Result(const InitData& init)
	: IScene{ init }
{
}

void Result::update(){

	if (MouseL.down())
	{
		changeScene(State::Title);
	}
}

void Result::draw() const {

	if(getData().win)
		t_font(U"GAME CLEAR").drawAt(400, 100, Palette::White);
	else
		t_font(U"GAME OVER").drawAt(400, 100, Palette::White);

	font(U"ステージ："+ stage).draw(300, 300, Palette::White);
	font(U"スコア：" + score).draw(300, 400, Palette::White);
	font(U"獲得単位数：" + kill).draw(300, 500, Palette::White);
}
