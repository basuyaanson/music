#include "common.h"
#include"musicplayer.h"

int main()
{
    srand((unsigned int)time(nullptr));//��{�H��(�H�ۮɶ��ܤ�)
    musicplayer* p = new musicplayer;

    while (1)
    {

        p->menu();
        p->keydown();

        system("cls");

    }
    return 0;
}


