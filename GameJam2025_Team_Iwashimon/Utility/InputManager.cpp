#include "InputManager.h"
#include "DxLib.h"

InputControl* InputControl::instance = nullptr;

//インスタンスを取得
InputControl* InputControl::GetInstance()
{
	//インスタンスが生成されていなければ
	if (instance == nullptr)
	{
		//インスタンスを生成
		instance = new InputControl();
	}

	return instance;
}

//インスタンスを削除
void InputControl::DeleteInstance()
{
	//インスタンスが生成されていれば
	if (instance != nullptr)
	{
		//インスタンスを削除
		delete instance;
		//インスタンスをnullptrにする
		instance = nullptr;
	}
}

//2種類の入力情報の更新
void InputControl::Update()
{
	//キー入力更新
	KeyInputUpdate();
	//GamePad入力更新
	PadInputUpdate();
}

//キー入力更新
void InputControl::KeyInputUpdate()
{
	//前回の入力値を更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEY_CODE_MAX));

	//全キーの押下状態を取得する
	GetHitKeyStateAll(now_key);
}
//キーを押した瞬間を取得
bool InputControl::GetKeyPress(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == TRUE
		&& old_key[key_code] == FALSE);
}
//キーを押し続けている間取得
bool InputControl::GetKeyHeld(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == TRUE
		&& old_key[key_code] == TRUE);
}
//キーを離した瞬間を取得
bool InputControl::GetKeyRelease(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == FALSE
		&& old_key[key_code] == TRUE);
}
//キーの入力範囲をチェック
bool InputControl::CheckKeyCodeRange(int key_code) const
{
	return (0 <= key_code
		&& key_code < D_KEY_CODE_MAX);
}

void InputControl::PadInputUpdate()
{
	//前回の入力状態を更新
	memcpy(old_button, now_button, (sizeof(char) * D_KEY_CODE_MAX));
	XINPUT_STATE xinput{};

	//入力状態を取得
	GetJoypadXInputState(DX_INPUT_PAD1, &xinput);

	//ボタンの押下状態の更新
	for (int i = 0; i < D_BUTTON_CODE_MAX; i++)
	{
		if (xinput.Buttons[i] == TRUE)
		{
			now_button[i] = TRUE;
		}
		else
		{
			now_button[i] = FALSE;
		}
	}

	//左スティックの入力更新
	l_stick_thumb.x = StickNormalize(xinput.ThumbLX);
	l_stick_thumb.y = StickNormalize(xinput.ThumbLY);

	//右スティックの入力更新
	r_stick_thumb.x = StickNormalize(xinput.ThumbRX);
	r_stick_thumb.y = StickNormalize(xinput.ThumbRY);

	//左右トリガーの押し込み具合を取得
	trigger[0] = TriggerNormalize(xinput.LeftTrigger);
	trigger[1] = TriggerNormalize(xinput.RightTrigger);
}
//ボタンを押した瞬間を取得
bool InputControl::GetButtonPress(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == TRUE
		&& old_button[button_code] == FALSE);
}
//ボタンを押し続けている間取得
bool InputControl::GetButtonHeld(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == TRUE
		&& old_button[button_code] == TRUE);
}
//ボタンを離した瞬間を取得
bool InputControl::GetButtonRelease(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == FALSE
		&& old_button[button_code] == TRUE);
}
//左トリガーの値を取得
float InputControl::GetLTrigger() const
{
	return trigger[0];
}
//右トリガーの値を取得
float InputControl::GetRTrigger() const
{
	return trigger[1];
}
//左スティックの傾きの値を取得
Vector2D InputControl::GetLStickPos() const
{
	return l_stick_thumb;
}
//右スティックの傾きの値を取得
Vector2D InputControl::GetRStickPos() const
{
	return r_stick_thumb;
}
//ボタンの入力範囲をチェック
bool InputControl::CheckButtonCodeRange(int button_code) const
{
	return (0 <= button_code
		&& button_code < D_BUTTON_CODE_MAX);
}
//スティックの入力値を補正
float InputControl::StickNormalize(short tip_value) const
{
	/* スティックの値 「-32768 ～ 32767」の値を */
	/*「 -1.0f～1.0f」 の値が返ってくる様に除算を行う*/
	if (0 < tip_value)
	{
		return (static_cast<float>(tip_value) / static_cast<float>(SHRT_MAX));
	}
	else
	{
		return -(static_cast<float>(tip_value) / static_cast<float>(SHRT_MIN));
	}
}
//トリガーの入力値を補正
float InputControl::TriggerNormalize(unsigned int trigger_value) const
{
	/* トリガーの値 「0～255」の値を */
	/* 「0～1.0f」の値が返ってくるように除算する */
	if (0 < trigger_value)
	{
		return (static_cast<float>(trigger_value) / static_cast<float>(UCHAR_MAX));
	}
	else
	{
		return 0.0f;
	}
}
