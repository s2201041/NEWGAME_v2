#include "Stage_1.h"

Stage_1::Stage_1(const InitData& init) 
	: Game{init}
{
	entity << Entity{ this, { 100 , 100 },2 ,Are};
	entity << Entity{ this, { 200 , 100 },1 ,Are};
	entity << Entity{ this, { 300 , 100 },2 ,Are};
}

void Stage_1::sub_update() {
	Print << U"派生シーンの実行";

}

void Stage_1::sub_draw() const{

}
