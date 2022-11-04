#pragma once
#include "Common.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include <vector>

class Game : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Game(const InitData& init);

	// 更新関数（オプションb）
	void update() override;

	// 描画関数（オプション）
	void draw() const override;

	//プレイヤー格納配列
	Array<Player> player;

	//エンティティ格納配列
	Array<Entity> entity;

	//アイテム格納配列
	Array<Item> item;

	//ショット格納配列
	Array<Shot> en_shot;
	Array<Shot>	pl_shot;


	//動作範囲
	Rect Are;

	int Score,Kill;
private:

	Texture winner;

	double Time_Left;

	bool win;

	double Time,Time_2;

	const Font hp_font{ FontMethod::MSDF, 20, Typeface::Bold };

	Stopwatch stopwatch{ StartImmediately::Yes};

	const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };
	const String stage = Format(getData().stage);
};
