#pragma once
#include <Windows.h>
#include <WinUser.h>
class KeyBoardInput
{
public:
	KeyBoardInput();
	~KeyBoardInput();
	//���݂̓��͏󋵂��擾
	void SetInputState();
	//1�t���[���O�̓��͏����i�[
	void SetPreBuffer();
	//�����Ă���
	BOOL GetKey(int key);
	//�����ꂽ�u��
	BOOL GetKeyDown(int key);
	//�����ꂽ�u��
	BOOL GetKeyUp(int key);
private:
	//���̒l�Ƃ̘_���ς��Ƃ�Ɠ��͂��Ƃ��
	const int isInputNum = 0x80;
	//���݂̓��͏󋵂��󂯎��o�b�t�@
	BYTE mInputByteBuffer[256];
	//1�t���[���O�̓��͏󋵂�ێ�����o�b�t�@
	BYTE mPreInputByteBuffer[256];
};

