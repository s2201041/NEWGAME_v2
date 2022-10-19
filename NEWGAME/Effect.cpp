#include"Common.h"

struct RingEffect : IEffect
{
	Vec2 m_pos;

	ColorF m_color;

	// このコンストラクタ引数が、Effect::add<RingEffect>() の引数になる
	explicit RingEffect(const Vec2& pos)
		: m_pos{ pos }
		, m_color{ RandomColorF() } {}

	bool update(double t) override
	{
		// 時間に応じて大きくなる輪
		Circle{ m_pos, (t * 100) }.drawFrame(4, m_color);

		// 1 秒未満なら継続
		return (t < 1.0);
	}
};

 
