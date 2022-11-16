#include "Select.h"

Select::Select(const InitData& init)
	: IScene{ init }
{
	// オーディオを再生
	audio.play();
}

void Select::update()
{

	// ボタン処理
	if (SimpleGUI::Button(U"Stage1", Vec2{ 350, 250 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_1);

		//ステージ1を選択
		getData().stage = 1;
	}

	if (SimpleGUI::Button(U"Stage2", Vec2{ 350, 300 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Game);

		//ステージ2を選択
		getData().stage = 2;
	}

	if (SimpleGUI::Button(U"Stage3", Vec2{ 350, 350 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Game);

		//ステージ3を選択
		getData().stage = 3;
	}

	if (SimpleGUI::Button(U"Stage4", Vec2{ 350, 400 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Game);

		//ステージ3を選択
		getData().stage = 4;
	}

}

void Select::draw() const
{
	TextureAsset(U"Select").draw();

	//FontAsset(U"TitleFont")(U"Stage Select").drawAt(400, 100);
}
