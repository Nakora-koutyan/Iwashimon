#pragma once
#include "Vector2D.h"

#define D_KEY_CODE_MAX (255)
#define D_BUTTON_CODE_MAX (255)

class InputControl
{
private:
	static InputControl* instance;

	//キー入力に関する変数
	char now_key[D_KEY_CODE_MAX]{};
	char old_key[D_KEY_CODE_MAX]{};

	//ボタン入力に関する変数
	char now_button[D_BUTTON_CODE_MAX]{};
	char old_button[D_BUTTON_CODE_MAX]{};

	//スティックの傾き度合を取得する変数
	Vector2D l_stick_thumb = Vector2D(0.0f);
	Vector2D r_stick_thumb = Vector2D(0.0f);
	//GamePadトリガーの値取得用変数
	float trigger[2];

private:
	InputControl() = default;

	//コピーコンストラクタ禁止
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;

public:
	~InputControl() = default;

public:
	//インスタンスを取得
	static InputControl* GetInstance();
	//インスタンスを削除
	static void DeleteInstance();

public:
	//2種類の入力情報の更新
	void Update();
public:

	//キーの入力処理に関する関数
	void KeyInputUpdate();

	bool GetKeyPress(int key_code)const;		//キーを押した瞬間を取得
	bool GetKeyHeld(int key_code)const;			//キーを押し続けている間取得
	bool GetKeyRelease(int key_code)const;		//キーを離した瞬間を取得

private:
	bool CheckKeyCodeRange(int key_code)const;	//キーの入力範囲をチェック

public:

	//GamePadの入力に関する更新
	void PadInputUpdate();

	bool GetButtonPress(int button_code)const;		//ボタンを押した瞬間を取得
	bool GetButtonHeld(int button_code)const;		//ボタンを押し続けている間取得
	bool GetButtonRelease(int button_code)const;	//ボタンを離した瞬間を取得

	float GetLTrigger()const;						//左トリガーの値を取得
	float GetRTrigger()const;						//右トリガーの値を取得

	Vector2D GetLStickPos()const;					//左スティックの傾きの値を取得
	Vector2D GetRStickPos()const;					//右スティックの傾きの値を取得

private:

	bool CheckButtonCodeRange(int button_code)const;	//ボタンの入力範囲をチェック

	/* スティックの値 「-32768 ～ 32767」の値を */
	/*「 - 1.0f～1.0f」 の値が返ってくる様に除算を行う */
	float StickNormalize(short tip_value)const;						//スティックの入力値を補正
	/* トリガーの値 「0～255」の値を */
	/* 「0～1.0f」の値が返ってくるように除算する */
	float TriggerNormalize(unsigned int trigger_value)const;		//トリガーの入力値を補正
};