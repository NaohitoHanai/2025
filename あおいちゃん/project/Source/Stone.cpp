#include "Stone.h"
#include "Field.h"
#include "Bird.h"
#include <assert.h>

Stone::Stone()
{
	hImage = LoadGraph("data/image/stone.png");
	x = 0;
	y = 0;
}

Stone::Stone(int sx, int sy, float vx, float vy)
{
	hImage = LoadGraph("data/image/stone.png");
	assert(hImage > 0);

	x = sx;
	y = sy;
	velocityX = vx;
	velocityY = vy;
}

Stone::~Stone()
{
}

void Stone::Update()
{
	x += velocityX;
	y += velocityY;
// Bird‚ª‚P‚Â‚µ‚©‚¢‚È‚¢‚Æ‚«
//	Bird *b = FindGameObject<Bird>();
//	b->IsHit(x, y);
// Bird‚ª‚¢‚Á‚Ï‚¢‚¢‚é‚Æ‚«
	auto birds = FindGameObjects<Bird>();
	for (auto b : birds) {
		if (b->IsHit(x+10, y+10, 5)) {
			DestroyMe();
		}
	}
}


void Stone::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawGraph(x - sc, y, hImage, 1);
	DrawCircle(x+10 - sc, y+10, 5, GetColor(0, 0, 255), FALSE);
}
