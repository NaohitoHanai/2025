#include "Bird.h"
#include "Field.h"

Bird::Bird()
{
	hImage = LoadGraph("data/image/mob.png");
	x = 0;
	y = 0;
}

Bird::Bird(int sx, int sy)
{
	hImage = LoadGraph("data/image/mob.png");
	x = sx;
	y = sy;
}

Bird::~Bird()
{
}

void Bird::Update()
{
}

void Bird::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}
