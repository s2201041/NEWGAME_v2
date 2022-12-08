#pragma once
#include "Game.h"

class Stage_1 : public Game {
public:
	Stage_1(const InitData& init);

	// 更新関数（オプション）
	void sub_update() override;

	// 描画関数（オプション）
	void sub_draw() const override;

private:
	double Entity_Time,Item_Time;

	Array<en> Entity_List;
	
	// 音声ファイルを読み込んで Audio を作成（ストリーミング再生をリクエスト）
	const Audio audio{ Audio::Stream, U"sound/bgm_1.mp3" };

};
