#include "Bird.h"
#include "Field.h"
#include "Screen.h"
#include "Player.h"

Bird::Bird()
{
	hImage = LoadGraph("data/image/mob.png");
	position = VECTOR3(0,0,0);
}

Bird::Bird(int sx, int sy)
{
	hImage = LoadGraph("data/image/mob.png");
	position = VECTOR3(sx, sy, 0);
	deadCounter = 0; // 死んでない
}

Bird::~Bird()
{
}

void Bird::Update()
{
	Player* p = FindGameObject<Player>();
	VECTOR3 pPos = p->GetPosition(); // プレイヤーの位置
	velocity = pPos - position;
	velocity = velocity.Normalize()*0.5f;

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
	if (position.x - sc > Screen::WIDTH) {
		return;
	}
	if (position.x - sc <= -64) {
		DestroyMe();
	}

	position += velocity;
}

void Bird::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	if (deadCounter > 0) {
		DrawRectGraph(position.x - sc, position.y, 0, 64*4, 64, 64, hImage, 1);
	} else {
		DrawRectGraph(position.x - sc, position.y, 0, 0, 64, 64, hImage, 1);
	}
	DrawCircle(position.x+32-sc, position.y+32, 30, GetColor(0,0,255), FALSE);
}

bool Bird::IsHit(float tx, float ty, float rad)
{
	if (deadCounter > 0) {
		return false;
	}
	// 弾の座標はtx, ty
	VECTOR3 t = VECTOR3(tx, ty, 0);
	// 鳥の座標はx, y
	VECTOR3 b = position+VECTOR3(32,32,0);
	VECTOR3 d = t - b; // 移動後-移動前
	if (d.Size() < 30+rad) {
		deadCounter = 30; // 0.5秒
		return true;
	}
	return false;
}

