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
	if ((SimpleGUI::Button(U"１年", Vec2{ 350, 250 })||Key1.pressed())&&getData().tani>=0)
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_1);

		//ステージ1を選択
		getData().stage = 1;
	}

	if ((SimpleGUI::Button(U"２年", Vec2{ 350, 300 })||Key2.pressed())&&getData().tani>=1)
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_2);

		//ステージ2を選択
		getData().stage = 2;
	}

	if ((SimpleGUI::Button(U"３年", Vec2{ 350, 350 })||Key3.pressed())&&getData().tani>=2)
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_3);

		//ステージ3を選択
		getData().stage = 3;
	}

	if ((SimpleGUI::Button(U"４年", Vec2{ 350, 400 })||Key4.pressed())&&getData().tani>=3)
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_4);

		//ステージ4を選択
		getData().stage = 4;
	}

	if ((SimpleGUI::Button(U"５年", Vec2{ 350, 450 })||Key5.pressed())&&getData().tani>=4)
	{
		// ゲームシーンに遷移
		changeScene(State::Stage_5);

		//ステージ5を選択
		getData().stage = 5;
	}

	if(getData().tani < 1)
		hp_font(U"×").draw(350,300,Palette::Red);
	if(getData().tani < 2)
		hp_font(U"×").draw(350,350,Palette::Red);
	if(getData().tani < 3)
		hp_font(U"×").draw(350,400,Palette::Red);
	if(getData().tani < 4)
		hp_font(U"×").draw(350,450,Palette::Red);


}

void Select::draw() const
{

}
