#pragma once

#include "Scene.h"

class CKeyEventWorldMap : public CSceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CKeyEventWorldMap(LPSCENE s) :CSceneKeyHandler(s) {};
};
