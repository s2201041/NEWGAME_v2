#pragma once
#include "Game.h"
class Stage_3 : public Game
{
public:
	Stage_3(const InitData& init);

	// 更新関数
	void sub_update() override;

	// 描画関数
	void sub_draw() const override;
};
