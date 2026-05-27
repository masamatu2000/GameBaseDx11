#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"Bullet.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f,0.0f,20.0f };
	sc_= new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(sc_);
	IsLeft_ = rand() % 2;
	dir_ = (IsLeft_ == 0) ? 1 :-1;
}

void Enemy::Update()
{
	
	time_ += 0.025f;
	transform_.position_.x = 12.0f * sin(time_)*dir_;
	//tr_.position_.y = tr_.position_.y+(-0.5f) * sin(time);
	transform_.position_.z = 10.0f;
	transform_.rotate_ = { tr_.rotate_.x + 1.0f,tr_.rotate_.y + 1.0f,tr_.rotate_.z + 1.0f };
	transform_.scale_ = { 1.0f,1.0f,1.0f };
	if (sin(time_) == 1||sin(time_)==-1) {
		dir_ *= -1;
	}
}

void Enemy::Draw()
{
	if (hModel_ != -1) {
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		pTarget->KillMe();
		KillMe();
	}
}
