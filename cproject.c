#include <stdio.h>
#include <time.h>
#include <string.h>

#include <conio.h>

enum status
{
    YET,
    WIP,
    DONE
};

enum rule
{
    SS,
    SF,
    FS,
    FF
};

struct task
{
    enum status status;
    int id;
    char wbs[8];
    char name[64];
    char worker[16];
    int hours;
    struct tm start;
    struct tm end;
    int level;
    int dep;
    enum rule rule;
    int manu;
};

void move_cursor(int key, int *row, int *col)
{
    switch (key)
    {
    case 72:
        printf("\e[1A");

        break;

    case 75:
        printf("\e[1D");
        break;

    case 77:
        printf("\e[1C");
        break;

    case 80:
        printf("\e[1B");
        break;

    default:
        break;
    }
}

int main()
{
    int ch;
    int row = 0;
    int col = 0;
    struct task tasks[1024] = {0};
    printf("\e[?1049h");
    printf("\e[0;0H");
    while (1) {
        ch = _getch();
        switch (ch)
        {
        case 0:
        case 0xE0:
            ch = _getch();
            move_cursor(ch, &row, &col);
            break;

        case 'q':
            printf("\e[?1049l");
            return 0;

        default:
            break;
        }
    }
}