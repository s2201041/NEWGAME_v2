#pragma once
#include "Common.h"

class Result : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Result(const InitData& init);

	// 更新関数（オプション）
	void update() override;

	// 描画関数（オプション）
	void draw() const override;

private:

	bool win;

	const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };

	const Font t_font{ 64, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };

	const String stage = Format(getData().stage);
	const String score = Format(getData().p_data[0].score);
	const String score2 = Format(getData().p_data[1].score);

	const String name = Format(getData().p_data[0].name);
	const String name2 = Format(getData().p_data[1].name);
	const String kill = Format(getData().kill);
	const String norma_kill = Format(getData().norma_kill);
};

