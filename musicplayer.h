#pragma once

#include"common.h"

//������
class musicplayer
{
public:
    enum CMD { open, play, pause, resume, close };//�C�|���O
    musicplayer();
    void menu(); //����
    void keydown();  //������O
    void showmusic();  //��ܺq��
    void playmusic(); //����
    void pausemusic(); //�Ȱ�
    void resumemusic();//�~��
    void next(); //�U�@��
    void pre();//�W�@��
    void random();//�H������
    void asciiart();////ASCII���N�ϧ�(���s��)
private:
    int curidex;  //��e��ܪ�����
    vector<string> cmd; //�N����R�O�ର�r�Ŧ�
};
