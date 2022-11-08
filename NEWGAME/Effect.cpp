#include"Common.h"
# include <Siv3D.hpp>

struct RingEffect : IEffect
struct Particle
{
	Vec2 m_pos;
	Vec2 start;

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
	Vec2 velocity;
};

struct Speed_Up : IEffect
struct Spark : IEffect
{
	int m_time;
	Array<Particle> m_particles;

	int* m_speed;
	
	explicit Speed_Up(int* s,int time)
		: m_time{ time }
		, m_speed{ s }
	explicit Spark(const Vec2& start)
		: m_particles(50)
	{
		*m_speed += 200;
		for (auto& particle : m_particles)
		{
			particle.start = start + RandomVec2(10.0);

			particle.velocity = RandomVec2(1.0) * Random(80.0);
	}

	~Speed_Up() {
		*m_speed -= 200;
	}
	
	bool update(double t) override
	{

		//FontAsset(U"TitleFont")(U"加速:"+Format(m_time-t)).drawAt(400, 100);

		// 1 秒未満なら継続
		return (t < m_time );
		for (const auto& particle : m_particles)
		{
			const Vec2 pos = particle.start
				+ particle.velocity * t + 0.5 * t * t * Vec2{ 0, 240 };

			Triangle{ pos, 16.0, (pos.x * 5_deg) }.draw(HSV{ pos.y - 40, (1.0 - t) });
	}
};

struct ScoreEffect : IEffect
{
	Vec2 m_start;

	int32 m_score;

	Font m_font = Font{ 50, Typeface::Heavy };

	ScoreEffect(const Vec2& start, int32 score)
		: m_start{ start }
		, m_score{ score } {}

	bool update(double t) override
	{
		const HSV color{ (180 - m_score * 1.8), 1.0 - (t * 2.0) };

		m_font(m_score).drawAt(m_start.movedBy(0, t * -120), color);

		return (t < 0.5);
		return (t < 1.0);
	}
};

