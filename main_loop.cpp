#include "DxLib.h"
#include "main_loop.h"
#include "system_tools.h"
#include "fps_control.h"
#include "draw_control.h"

#include <windows.h>
#include <stdio.h>

#if defined(_DEBUG) || defined(DEBUG)
// Debug�̂Ƃ�
#define TRACE(x)   OutputDebugString(x)
#define TRACE0(x)   OutputDebugString(x)
#define TRACE1(x, a)            MyOutputDebugString(x, a)
#define TRACE2(x, a, b)         MyOutputDebugString(x, a, b)
#define TRACE3(x, a, b, c)      MyOutputDebugString(x, a, b, c)
#define TRACE4(x, a, b, c, d)   MyOutputDebugString(x, a, b, c, d)

#else
// Release�̂Ƃ�
#define TRACE(x)
#define TRACE0(x)
#define TRACE1(x, a)
#define TRACE2(x, a, b)
#define TRACE3(x, a, b, c)
#define TRACE4(x, a, b, c, d)
#endif

void MyOutputDebugString(LPCSTR pszFormat, ...)
{
	va_list	argp;
	char pszBuf[256];
	va_start(argp, pszFormat);
	vsprintf_s(pszBuf,sizeof(pszBuf), pszFormat, argp);
	va_end(argp);
	OutputDebugString(pszBuf);
}

void dmsg(LPCSTR pszFormat, ...){
	va_list	argp;
	char pszBuf[256];
	va_start(argp, pszFormat);
	vsprintf_s(pszBuf, pszFormat, argp);
	va_end(argp);
	MessageBox(NULL, pszBuf, "", MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//--------------------------------------------�����ݒ肱������
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
	SetWindowSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	SetWindowStyleMode(9);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("initializing...");
	ChangeWindowMode(true);
	SetUseDateNameLogFile(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetWindowSizeChangeEnableFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetOutApplicationLogValidFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetMainWindowText("jubeat lab.");
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	OutputDebugString("game start.\n");
	//--------------------------------------------�����ݒ肱���܂�



	//--------------------------------------------���C���Q�[��������������
	draw_control c_loop;
	fps_control c_fps;

	while (!ProcessMessage() && !ClearDrawScreen() && keyBuff[KEY_INPUT_ESCAPE] == 0)
	{
		getKey();
		c_fps.Update();
		c_loop.processing(c_fps.get_fps());
		ScreenFlip();
		c_fps.Wait();
	}
	//--------------------------------------------���C���Q�[�����������܂�



	DxLib_End();
	OutputDebugString("game end.\n");
	return 0;
}
