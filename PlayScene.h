#pragma once
#include "Engine\\GameObject.h"
class PlayScene :
    public GameObject
{;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
private:
	int hModel_; //モデルのハンドル
	int hModel_2;
	int time_;//時間
	int spawnTimer;
	Transform ot_;//おでん用のトランスフォーム
	XMFLOAT3 CameraTargetPos;
};