#pragma once
#include "Common.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"

class Game : public App::Scene
{
public:

	// コンストラクタ（必ず実装）
	Game(const InitData& init);

	// 基底シーンの更新関数
	void update() override;

	virtual void sub_update() = 0;

	// 基底シーンの描画関数
	void draw() const override;

	virtual void sub_draw() const = 0;

	//ゲームオーバー関数
	void Game_Over();

	//プレイヤー格納配列
	Array<Player> player;

	//エンティティ格納配列
	Array<Entity> entity;

	//アイテム格納配列
	Array<Item> item;

	//ショット格納配列
	Array<Shot> en_shot;
	Array<Shot>	pl_shot;


	//動作範囲
	Rect Are;

	int Kill;

	int norma_Kill;

	Effect effect;

protected:

	Texture winner;

	//クリア判定
	bool win;

	//ゲームオーバー判定
	bool game_over;

	//制限時間
	double Time_Left;

	//経過時間
	double Time;

	//待機状態
	bool standby;

	//エンティティのリスト
	struct en {
		Entity entity;
		int num;
	};
	Array<en> Entity_List;
	
	const Font hp_font{ FontMethod::MSDF, 20, Typeface::Bold };

	Stopwatch stopwatch{ StartImmediately::Yes };

	const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf", FontStyle::Bitmap };
	const String stage = Format(getData().stage);

	// 音声ファイルを読み込んで Audio を作成（ストリーミング再生をリクエスト）
	const Audio audio{ Audio::Stream, U"sound/bgm_1.mp3" };


};
