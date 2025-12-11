#pragma once
#include "../Library/GameObject.h"

class Bird : public GameObject
{
public:
	Bird();
	Bird(int sx, int sy);
	~Bird();
	void Update() override;
	void Draw() override;
	bool IsHit(float tx, float ty, float rad);
private:
	int hImage;
	VECTOR3 position;
	VECTOR3 velocity;
//	float x, y;

	int deadCounter; // >0ければカウントダウン
};