#pragma once
#include "DxLib.h"

void dmsg(LPCSTR pszFormat, ...);

#define LONG_PUSH_TIME	150
#define FPS_AVE			60
#define FPS				60

#define WINDOW_SIZE_X	1280	//�E�B���h�E�T�C�Y�i���j
#define WINDOW_SIZE_Y	720		//�E�B���h�E�T�C�Y�i�c�j
#define GRAPH_SIZE_X	1920	//�Q�[����ł̕`��T�C�Y�i���j
#define GRAPH_SIZE_Y	1080	//�Q�[����ł̕`��T�C�Y�i�c�j


#define LINE_WIDTH		28
#define _BUTTON_SIZE	270
#define BUTTON_SIZE		(_BUTTON_SIZE - LINE_WIDTH*2)
#define JACKET_IMG_SIZE	60
#define LINE_TOP_WIDTH	150
#define DEF_BACK_COLOR	GetColor(255,255,255)
#define PI				3.1415926535897932384626433832795f
#define FADE_IN			(0)
#define FADE_OUT		(1)

enum SCENE_STATE{

	scene_continue,
	scene_finish

};


class SCREEN_DATA{

public:
	struct{
		int img_handle;
		int x_size;
		int y_size;
	}top;

	struct{
		int img_handle;
		int x_size;
		int y_size;
	}bottom;

	int wave_y;
};
