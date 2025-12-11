#pragma once
#include "../Library/GameObject.h"

class Stone : public GameObject
{
public:
	Stone();
	Stone(int sx, int sy, float vx, float vy);
	~Stone();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position; // 座標
	VECTOR3 velocity; // ベクトル
//	float x, y;
//	float velocityX, velocityY;
};