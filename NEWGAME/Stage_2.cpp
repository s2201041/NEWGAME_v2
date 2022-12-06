#include "Stage_2.h"

Stage_2::Stage_2(const InitData& init)
	: Game{init}
{
	Time_Left = 100;
}

void Stage_2::sub_update() {
	if (Time_Left <= 0) win = true;
}

void Stage_2::sub_draw() const {

}
