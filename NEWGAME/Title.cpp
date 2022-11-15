﻿#include "Title.h"

Title::Title(const InitData& init)
	: IScene{ init }
{
}

void Title::update()
{
	// 左クリックで
	if (MouseL.down())
	{
		// ゲームシーンに遷移
		changeScene(State::Select);
	}
}

void Title::draw() const
{
	TextureAsset(U"Title").draw();

	//FontAsset(U"TitleFont")(U"new Game").drawAt(400, 100);
}
