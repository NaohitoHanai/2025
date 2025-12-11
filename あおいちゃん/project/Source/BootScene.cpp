#include "BootScene.h"
#include "Common.h"
#include "Fader.h"

BootScene::BootScene()
{
	new Common();
	new Fader();
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TITLE"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦
}

void BootScene::Draw()
{
}
