#include "ress.h"
#include"musplayer.h"

int main()
{
    srand((unsigned int)time(nullptr));//��{�H��
    musicplayer* p = new musicplayer;

    while (1)
    {
        p->menu();
        p->keydown();
        system("cls");
    }
    return 0;
}

