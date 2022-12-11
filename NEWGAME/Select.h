#pragma once
#include "Common.h"

class Select : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Select(const InitData& init);

	// 更新関数（オプション）
	void update() override;

	// 描画関数（オプション）
	void draw() const override;

private:

	int s_stage;

	double time;

	const Font hp_font{ FontMethod::MSDF, 24};

	const Font font{ 24, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };

	// 音声ファイルを読み込んで Audio を作成（ストリーミング再生をリクエスト）
	const Audio audio{ Audio::Stream, U"sound/bgm_2.ogg" };


};
