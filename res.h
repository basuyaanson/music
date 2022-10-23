#pragma once

#include"common.h"


//音樂資源 單例設計模式
class Res
{
public:
    static Res* getres();//提供訪問數據
    static bool ismusic(const string& name);//判斷文件是否為音樂文件(.mp3)
    static string getnewname(string name);//如果音樂文件有空格,替換為_
    static void traverfile(); //遍歷文件夾
    static map<int, string> music; //數組 STL
private:
    Res();
};

