#include "Bird.h"
#include "Field.h"
#include "Screen.h"

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
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	// 表示座標は(x-sc, y)
	if (x - sc > Screen::WIDTH) {
		return;
	}
	if (x - sc <= -64) {
		DestroyMe();
	}

	
	x -= 0.5f;
}

void Bird::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}

bool Bird::IsHit(float tx, float ty)
{
	// 弾の座標はtx, ty
	// 鳥の座標はx, y
	float dx = tx - x;
	float dy = ty - y;
	float d = sqrt(dx*dx+dy*dy);
	if (d<30+5) {
		DestroyMe();
		return true;
	}
	return false;
}



