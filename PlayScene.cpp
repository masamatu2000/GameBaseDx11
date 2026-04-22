#include "PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
//コンストラクタ
//引数：parent  親オブジェクト（SceneManager）
//メンバー変数の初期化はコンストラクタで
PlayScene::PlayScene(GameObject* parent) :GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("../Assets/Oden.fbx");
	assert(hModel_ >=0);
}

void PlayScene::Update()
{
	static float pauseTime = 2.0f;
	static bool isPause = false;
	if (Input::IsKeyDown(DIK_SPACE)) {
		pauseTime -= 0.1f;
		isPause = true;
		if (pauseTime < 0.0f) {
			isPause = false;
			pauseTime = 2.0f;
		}
	}
	if(!isPause){
		static float count = 0.0f;
		static float dir = 1.0;
		static float time = 0.0f;
		time += 0.1f;
		count += 0.1f * dir;
		ot_.rotate_ = { ot_.rotate_.x + 1.0f,ot_.rotate_.y + 1.0f,ot_.rotate_.z + 1.0f };
		ot_.scale_ = { 1.0f,1.0f,2.0f };
		ot_.position_ = { count,ot_.position_.y + (-0.5f) * sinf(time),10.0f };
		if (count > 10 || count < -10)
			dir *= -1;
	}
	else {

	}
}

void PlayScene::Draw()
{
	
	if (hModel_ != -1) {
		Model::SetTransform(hModel_,ot_);
		Model::Draw(hModel_);
	}
}

void PlayScene::Release()
{
}
