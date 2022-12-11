#include "Title.h"

Title::Title(const InitData& init)
	: IScene{ init }
{


	// オーディオを再生
	audio.play();
}

void Title::update()
{
	auto controller = XInput(0);

	// 左クリックで
	if (MouseL.down()||KeySpace.pressed()||controller.buttonA.down())
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
