#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Bullet.h"
Player::Player(GameObject* parent)
		//親のポインタと自分の名前
	:GameObject(parent,"Player"),hModel_(-1)
{
	
}

void Player::Initialize()
{
	hModel_ = Model::Load("SpaceShip.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.1f;
	}
	if (Input::IsKeyDown(DIK_SPACE)) {
		Bullet *pb=Instantiate<Bullet>(this->GetParent());
		pb->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
