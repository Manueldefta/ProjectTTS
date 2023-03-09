#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void exit1()
{
    system("cls");
    gotoxy(41,1);
    printf("================================================\n");
    gotoxy(41,2);
    printf("|                                              |\n");
    gotoxy(41,3);
    printf("|                TERIIMA KASIH                 |\n");
    gotoxy(41,4);
    printf("|                                              |\n");
    gotoxy(41,5);
    printf("================================================\n");
    gotoxy(41,6);
    printf("| Author :                                     |\n");
    gotoxy(41,7);
    printf("|                                              |\n");
    gotoxy(41,8);
    printf("| Christopher Arvin Tungady 672022279          |\n");
    gotoxy(41,9);
    printf("| Eugene Tanuwijaya 672022275                  |\n");
    gotoxy(41,10);
    printf("| Emanuell Devtavalandra Rahmanto 672022091    |\n");
    gotoxy(41,11);
    printf("================================================\n");
    getch();
    exit(0);
}
int main()
{
    system("color 09");
    exit1();
    return 0;
}


