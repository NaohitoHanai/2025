#include "Field.h"

int m[8] = { 1,1,1,0,1,0,1,1 };

Field::Field()
{
	hImage = LoadGraph("data/image/bgchar.png");
	x = 0;
	y = 600;
}

Field::~Field()
{
}

void Field::Update()
{
}

void Field::Draw()
{
	for (int i = 0; i < 8; i++) {
		if (m[i] == 1) {
			DrawRectGraph(x + i * 64, y, 0, 32, 64, 64, hImage, 1);
		}
	}
}

int Field::HitCheck(int px, int py)
{
	int blockX = px / 64;
	if (m[blockX] == 0)
		return 0;
	if (py >= 600)
		return py - 600 + 1;
	return 0;
}











