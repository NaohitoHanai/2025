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
	deadCounter = 0; // 死んでない
}

Bird::~Bird()
{
}

void Bird::Update()
{
	if (deadCounter > 0) {
		deadCounter -= 1;
		if (deadCounter == 0) {
			DestroyMe();
		}
		return;
	}

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
	if (deadCounter > 0) {
		DrawRectGraph(x - sc, y, 0, 64*4, 64, 64, hImage, 1);
	} else {
		DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
	}
	DrawCircle(x+32-sc, y+32, 30, GetColor(0,0,255), FALSE);
}

bool Bird::IsHit(float tx, float ty, float rad)
{
	if (deadCounter > 0) {
		return false;
	}
	// 弾の座標はtx, ty
	// 鳥の座標はx, y
	float dx = tx - (x+32);
	float dy = ty - (y+32);
	float d = sqrt(dx*dx+dy*dy);
	if (d<30+rad) {
//		DestroyMe();
		deadCounter = 30; // 0.5秒
		return true;
	}
	return false;
}



