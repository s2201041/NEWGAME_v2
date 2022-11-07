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

struct Speed_Up : IEffect
{
	int m_time;

	int* m_speed;
	
	explicit Speed_Up(int* s,int time)
		: m_time{ time }
		, m_speed{ s }
	{
		*m_speed += 200;

	}

	~Speed_Up() {
		*m_speed -= 200;
	}
	
	bool update(double t) override
	{

		FontAsset(U"TitleFont")(U"加速:"+Format(m_time-t)).drawAt(400, 100);

		// 1 秒未満なら継続
		return (t < m_time );

	}
};
