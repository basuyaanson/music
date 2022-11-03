#include "ress.h"
#include"musplayer.h"

int main()
{
    srand((unsigned int)time(nullptr));//¹ê²{ÀH¾÷
    musicplayer* p = new musicplayer;

    while (1)
    {
        p->menu();
        p->keydown();
        system("cls");
    }
    return 0;
}

