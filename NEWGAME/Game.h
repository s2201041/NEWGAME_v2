#pragma once
#include "Common.h"
#include "Entity.h"
#include "Player.h"
#include "Effect.cpp"

class Game : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Game(const InitData& init);

	// 更新関数（オプションb）
	void update() override;

	// 描画関数（オプション）
	void draw() const override;

	void tes();

	//プレイヤー格納配列
	Array<Player> player;

	//エンティティ格納配列
	Array<Entity> entity;

	//動作範囲
	Rect Are;


private:

	Texture winner;

	int Score;

	int Time_Left;

	bool win;

	double time;

	const Font hp_font{ FontMethod::MSDF, 20, Typeface::Bold };

	Stopwatch stopwatch{ StartImmediately::Yes};

	const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };
	const String stage = Format(getData().stage);
};
