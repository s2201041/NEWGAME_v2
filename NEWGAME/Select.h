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

	double time;

	const Font hp_font{ FontMethod::MSDF, 10, Typeface::Bold };

	// 音声ファイルを読み込んで Audio を作成（ストリーミング再生をリクエスト）
	const Audio audio{ Audio::Stream, U"C:/Users/a0tg3/Downloads/bgm_classic_etc_scarboroughfair.wav" };

};
