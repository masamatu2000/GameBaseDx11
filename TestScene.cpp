#include "TestScene.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
#include"Engine/Image.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),hTitlePic_(-1)
{
}

//初期化
void TestScene::Initialize()
{

	hTitlePic_ = Image::Load("../Assets/Title.png");
	assert(hTitlePic_ >-1);
	
}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	if (hTitlePic_ != -1) {
		transform_.scale_ = { 1.5f,1.5f,1.0f };
		Image::SetTransform(hTitlePic_,transform_);
		Image::Draw(hTitlePic_);
	}
}

//開放
void TestScene::Release()
{
}
