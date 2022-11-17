#include "Game.h"
#include <vector>

Game::Game(const InitData& init)
	: IScene{ init }
{

	Kill = 0;

	Score = 0;

	win = false;

	player << Player{ this, { 300 , 300 } ,1 ,Are };

	//動作範囲
	Are = Rect{ 0, 0, 600, 600 };
}

void Game::update() {

	//制限時間の更新
	Time_Left -= Scene::DeltaTime();

	//敵の動作処理
	for (auto& en : entity) {
		en.update();
		if (en.Del)
			Kill++;
	}

	//プレイヤーの動作処理
	for (auto& pl : player) {
		pl.update();
		if (pl.Del)
			changeScene(State::Title);
	}

	//敵ショットの動作処理
	for (auto& sh : en_shot) {
		sh.update();
	}

	//自機ショットの動作処理
	for (auto& sh : pl_shot) {
		sh.update();
	}

	//アイテムの動作処理
	for (auto& it : item) {
		it.update();
	}

	//衝突判定
	for (auto& pl : player) {
		for (auto& en : entity) {
			for (auto& sh : pl_shot) {
				//自機ショットと敵の衝突処理
				if (en.Col.intersects(sh.Col)) {
					sh.cla(&en);
					en.cla(&sh);
				}
			}
			for (auto& sh : en_shot) {
				//敵ショットと自機の衝突処理
				if (pl.Col.intersects(sh.Col)) {
					pl.cla(&sh);
					sh.cla(&pl);
				}
			}
			//敵と自機の衝突判定
			if (en.Col.intersects(pl.Col)) {
				en.cla(&pl);
				pl.cla(&en);
			}
		}
		//自機とアイテムの衝突判定
		for (auto& it : item) {
			if (it.Col.intersects(pl.Col)) {
				pl.cla(&it);
				it.cla(&pl);
			}
		}
	}

	//敵から最も近い自機の座標
	if (player.size() != 0)
		for (auto& en : entity) {
			double j, imin = 0, jmin = -1;
			for (int i = 0; i < player.size(); i++) {
				j = (player[i].Pos.x - en.Pos.x) * (player[i].Pos.x - en.Pos.x) + (player[i].Pos.y - en.Pos.y) * (player[i].Pos.y - en.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			en.NearPos = player[imin].Pos;
		}

	//自機から最も近い敵の座標
	if (entity.size() != 0)
		for (auto& pl : player) {
			double j, imin = 0, jmin = -1;
			for (int i = 0; i < entity.size(); i++) {
				j = (entity[i].Pos.x - pl.Pos.x) * (entity[i].Pos.x - pl.Pos.x) + (entity[i].Pos.y - pl.Pos.y) * (entity[i].Pos.y - pl.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			pl.NearPos = entity[imin].Pos;
		}

	//ショットからエンティティの直近座標
	if (entity.size() != 0) {
		for (auto& sh : pl_shot) {
			double j, imin = 0, jmin = -1;
			for (int i = 0; i < entity.size(); i++) {
				j = (entity[i].Pos.x - sh.Pos.x) * (entity[i].Pos.x - sh.Pos.x) + (entity[i].Pos.y - sh.Pos.y) * (entity[i].Pos.y - sh.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			sh.NearPos = entity[imin].Pos;
		}

		for (auto& sh : en_shot) {
			double j, imin = 0, jmin = -1;
			for (int i = 0; i < player.size(); i++) {
				j = (player[i].Pos.x - sh.Pos.x) * (player[i].Pos.x - sh.Pos.x) + (player[i].Pos.y - sh.Pos.y) * (player[i].Pos.y - sh.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			sh.NearPos = player[imin].Pos;
		}
	}
	else
		for (auto& sh : pl_shot)
			sh.NearPos = { 300,0 };

	//消去判定
	entity.remove_if([](const Entity& en) { return en.Del == true; });
	player.remove_if([](const Player& pl) { return pl.Del == true; });
	en_shot.remove_if([](const Shot& sh) { return sh.Del == true; });
	pl_shot.remove_if([](const Shot& sh) { return sh.Del == true; });
	item.remove_if([](const Item& it) { return it.Del == true; });

	//派生シーンの更新処理
	sub_update();
}

void Game::draw() const
{
	//背景の描画
	TextureAsset(U"haikei").scaled(2.5).draw();

	//システムウィンドウの描画
	Rect{ 600, 0, 200, 600 }.draw(Arg::top = Palette::White, Arg::bottom = Palette::Silver).drawFrame(5, 0, Palette::Black);
	Line{ 605, 80, 800, 80 }.draw(3, Palette::Black);
	Line{ 605, 160, 800, 160 }.draw(3, Palette::Black);
	Line{ 605, 500, 800, 500 }.draw(3, Palette::Black);
	font(U"ステージ" + stage).draw(620, 13, Palette::Black);
	font(U"残り時間" + Format(Time_Left)).draw(620, 93, Palette::Black);
	font(U"スコア:" + Format(Score)).draw(620, 160, Palette::Black);
	font(U"キル数：" + Format(Kill)).draw(620, 190, Palette::Black);

	//プレイヤーの描画
	for (auto& pl : player) {
		pl.draw();
		RectF{ 610 , 550, 180, 20 }.draw(Palette::Orange);;
		RectF{ 610 , 550, pl.Hp * 180 / pl.Max_Hp , 20 }.draw(Palette::Red);;
	}

	//敵の描画
	for (int i = 0; i < entity.size(); i++) {
		entity[i].draw();
		RectF{ 25 , 25 + i * 30 , 550, 15 }.draw(Palette::Orange);;
	RectF{ 25 , 25 + i * 30 , entity[i].Hp * 550 / entity[i].Max_Hp, 15 }.draw(Palette::Red);;
		hp_font(entity[i].Hp).drawAt(300, 30 + i * 30);
		hp_font(entity[i].Nam).drawAt(300, 45 + i * 30);
	}

	//敵ショットの描画
	for (int i = 0; i < en_shot.size(); i++) {
		en_shot[i].draw();
	}

	//自機ショットの描画
	for (int i = 0; i < pl_shot.size(); i++) {
		pl_shot[i].draw();
	}

	//アイテムの描画
	for (auto& it : item) {
		it.draw();
	}

	//エフェクトの更新
	effect.update();

	//派生シーンの描画処理
	sub_draw();
}
