# include "Common.h"
# include "Title.h"
# include "Select.h"
# include "Game.h"

//開発ベース ver0.0

//機能の更新

void Main()
{
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetStyle(WindowStyle::Sizable);

	//アセットの定義.
	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy, FontStyle::Bitmap);
	TextureAsset::Register(U"haikei", U"texture/haikei.png", TextureDesc::Mipped);

	//Shotアセット
	TextureAsset::Register(U"shot_1", U"texture/shot/shot_1.png" , TextureDesc::Mipped);
	TextureAsset::Register(U"shot_2", U"texture/shot/shot_2.png" , TextureDesc::Mipped);
	
	//Entityアセット
	TextureAsset::Register(U"enemy_1", U"texture/entity/enemy_1.png", TextureDesc::Mipped);
	TextureAsset::Register(U"enemy_2", U"texture/entity/enemy_2.png", TextureDesc::Mipped);


	//Playerアセット
	TextureAsset::Register(U"player_1_up", U"texture/player/player_1_up.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_down", U"texture/player/player_1_down.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_left", U"texture/player/player_1_left.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_right", U"texture/player/player_1_right.png", TextureDesc::Mipped);


	//sceneの追加
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Select>(State::Select);
	manager.add<Game>(State::Game);


	// ゲームシーンから開始したい場合はこのコメントを外す
	manager.init(State::Title);

	while (System::Update())
	{
		//ドット感を出す呪文
		const ScopedRenderStates2D state(SamplerState::ClampNearest);

		//window名を設定
		Window::SetTitle(U"NewGame");

		if (not manager.update())
		{
			break;
		}
	}
}
