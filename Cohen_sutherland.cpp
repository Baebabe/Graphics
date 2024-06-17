#include <graphics.h>
#include <math.h>



int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    getch();
    closegraph();
    return 0;
}