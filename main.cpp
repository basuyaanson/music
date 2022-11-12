#include "res.h"
#include"musicplayer.h"

int main()
{
    srand((unsigned int)time(nullptr));//實現隨機(隨著時間變化)
    musicplayer* p = new musicplayer;

    while (1)
    {
        p->menu();
        p->keydown();
        system("cls");
    }
    return 0;
}
