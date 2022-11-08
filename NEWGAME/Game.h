#pragma once
#include "Common.h"
#include "Entity.h"
#include "Player.h"

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

	//動作範囲
	Rect Are;

private:

	Effect effect;

	double time;
    double hit;
	const Font hp_font{ FontMethod::MSDF, 10, Typeface::Bold };


	const Font font32{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };
	const Font font18{ 18, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };
	const String stage = Format(getData().stage);
};
