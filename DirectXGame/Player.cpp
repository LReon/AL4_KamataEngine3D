#include <cassert>
#include <ImGuiManager.h>
#include "Player.h"
#include "affine.h"


void Player::Initialize(Model* model, uint32_t textureHandle) {

	// シングルインスタンスを取得する
	input_ = Input::GetInstance();

	// NULLポインタチェック
	assert(model);
	// メンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;

	// ワールド変換の初期化
	worldTransform_.Initialize();

}

void Player::Update() {

	

	// キャラクターの移動ベクトル
	
	float slider[3] = {0.0f, 0.0f, 0.0f};

	

	// キャラクターの移動の速さ
	const float kCharacterSpeedX = 0.1f;
	const float kCharacterSpeedY = 0.1f;
	const float kCharacterSpeedZ = 0.1f;
	
	// 押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A)) {
		
		worldTransform_.translation_.x -= kCharacterSpeedX;
	
	} else if (input_->PushKey(DIK_D)) {
		
		worldTransform_.translation_.x += kCharacterSpeedX;
	}
	if (input_->PushKey(DIK_W)) {
		
		worldTransform_.translation_.y += kCharacterSpeedY;

	} else if (input_->PushKey(DIK_S)) {
		
		worldTransform_.translation_.y -= kCharacterSpeedY;
	}
	if (input_->PushKey(DIK_Q)) {

		worldTransform_.translation_.z += kCharacterSpeedZ;

	} else if (input_->PushKey(DIK_E)) {

		worldTransform_.translation_.z -= kCharacterSpeedZ;
	}


	slider[0] = worldTransform_.translation_.x;
	slider[1] = worldTransform_.translation_.y;
	slider[2] = worldTransform_.translation_.z;

	ImGui::Begin("Debug");
	ImGui::Text("X = AD Y = WS Z = QE");
	ImGui::InputFloat3("player", slider);
	ImGui::End();


	worldTransform_.translation_.x = slider[0];
	worldTransform_.translation_.y = slider[1];
	worldTransform_.translation_.z = slider[2];

	

	


	// 座標移動(ベクトルの加算)
	
	



	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	

	
}

void Player::Draw(ViewProjection& viewProjection) {

	// 3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection, textureHandle_);

}
