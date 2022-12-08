#pragma once
#include "Game.h"
class Stage_5 : public Game
{
public:
	Stage_5(const InitData& init);

	// 更新関数
	void sub_update() override;

	// 描画関数
	void sub_draw() const override;

private:
	double Entity_Time,Item_Time;
};
