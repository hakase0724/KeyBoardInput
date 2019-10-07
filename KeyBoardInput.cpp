#include "KeyBoardInput.h"

KeyBoardInput::KeyBoardInput() : mInputByteBuffer{}, mPreInputByteBuffer{} {}

KeyBoardInput::~KeyBoardInput() {}


void KeyBoardInput::SetInputState()
{
	if (!GetKeyboardState(mInputByteBuffer)) {}
}

void KeyBoardInput::SetPreBuffer()
{
	for (int i = 0; i < 256; i++)
	{
		mPreInputByteBuffer[i] = mInputByteBuffer[i];
	}
}

BOOL KeyBoardInput::GetKey(int key)
{
	if (mInputByteBuffer[key] & isInputNum) return TRUE;
	else return FALSE;
}

BOOL KeyBoardInput::GetKeyDown(int key)
{
	if (mInputByteBuffer[key] & isInputNum)
	{
		if (!(mPreInputByteBuffer[key] & isInputNum)) return TRUE;
	}
	return FALSE;
}

BOOL KeyBoardInput::GetKeyUp(int key)
{
	if (!(mInputByteBuffer[key] & isInputNum))
	{
		if (mPreInputByteBuffer[key] & isInputNum) return TRUE;
	}
	return FALSE;
}
