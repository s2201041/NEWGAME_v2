#include "Setting.h"

Setting::Setting(const InitData& init)
	: IScene{ init }
{
}

void Setting::update()
{
	// 左クリックで
	if (MouseL.down())
	{
		// ゲームシーンに遷移
		changeScene(State::Select);
	}
}

void Setting::draw() const
{
	TextureAsset(U"Title").draw();
}
