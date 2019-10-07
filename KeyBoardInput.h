#pragma once
#include <Windows.h>
#include <WinUser.h>
class KeyBoardInput
{
public:
	KeyBoardInput();
	~KeyBoardInput();
	//現在の入力状況を取得
	void SetInputState();
	//1フレーム前の入力情報を格納
	void SetPreBuffer();
	//押している
	BOOL GetKey(int key);
	//押された瞬間
	BOOL GetKeyDown(int key);
	//離された瞬間
	BOOL GetKeyUp(int key);
private:
	//この値との論理積をとると入力をとれる
	const int isInputNum = 0x80;
	//現在の入力状況を受け取るバッファ
	BYTE mInputByteBuffer[256];
	//1フレーム前の入力状況を保持するバッファ
	BYTE mPreInputByteBuffer[256];
};

