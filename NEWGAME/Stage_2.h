#pragma once
#include "Game.h"
class Stage_2 : public Game
{
public:
	Stage_2(const InitData& init);

	// 更新関数
	void sub_update() override;

	// 描画関数
	void sub_draw() const override;

private:
	Array<en> Entity_List;

	double Entity_Time,Item_Time;
};

