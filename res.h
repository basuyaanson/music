#pragma once

#include"common.h"


//���ָ귽 ��ҳ]�p�Ҧ�
class Res
{
public:
    static Res* getres();//���ѳX�ݼƾ�
    static bool ismusic(const string& name);//�P�_���O�_�����֤��(.mp3)
    static string getnewname(string name);//�p�G���֤�󦳪Ů�,������_
    static void traverfile(); //�M�����
    static map<int, string> music; //�Ʋ� STL
private:
    Res();
};

