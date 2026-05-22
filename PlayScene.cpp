#include "PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"

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
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	
		
		//ot_.position_ = { ot_.position_.x,ot_.position_.y + (-0.5f) * sinf(time),10.0f};
}

void PlayScene::Draw()
{
	
	
}

void PlayScene::Release()
{
}
