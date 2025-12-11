#pragma once
#include "../Library/GameObject.h"

class Common : public GameObject
{
public:
	Common();
	void Update() override;

	int stageNumber;
	int score;
	int hiScore;
	bool noDead;
};