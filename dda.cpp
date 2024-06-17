#include <graphics.h>
#include <math.h>
void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? dx : dy;
    int xin = dx / steps;
    int yin = dy / steps;
    int x = x1;
    int y = y1;
    for (int i = 0; i < steps; i++)
    {
        putpixel(round(x), round(y), RED);
        x += xin;
        y += yin;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    dda(10, 10, 200, 200);
    getch();
    closegraph();
    return 0;
}
