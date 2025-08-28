#pragma once
#include "../Library/GameObject.h"

class Field : public GameObject
{
public:
	Field();
	~Field();
	void Update() override;
	void Draw() override;

	int HitCheck(int px, int py);
private:
	int hImage;
	float x, y;
};