#pragma once
#include "Engine/GameObject.h"
#include"Engine/SphereCollider.h"
class Bullet :
    public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	SphereCollider* GetCollider() { return sc_; }
private:
	int hModel_;
	float speed;
	Transform tr_;//アフィン変換のパラメータを保存
	float bx;
	SphereCollider* sc_;
};

