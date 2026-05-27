#include "Bullet.h"
#include"Engine/Model.h"
#include"Player.h"
#include"Enemy.h"
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1),speed(0.5f)
{

}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.5f,0.5f,0.5f };
	sc_ = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(sc_);
}

void Bullet::Update()
{
	transform_.position_.z += speed;
	Enemy* e =(Enemy*) FindObject("Enemy");
	if (e != nullptr) {
		if (sc_->IsHit(e->GetCollider())) {
			e->OnCollision(this);
		}
	}
	if (transform_.position_.z > 50.0f) {
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
