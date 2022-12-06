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

	const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };

	const Font t_font{ 64, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };

	const String stage = Format(getData().stage);
	const String score = Format(getData().score);
	const String kill = Format(getData().kill);
};

