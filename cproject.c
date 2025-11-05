#include <stdio.h>
#include <time.h>

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
    char* wbs;
    char* name;
    char* desc;
    char* worker;
    int hours;
    struct tm start;
    struct tm end;
    int level;
    int dep;
    enum rule rule;
    int manu;  
};

int main()
{
    struct task task = {.id = 1};
}