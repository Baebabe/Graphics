#include <graphics.h>

int computeCode(float x, float y, float xmin, float ymin, float xmax, float ymax) {
    int code = 0;
    if (y > ymax) code |= 8; // Top
    if (y < ymin) code |= 4; // Bottom
    if (x > xmax) code |= 2; // Right
    if (x < xmin) code |= 1; // Left
    return code;
}

void cohenSutherland(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    while (1) {
        if (!(code1 | code2)) {
            setcolor(RED);
            rectangle(xmin, ymin, xmax, ymax);
            setcolor(WHITE);
            line(x1, y1, x2, y2);
            return;
        } else if (code1 & code2) {
            printf("Line is outside the window\n");
            return;
        } else {
            float x, y;
            int outCode = code1 ? code1 : code2;

            if (outCode & 8) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (outCode & 4) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (outCode & 2) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outCode == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    float x1 = 100, y1 = 20, x2 = 200, y2 = 400;
    float xmin = 50, ymin = 50, xmax = 300, ymax = 300;
    initgraph(&gd, &gm, NULL);
    cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    getch();
    closegraph();
    return 0;
}
