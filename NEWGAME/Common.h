#pragma once
# include <Siv3D.hpp>

//シーン
enum class State
{
	Title,
	Select,
	Result,
	Game,
	Setting,
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

	int norma_kill = 0;

	//勝利判定
	bool win = false;

	//合格
	int tani = 0;

	struct score_data {
		int score;
		int kill;
		int norma_kill;
	};

	score_data ranking[5][10];
};

using App = SceneManager<State,GameData>;
