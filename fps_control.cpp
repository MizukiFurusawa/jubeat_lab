#pragma once
#include "main_loop.h"
#include "fps_control.h"
#include <DxLib.h>



fps_control::fps_control(){
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

bool fps_control::Update(){
	if (mCount == 0){ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == FPS){ //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)FPS_AVE);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void fps_control::Wait(){
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0){
		Sleep(waitTime);	//�ҋ@
	}
}

void fps_control::Draw(){
	DrawFormatString(10, 10, GetColor(255, 255, 255), "%04.1f", mFps);
}


float fps_control::get_fps(){
	return mFps;
}
