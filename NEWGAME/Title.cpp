#include "Title.h"

Title::Title(const InitData& init)
	: IScene{ init }
{
	//Keyconfigの初期化
	//getData().Keyconfig[0] = { KeyLeft, KeyRight, KeyUp, KeyDown, KeySpace, };
	//getData().Keyconfig[1] = { KeyLeft, KeyRight, KeyUp, KeyDown, KeySpace, };

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
	TextureAsset(U"haikei").scaled(4.0).draw();

	FontAsset(U"TitleFont")(U"New Game").drawAt(400, 100);


}
