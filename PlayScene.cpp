#include "PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Engine/SceneManager.h"
//コンストラクタ
//引数：parent  親オブジェクト（SceneManager）
//メンバー変数の初期化はコンストラクタで
PlayScene::PlayScene(GameObject* parent) :GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	
	Instantiate<Player>(this);
	//Instantiate<Bullet>(this);
	for (int i = 0;i < 15;i++) {
		Instantiate<Enemy>(this);
	}
}

void PlayScene::Update()
{
	if (FindObject("Enemy")==nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
		//ot_.position_ = { ot_.position_.x,ot_.position_.y + (-0.5f) * sinf(time),10.0f};
}

void PlayScene::Draw()
{
	
	
}

void PlayScene::Release()
{
}
