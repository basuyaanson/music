#include"res.h"

map<int, string>Res::music;

//提供訪問數據
Res* Res::getres()
{
    static Res* p = new Res;
    return p;
}

//判斷文件是否為音樂文件(.mp3)
bool Res::ismusic(const string& name)
{
    int lenght = name.size();
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
    //判定路徑是否存在音樂檔案
    filesystem::path ress(resroot);

    if (!filesystem::exists(ress))
    {
        cout << "未找到音樂檔案......" << endl;
        exit(0);
    }

    //得到當前路徑下所有音樂的文件路徑
    int pos = 1;
    string oldname;
    string newname;
    filesystem::directory_iterator begin(ress);
    for (filesystem::directory_iterator end; begin != end; ++begin)//遍歷文件
    {
        if (!filesystem::is_directory(begin->path()))//判定是否為.mp3(***會跳過當前路徑下的其他文件夾***)
        {
            if (ismusic(begin->path().filename().string()))// 判斷文件是否為音樂文件(.mp3)
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

//初始化音樂庫
Res::Res()
{
    cout << "初始化音樂庫.....\n\n";
    traverfile();
}
