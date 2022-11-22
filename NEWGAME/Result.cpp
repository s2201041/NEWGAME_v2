#include "Result.h"

Result::Result(const InitData& init)
	: IScene{ init }
{


}

void Result::update(){

	if (MouseL.down())
	{
		changeScene(State::Select);
	}
}

void Result::draw() const {


	font(U"ステージ："+ stage).draw(300, 300, Palette::White);
	font(U"スコア：" + stage).draw(300, 400, Palette::White);
	font(U"キル数：" + stage).draw(300, 500, Palette::White);
}
