#include "Stone.h"
#include "Field.h"
#include "Bird.h"
#include <assert.h>

Stone::Stone()
{
	hImage = LoadGraph("data/image/stone.png");
	position = VECTOR3(0, 0, 0);
}

Stone::Stone(int sx, int sy, float vx, float vy)
{
	hImage = LoadGraph("data/image/stone.png");
	assert(hImage > 0);
	position = VECTOR3(sx, sy, 0);
	velocity = VECTOR3(vx, vy, 0);
}

Stone::~Stone()
{
}

void Stone::Update()
{
	position += velocity;
// Bird‚ª‚P‚Â‚µ‚©‚¢‚È‚¢‚Æ‚«
//	Bird *b = FindGameObject<Bird>();
//	b->IsHit(x, y);
// Bird‚ª‚¢‚Á‚Ï‚¢‚¢‚é‚Æ‚«
	auto birds = FindGameObjects<Bird>();
//–{“–‚È‚ç‚±‚¤‘‚­
// 	for (std::list<Bird*>::iterator it = birds.begin();
//			it != birds.end(); it++) {
//		Bird* b = *it;
	for (auto b : birds) {
		if (b->IsHit(position.x+10, position.y+10, 5)) {
			DestroyMe();
		}
	}

	//int m[20];
	//for (int& d : m) { // int&‚Ì•‚ÍQÆ‚Æ‚¢‚¤ˆÓ–¡
	//	if (d == 0) {
	//		d = 3;
	//	}
	//}
}


void Stone::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawGraph(position.x - sc, position.y, hImage, 1);
	DrawCircle(position.x+10 - sc, position.y+10, 5, GetColor(0, 0, 255), FALSE);
}
