#pragma once
#include "Common.h"
#include "Entity.h"
#include "Player.h"

class Game : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Game(const InitData& init);

	// 更新関数（オプションb）
	void update() override;

	// 描画関数（オプション）
	void draw() const override;

	void tes(Array<Base*> base);

	//プレイヤー格納配列
	Array<Player> player;

	//エンティティ格納配列
	Array<Base*> entity;

	//Base * entity[2];

	//動作範囲
	Rect Are;

private:

	double time;

	const Font hp_font{ FontMethod::MSDF, 20, Typeface::Bold };



};
