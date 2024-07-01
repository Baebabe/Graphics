#include <graphics.h>
#include <stdio.h>

void liangBarskyClip(float x0, float y0, float x1, float y1, float xmin, float ymin, float xmax, float ymax)
{
    float dx = x1 - x0, dy = y1 - y0;
    float p[] = {-dx, dx, -dy, dy};
    float q[] = {x0 - xmin, xmax - x0, y0 - ymin, ymax - y0};
    float t0 = 0.0, t1 = 1.0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                printf("Line is outside the window\n");
                return;
            }
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0 && t > t0) {
                t0 = t;
            } else if (p[i] > 0 && t < t1) {
                t1 = t;
            }
        }
    }

    if (t0 > t1) {
        printf("Line is outside the window\n");
        return;
    }

    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(WHITE);
    line(x0 + t0 * dx, y0 + t0 * dy, x0 + t1 * dx, y0 + t1 * dy);
}

int main()
{
    int gd = DETECT, gm;
    float x0 = 100, y0 = 150, x1 = 400, y1 = 250;
    float xmin = 50, ymin = 50, xmax = 300, ymax = 300;   
    initgraph(&gd, &gm, NULL);
    liangBarskyClip(x0, y0, x1, y1, xmin, ymin, xmax, ymax);
    getch();
    closegraph();
    return 0;
}

