#include "Select.h"

Select::Select(const InitData& init)
	: IScene{ init }
{
	// オーディオを再生
	audio.play();

	s_stage = getData().tani+1;

	player_select = 0;

	getData().p_data[0].name = U"プレイヤー１";
	getData().p_data[1].name = U"プレイヤー２";

}

void Select::update()
{
	auto controller = XInput(0);

	TextureAsset(U"Select").draw();


	if (KeyUp.down() || controller.buttonUp.down())
		if (s_stage != 1)
			s_stage--;
		else
			s_stage = 5;
	if (KeyDown.down() || controller.buttonDown.down()||controller.buttonB.down())
		if (s_stage != 5)
			s_stage++;
		else
			s_stage = 1;

	if (KeyP.down() || controller.buttonX.down())
		if (player_select != 1)
			player_select++;
		else
			player_select--;

	if(controller.buttonA.down()||KeySpace.down())
		if (s_stage <= getData().tani+1) {
			if (s_stage == 1) changeScene(State::Stage_1);
			if (s_stage == 2) changeScene(State::Stage_2);
			if (s_stage == 3) changeScene(State::Stage_3);
			if (s_stage == 4) changeScene(State::Stage_4);
			if (s_stage == 5) changeScene(State::Stage_5);
		getData().stage = s_stage ;
		}
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

	Rect{ 350, 200 + 50 *s_stage, 80, 37 }.drawFrame(3,0,ColorF(1,0,0,0.5));

	if (getData().tani < 1) {
		Rect{ 350, 200 + 50 * 2, 80, 37 }.draw( ColorF(0, 0, 0, 0.5));
	}
	if (getData().tani < 2) {
		Rect{ 350, 200 + 50 * 3, 80, 37 }.draw( ColorF(0, 0, 0, 0.5));
	}
	if (getData().tani < 3) {
		Rect{ 350, 200 + 50 * 4, 80, 37 }.draw( ColorF(0, 0, 0, 0.5));
	}
	if (getData().tani < 4) {
		Rect{ 350, 200 + 50 * 5, 80, 37 }.draw( ColorF(0, 0, 0, 0.5));
	}

	SimpleGUI::RadioButtons(player_select, { U"1人でプレイ", U"２人でプレイ" }, Vec2{ 600, 400 });
	getData().player_data = player_select;
}

void Select::draw() const
{

}
