#include <graphics.h>
#include <math.h>

void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, BLUE);
    putpixel(xc + x, yc - y, BLUE);
    putpixel(xc - x, yc - y, WHITE);
}

void Mid_pointellipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;
    float p1 = ry * ry - (rx * rx * ry) + (0.25 * rx * rx);
    while ((2 * ry * ry * x) < (2 * rx * rx * y)) {
        plotEllipsePoints(xc, yc, x, y);
        x++;
        if (p1 < 0) {
            p1 += (2 * ry * ry * x) + (ry * ry);
        } else {
            y--;
            p1 += (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
    }

    float p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - (rx * rx * ry * ry);
    while (y > 0) {
        plotEllipsePoints(xc, yc, x, y);
        y--;
        if (p2 > 0) {
            p2 += rx * rx - (2 * rx * rx * y);
        } else {
            x++;
            p2 += (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Mid_pointellipse(200, 200, 100, 50);
    getch();
    closegraph();
    return 0;
}

