#include <graphics.h>
#include <math.h>
void bresenhams(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err;
    if (dy < dx)
    {
        err = 2 * dy - dx;
        while (x1 != x2)
        {
            putpixel(x1, y1, RED);
            if (err >= 0)
            {
                y1 += sy;
                err -= 2 * dx;
            }
            x1 += sx;
            err += 2 * dy;
        }
    }
    else
    {
        err = 2 * dx - dy;
        while (y1 != y2)
        {
            putpixel(x1, y1, RED);
            if (err >= 0)
            {
                x1 += sx;
                err -= 2 * dy;
            }
            y1 += sy;
            err += 2 * dx;
        }
    }
    putpixel(x1, y1, RED);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    bresenhams(10, 10, 200, 200);

    getch();
    closegraph();
    return 0;
}
