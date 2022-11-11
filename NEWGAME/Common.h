#pragma once
# include <Siv3D.hpp>

//シーン
enum class State
{
	Title,
	Select,
	Game,
	Stage_1	
};

//シーン間で共有するデータ
struct GameData
{
	//選択したステージ
	int stage = 0;

	//キーコンフィグの定義
	//struct keyconfig{
	//	InputGroup inputLeft;
	//	InputGroup inputRight;
	//	InputGroup inputUp;
	//	InputGroup inputDown;
	//	InputGroup inputShot;
	//};

	//Array<keyconfig> Keyconfig;
};

using App = SceneManager<State,GameData>;
