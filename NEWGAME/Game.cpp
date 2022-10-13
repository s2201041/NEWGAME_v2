#include "Game.h"


Game::Game(const InitData& init)
	: IScene{ init }
{
	//経過時間の初期化
	time = 0;

	//動作範囲
	Are = Rect{ 0, 0, 600, 600 };

	//ステージ表示
	//Print << getData().stage;

	entity << Entity{ { 100 , 100 },1 ,Are};
	player << Player{ { 0 , 0 } ,1 ,Are};
}

void Game::update() {

	//経過時間
	time += Scene::DeltaTime();

	//敵の出現
	if (time >= 5) {
		entity << Entity{ { 600 , 50 },Random(1,2) ,Are};
		time = 0;
	}

	

	//敵の動作処理
	for (auto& en : entity)
		en.update();

	//プレイヤーの動作処理
	for (auto& pl : player)
		pl.update();

	for (auto& pl : player) {
		if (pl.Del == true)
			changeScene(State::Title);
	}

	//for (auto& en : entity) {
	//	if (en.Del == true)
	//		entity << Entity{ { 100 , 100 },1 };
	//}


	//消去判定
	entity.remove_if([](const Entity& en) { return en.Del == true; });
	player.remove_if([](const Player& pl) { return pl.Del == true; });



	//衝突判定
	for (auto& en : entity)
		for (auto& pl : player) {
			for (auto& sh : pl.shot)
				//自機ショットと敵の衝突処理
				if (en.Col.intersects(sh.Col)) {
					sh.cla();
					en.sh_cla();
				}
			for (auto& sh : en.shot)
				//敵ショットと自機の衝突処理
				if (pl.Col.intersects(sh.Col)) {
					sh.cla();
					pl.sh_cla();
				}
			//敵と自機の衝突判定
			if (en.Col.intersects(pl.Col)) {
				en.pl_cla();
				pl.en_cla(en.Typ);
			}
		}



	//敵から最も近い自機の座標
	if (player.size() != 0)
		for (auto& en : entity) {
			double j, imin, jmin = -1;
			for (int i = 0; i < player.size(); i++) {
				j = (player[i].Pos.x - en.Pos.x) * (player[i].Pos.x - en.Pos.x) + (player[i].Pos.y - en.Pos.y) * (player[i].Pos.y - en.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			en.PlPos = player[imin].Pos;
		}

	//自機から最も近い敵の座標
	if (entity.size() != 0)
		for (auto& pl : player) {
			double j, imin, jmin = -1;
			for (int i = 0; i < entity.size(); i++) {
				j = (entity[i].Pos.x - pl.Pos.x) * (entity[i].Pos.x - pl.Pos.x) + (entity[i].Pos.y - pl.Pos.y) * (entity[i].Pos.y - pl.Pos.y);
				if (jmin < j) {
					jmin = j;
					imin = i;
				}
			}
			pl.EnPos = entity[imin].Pos; }
}

void Game::draw() const
{
	//背景の描画
	TextureAsset(U"haikei").scaled(2.0).draw();
	
	//システムウィンドウの描画
	Rect{ 600, 0, 200, 600 }.draw();

	//プレイヤーの描画
	for (auto& pl : player) {
		pl.draw();
		RectF{ 610 , 550, 180, 20 }.draw(Palette::Orange);;
		RectF{ 610 , 550, pl.Hp * 1.8, 20 }.draw(Palette::Red);;
	}


	
	//敵の描画
	for (int i = 0; i < entity.size(); i++) {
		entity[i].draw();
		RectF{ 25 , 25 + i * 30 , 550, 15 }.draw(Palette::Orange);;
		RectF{ 25 , 25 + i * 30 , entity[i].Hp * 5.5, 15}.draw(Palette::Red);;
		hp_font(entity[i].Hp).drawAt( 10, 300, 25 + i * 30);
		hp_font(entity[i].Nam).drawAt(20, 300, 35 + i * 30);

	}


}

