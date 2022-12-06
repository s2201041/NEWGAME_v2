#include "Select.h"

Select::Select(const InitData& init)
	: IScene{ init }
{

	// オーディオを再生
	audio.play();
}

void Select::update()
{
	TextureAsset(U"Select").draw();

	// ボタン処理
	if (SimpleGUI::Button(U"Stage_1", Vec2{ 350, 250 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_1);

		//ステージ1を選択
		getData().stage = 1;
	}

	if (SimpleGUI::Button(U"Stage_2", Vec2{ 350, 300 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_2);

		//ステージ2を選択
		getData().stage = 2;
	}

	if (SimpleGUI::Button(U"Stage_3", Vec2{ 350, 350 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_3);

		//ステージ3を選択
		getData().stage = 3;
	}

	if (SimpleGUI::Button(U"Stage_4", Vec2{ 350, 400 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_4);

		//ステージ4を選択
		getData().stage = 4;
	}

	if (SimpleGUI::Button(U"Stage_5", Vec2{ 350, 450 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_5);

		//ステージ5を選択
		getData().stage = 5;
	}

	if (SimpleGUI::Button(U"Setting", Vec2{ 350, 500 }))
	{
		// ゲームシーンに遷移
		changeScene(State::Setting);
	}
}

void Select::draw() const
{

	//FontAsset(U"TitleFont")(U"Stage Select").drawAt(400, 100);
}
