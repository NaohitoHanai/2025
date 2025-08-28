#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	float x, y;
	float velocity;
	bool onGround;
};