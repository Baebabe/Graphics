#include <graphics.h>
#include <math.h>

void plotCirclePoints(int x1, int y1, int x, int y){
    putpixel(x1 + x, y1 + y, RED);
    delay(10);
    putpixel(x1 - x, y1 + y, RED);
    delay(10);
    putpixel(x1 + x, y1 - y, RED);
    delay(10);
    putpixel(x1 - x, y1 - y, RED);
    delay(10);
    putpixel(x1 + y, y1 + x, RED);
    delay(10);
    putpixel(x1 - y, y1 + x, RED);
    delay(10);
    putpixel(x1 + y, y1 - x, RED);
    delay(10);
    putpixel(x1 - y, y1 - x, RED);
    delay(10);
}


void Mid_pointcircle(int x1, int y1, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r; 

    plotCirclePoints(x1, y1, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(x1, y1, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Mid_pointcircle(100, 100, 50);

    getch();
    closegraph();
    return 0;
}