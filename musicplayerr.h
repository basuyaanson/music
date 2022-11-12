#pragma once
#include <iostream>
#include <string>
#include <map> 
#include<ctime>
#include<cstdlib>
#include<filesystem>
#include <vector>
#include <cstdio>
#include<Windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
//音樂資源類 使用靜態成員，讓類外可以使用
class Res
{
public:
    static bool ismusic(const string& name);//判斷文件是否為音樂文件(.mp3)
    static string getnewname(string name);//如果音樂文件有空格,替換為_
    static void traverfile(); //遍歷文件夾
    static map<int, string> music; //使用容器儲存音樂文件
    Res();
private:
};

map<int, string>Res::music;

//判斷文件是否為音樂文件(.mp3)
bool Res::ismusic(const string& name)
{
    int lenght = name.size();
    return name.substr(lenght - 4) == ".mp3"; //substr函數，用來擷取檔案後面的字
}
//遍歷音樂名稱，如果有空格，替換為_
string Res::getnewname(string name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == ' ')
        {
            name[i] = '_';
        }
    }
    return name;
}
//遍歷文件夾
void Res::traverfile()
{ 
    cout << "初始化音樂庫.....\n\n";
    cout << "請輸入音樂庫文件夾路徑:";
    string resroot;
    cin >> resroot;

    filesystem::path ress(resroot);
    //判定路徑是否存在
    if (!filesystem::exists(ress))
    {
        cout << "未找到音樂檔案......" << endl;
        exit(0);
    }

    int pos = 1;//音樂文件序號
    string oldname;
    string newname;
    //使用迭代器遍歷文件
    filesystem::directory_iterator begin(ress);
    for (filesystem::directory_iterator end; begin != end; ++begin)
    {
        if (!filesystem::is_directory(begin->path()))//判斷是否是資料夾，否就繼續
        {
            //判斷文件是否為音樂文件(.mp3)
            if (ismusic(begin->path().filename().string()))
            {
                //獲取文件名並轉為string
                oldname = resroot + "/" + begin->path().filename().string();
                newname = getnewname(oldname);//如果音樂文件有空格,替換為_
                int resulf = rename(oldname.c_str(), newname.c_str());// 使用rename 重新命名  ; .c_str():將string轉換成c語言的str
                music[pos++] = newname;

            }
        }
    }
    cout << "音樂庫加載成功....." << endl;
}

Res::Res()
{
}
