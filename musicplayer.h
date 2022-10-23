#pragma once

#include"common.h"

//播放器類
class musicplayer
{
public:
    enum CMD { open, play, pause, resume, close };//列舉型別
    musicplayer();
    void menu(); //介面
    void keydown();  //按鍵指令
    void showmusic();  //顯示歌單
    void playmusic(); //播放
    void pausemusic(); //暫停
    void resumemusic();//繼續
    void next(); //下一首
    void pre();//上一首
    void random();//隨機播放
    void asciiart();////ASCII藝術圖形(美編用)
private:
    int curidex;  //當前選擇的音樂
    vector<string> cmd; //將按鍵命令轉為字符串
};
