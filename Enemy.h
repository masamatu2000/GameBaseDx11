#pragma once
#include "Engine/GameObject.h"
#include"Engine/SphereCollider.h"
class Enemy :
    public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
	SphereCollider* GetCollider() { return sc_; }
private:
	
	int hModel_;
	Transform tr_;//アフィン変換のパラメータを保
	SphereCollider* sc_;
	float count_ = 0.0f;
	float dir_ = 1.0;
	float time_ = 0.0f;
	bool IsLeft_;
};

