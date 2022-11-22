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
}
