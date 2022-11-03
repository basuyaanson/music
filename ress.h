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
//音樂資源
class Res
{
public:
    //static Res* getres();//提供引用來訪問數據（單例模式）
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
    //substr函數，用來擷取檔案後面的字
    return name.substr(lenght - 4) == ".mp3";
}
//如果音樂文件有空格,替換為_
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
    system("color 70");
    cout << "請輸入音樂庫文件夾路徑:";
    string resroot;
    cin >> resroot;


    filesystem::path ress(resroot);
    //判定路徑是否存在音樂檔案
    if (!filesystem::exists(ress))
    {
        cout << "未找到音樂檔案......" << endl;
        exit(0);
    }

    //得到當前路徑下所有音樂的文件路徑
    int pos = 1;//給每個音樂文件配個序號
    string oldname;
    string newname;
    //使用迭代器遍歷文件
    filesystem::directory_iterator begin(ress);
    for (filesystem::directory_iterator end; begin != end; ++begin)
    {
        if (!filesystem::is_directory(begin->path()))//判斷是否是資料夾，是就跳過
        {
            //獲取路徑，獲取文件名並轉為string，判斷文件是否為音樂文件(.mp3)
            if (ismusic(begin->path().filename().string()))
            {
                //如果音樂文件有空格,替換為_
                oldname = resroot + "/" + begin->path().filename().string();
                newname = getnewname(oldname);
                int resulf = rename(oldname.c_str(), newname.c_str());//.c_str():將string轉換成c語言的str
                music[pos++] = newname;

            }
        }
    }
    cout << "音樂庫加載成功....." << endl;
}
//使用建構子初始化
Res::Res()
{
    cout << "初始化音樂庫.....\n\n";
    traverfile();
}