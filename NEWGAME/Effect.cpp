#include"Common.h"

struct Speed_Up : IEffect
{
	int m_time;

	int* m_speed;

	Font m_font = Font{ 50, Typeface::Heavy };

	explicit Speed_Up(int* s, int time)
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
		// 1 秒未満なら継続
		return (t < m_time);
	}
};

struct Damage_Down: IEffect
{
	int m_time;

	int* m_damage;

	explicit Damage_Down(int* d, int time)
		: m_time{ time }
		, m_damage{ d }
	{
		*m_damage = 50;
	}

	~Damage_Down() {
		*m_damage = 100;
	}

	bool update(double t) override
	{
		// 1 秒未満なら継続
		return (t < m_time);
	}
};

struct Speed_Down : IEffect
{
	int m_time;

	int* m_speed;

	explicit Speed_Down(int* s, int time)
		: m_time{ time }
		, m_speed{ s }
	{
		*m_speed -= 200;
	}

	~Speed_Down() {
		*m_speed += 200;
	}

	bool update(double t) override
	{
		// 1 秒未満なら継続
		return (t < m_time);
	}
};

struct Mazai: IEffect
{
	int m_time;

	int m_base_speed = 0;

	int* m_speed;

	bool one = true;

	explicit Mazai(int* s, int time)
		: m_time{ time }
		, m_speed{ s }
	{
		m_base_speed = *m_speed;

		*m_speed += 200;
	
	}

	~Mazai() {
		*m_speed += 200;
	}

	bool update(double t) override
	{
		if (t > m_time / 2 && one == true) {
			*m_speed -= 400;
			one = false;
		}

		// 1 秒未満なら継続
		return (t < m_time);

	}
};

struct ScoreEffect : IEffect
{
	Vec2 m_start;

	int32 m_score;

	Font m_font = Font{ 50, Typeface::Heavy };

	ScoreEffect(const Vec2& start, int32 score )
		: m_start{ start }
		, m_score{ score }
		{}

	bool update(double t) override
	{
		const HSV color{ (180 - m_score * 1.8), 1.0 - (t * 2.0) };

		m_font(m_score).drawAt(m_start.movedBy(0, t * -120), color);

		return (t < 0.5);
	}
};

struct Effect_Name : IEffect
{
	int m_num;

	String m_name;

	Font m_font = Font{ 25, Typeface::Heavy };

	Effect_Name(const int num, String name)
		: m_num{ num }
		, m_name{ name }
		{}

	bool update(double t) override
	{
		m_font(m_name).drawAt(10, 10 + 30 * m_num );

		return (t < 1.5);
	}
};

struct BubbleEffect : IEffect
{
	struct Bubble
	{
		Vec2 offset;
		double startTime;
		double scale;
		ColorF color;
	};

	Vec2 m_pos;

	Array<Bubble> m_bubbles;

	BubbleEffect(const Vec2& pos, double baseHue)
		: m_pos{ pos }
	{
		for (int32 i = 0; i < 8; ++i)
		{
			Bubble bubble{
				.offset = RandomVec2(Circle{30}),
				.startTime = Random(-0.3, 0.1), // 登場の時間差
				.scale = Random(0.1, 1.2),
				.color = HSV{ baseHue + Random(-30.0, 30.0) }
			};
			m_bubbles << bubble;
		}
	}

	bool update(double t) override
	{
		for (const auto& bubble : m_bubbles)
		{
			const double t2 = (bubble.startTime + t);

			if (not InRange(t2, 0.0, 1.0))
			{
				continue;
			}

			const double e = EaseOutExpo(t2);

			Circle{ (m_pos + bubble.offset + (bubble.offset * 4 * t)), (e * 40 * bubble.scale) }
				.draw(ColorF{ bubble.color, 0.15 })
				.drawFrame((30.0 * (1.0 - e) * bubble.scale), bubble.color);
		}

		return (t < 1.3);
	}
};

struct Item_use : IEffect
{
	String m_name;

	ColorF m_color;

	Font m_font = Font{ 50, Typeface::Heavy };

	// このコンストラクタ引数が、Effect::add<RingEffect>() の引数になる
	explicit Item_use(const String name,ColorF color)
		: m_name(name)
		, m_color{ color } {}

	bool update(double t) override
	{
		// 時間に応じて大きくなる輪
		m_font(m_name).drawAt({ 0,0 }, m_color);

		// 1 秒未満なら継続
		return (t < 2.0);
	}
};

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
