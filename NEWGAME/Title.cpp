#include "Title.h"

Title::Title(const InitData& init)
	: IScene{ init }
{
	//Keyconfigの初期化
	//getData().Keyconfig[0] = { KeyLeft, KeyRight, KeyUp, KeyDown, KeySpace, };
	//getData().Keyconfig[1] = { KeyLeft, KeyRight, KeyUp, KeyDown, KeySpace, };


	// オーディオを再生
	audio.play();
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
