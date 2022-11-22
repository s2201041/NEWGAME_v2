#pragma once
# include <Siv3D.hpp>

//シーン
enum class State
{
	Title,
	Select,
	Result,
	Game,
	Stage_1,	
	Stage_2,
	Stage_3,	
	Stage_4,	
	Stage_5,	
};

//シーン間で共有するデータ
struct GameData
{
	//選択したステージ
	int stage = 0;

	//スコア
	int score = 0;

	//キル数
	int kill = 0;

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
