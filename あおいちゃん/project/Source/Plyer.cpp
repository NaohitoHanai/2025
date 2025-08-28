#include "Player.h"
#include "Field.h"

static const float Gravity = 0.2;
static const float V0 = -10.0;

// �R���X�g���N�^�[
// �ŏ��ɂP�񂾂��K���Ă΂��
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

// �f�X�g���N�^�[
// �Ō�ɂP�񂾂��K���Ă΂��
Player::~Player()
{
}

// �v�Z�E��������Ƃ���
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

// �\������Ƃ���
void Player::Draw()
{
	DrawRectGraph(x, y, 0, 0, 64, 64, hImage, 1);
}
