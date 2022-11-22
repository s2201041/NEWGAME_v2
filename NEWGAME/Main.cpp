# include "Common.h"
# include "Title.h"
# include "Select.h"
# include "Game.h"
# include "Result.h"
# include "Stage_1.h"
# include "Stage_2.h"
# include "Stage_3.h"
# include "Stage_4.h"
# include "Stage_5.h"

//開発ベース ver0.0

//機能の更新

void Main()
{
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetStyle(WindowStyle::Sizable);

	//アセットの定義.
	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy, FontStyle::Bitmap);
	TextureAsset::Register(U"Title", U"example/Title.jpg", TextureDesc::Mipped);
	TextureAsset::Register(U"Select", U"example/Select.jpg", TextureDesc::Mipped);
	TextureAsset::Register(U"haikei", U"texture/haikei.png", TextureDesc::Mipped);
	//Shotアセット
	TextureAsset::Register(U"hinotama", U"texture/shot/hinotama.png" , TextureDesc::Mipped);
	TextureAsset::Register(U"blue_hinotama", U"texture/shot/blue_hinotama.png" , TextureDesc::Mipped);
	TextureAsset::Register(U"kaminari", U"texture/shot/kaminari.png" , TextureDesc::Mipped);
	TextureAsset::Register(U"juudan", U"texture/shot/juudan.png" , TextureDesc::Mipped);
	
	//Entityアセット
	TextureAsset::Register(U"enemy_1", U"texture/entity/enemy_1.png", TextureDesc::Mipped);
	TextureAsset::Register(U"enemy_2", U"texture/entity/enemy_2.png", TextureDesc::Mipped);


	//Playerアセット
	TextureAsset::Register(U"player_1_up", U"texture/player/player_1_up.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_down", U"texture/player/player_1_down.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_left", U"texture/player/player_1_left.png", TextureDesc::Mipped);
	TextureAsset::Register(U"player_1_right", U"texture/player/player_1_right.png", TextureDesc::Mipped);

	//Itemasset
	TextureAsset::Register(U"mazai",U"texture/item/mazai.png", TextureDesc::Mipped);
	TextureAsset::Register(U"kakomon",U"texture/item/kakomon.png", TextureDesc::Mipped);
	TextureAsset::Register(U"report",U"texture/item/report.png", TextureDesc::Mipped);
	TextureAsset::Register(U"item_2",U"texture/item/item_2.png", TextureDesc::Mipped);

	//サウンドアセット
	AudioAsset::Register(U"cla_sound", U"sound/cla.mp3");
	AudioAsset::Register(U"clear_sound", U"sound/clear.mp3");
	//sceneの追加
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Select>(State::Select);
	manager.add<Result>(State::Result);
	manager.add<Stage_1>(State::Stage_1);
	manager.add<Stage_2>(State::Stage_2);
	manager.add<Stage_3>(State::Stage_3);
	manager.add<Stage_4>(State::Stage_4);
	manager.add<Stage_5>(State::Stage_5);


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
