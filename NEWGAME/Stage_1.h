#pragma once
#include "Game.h"
class Stage_1 : public Game
{
public:
	Stage_1(const InitData& init);

	// 更新関数（オプション）
	void sub_update() override;

	// 描画関数（オプション）
	void sub_draw() const override;

private:
	double Time,Time_2;
	
};

