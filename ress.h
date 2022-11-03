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
//���ָ귽
class Res
{
public:
    //static Res* getres();//���ѤޥΨӳX�ݼƾڡ]��ҼҦ��^
    static bool ismusic(const string& name);//�P�_���O�_�����֤��(.mp3)
    static string getnewname(string name);//�p�G���֤�󦳪Ů�,������_
    static void traverfile(); //�M�����
    static map<int, string> music; //�ϥήe���x�s���֤��
    Res();
private:

};

map<int, string>Res::music;
//�P�_���O�_�����֤��(.mp3)
bool Res::ismusic(const string& name)
{
    int lenght = name.size();
    //substr��ơA�Ψ��^���ɮ׫᭱���r
    return name.substr(lenght - 4) == ".mp3";
}
//�p�G���֤�󦳪Ů�,������_
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
//�M�����
void Res::traverfile()
{
    system("color 70");
    cout << "�п�J���֮w��󧨸��|:";
    string resroot;
    cin >> resroot;


    filesystem::path ress(resroot);
    //�P�w���|�O�_�s�b�����ɮ�
    if (!filesystem::exists(ress))
    {
        cout << "����쭵���ɮ�......" << endl;
        exit(0);
    }

    //�o���e���|�U�Ҧ����֪������|
    int pos = 1;//���C�ӭ��֤��t�ӧǸ�
    string oldname;
    string newname;
    //�ϥέ��N���M�����
    filesystem::directory_iterator begin(ress);
    for (filesystem::directory_iterator end; begin != end; ++begin)
    {
        if (!filesystem::is_directory(begin->path()))//�P�_�O�_�O��Ƨ��A�O�N���L
        {
            //������|�A������W���ରstring�A�P�_���O�_�����֤��(.mp3)
            if (ismusic(begin->path().filename().string()))
            {
                //�p�G���֤�󦳪Ů�,������_
                oldname = resroot + "/" + begin->path().filename().string();
                newname = getnewname(oldname);
                int resulf = rename(oldname.c_str(), newname.c_str());//.c_str():�Nstring�ഫ��c�y����str
                music[pos++] = newname;

            }
        }
    }
    cout << "���֮w�[�����\....." << endl;
}
//�ϥΫغc�l��l��
Res::Res()
{
    cout << "��l�ƭ��֮w.....\n\n";
    traverfile();
}