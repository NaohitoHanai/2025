#include "Player.h"
#include "Field.h"

static const float Gravity = 0.2;
static const float V0 = -10.0;

// コンストラクター
// 最初に１回だけ必ず呼ばれる
Player::Player()
{
	hImage = LoadGraph("data/image/aoi.png");
	x = 200;
//	y = 0;
//	velocity = 0;
	y = 500;
	velocity = V0;
	onGround = false;
}

// デストラクター
// 最後に１回だけ必ず呼ばれる
Player::~Player()
{
}

// 計算・処理するところ
void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_D)) {
		x += 2;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		x -= 2;
	}
	if (onGround == true) {
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			velocity = V0;
		}
	}

	y += velocity;
	velocity += Gravity;
	Field* field = FindGameObject<Field>();
	int ret = field->HitCheck(x, y + 64);
	if (ret > 0) {
		y -= ret;
		velocity = 0;
		onGround = true;
	} else {
		onGround = false;
	}
}

// 表示するところ
void Player::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, 1);
}
