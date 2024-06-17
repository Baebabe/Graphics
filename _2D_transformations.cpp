#include <graphics.h>
#include <math.h>
#include <cmath>
#define M_PI 3.14159265
void matrix_multiplication(float A[3][3], float P[3], float Q[3]) {
    for (int i = 0; i < 3; i++) {
        Q[i] = 0; 
        for (int j = 0; j < 3; j++) {
            Q[i] += A[i][j] * P[j];
        }
    }
}

void translate(float x1, float y1, float x2, float y2, float x3, float y3, float tx, float ty) {
    float A[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };
    
    float B1[3] = {x1, y1, 1};
    float B2[3] = {x2, y2, 1};
    float B3[3] = {x3, y3, 1};  
    float C1[3], C2[3], C3[3];
    
    matrix_multiplication(A, B1, C1);
    matrix_multiplication(A, B2, C2);
    matrix_multiplication(A, B3, C3);
    
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    setcolor(GREEN);
    line(C1[0], C1[1], C2[0], C2[1]);
    line(C2[0], C2[1], C3[0], C3[1]);
    line(C3[0], C3[1], C1[0], C1[1]);
}

// void rotate(float x1, float y1, float x2, float y2, float x3, float y3, double thetad) {
//     double theta = thetad * (M_PI / 180.0);
//     float a=cos(theta);
//     float b= sin(theta);
//     float A[3][3] = {
//         {a, -b, 0},
//         {b, a, 0},
//         {0, 0, 1}
//     };
    
//     float B1[3] = {x1, y1, 1};
//     float B2[3] = {x2, y2, 1};
//     float B3[3] = {x3, y3, 1};
    
//     float C1[3], C2[3], C3[3];
    
//     matrix_multiplication(A, B1, C1);
//     matrix_multiplication(A, B2, C2);
//     matrix_multiplication(A, B3, C3);
    
//     setcolor(RED);
//     line(x1, y1, x2, y2);
//     line(x2, y2, x3, y3);
//     line(x3, y3, x1, y1);
    
//     setcolor(GREEN);
//     line(C1[0], C1[1], C2[0], C2[1]);
//     line(C2[0], C2[1], C3[0], C3[1]);
//     line(C3[0], C3[1], C1[0], C1[1]);
// }

void rotate(float x1, float y1, float x2, float y2, float x3, float y3, double thetad) {

    float cx = (x1 + x2 + x3) / 3;
    float cy = (y1 + y2 + y3) / 3;

    float tx1 = x1 - cx, ty1 = y1 - cy;
    float tx2 = x2 - cx, ty2 = y2 - cy;
    float tx3 = x3 - cx, ty3 = y3 - cy;

    double theta = thetad * (M_PI / 180.0); 
    float a = cos(theta);
    float b = sin(theta);
    float A[3][3] = {
        {a, -b, 0},
        {b, a, 0},
        {0, 0, 1}
    };
    
    float B1[3] = {tx1, ty1, 1};
    float B2[3] = {tx2, ty2, 1};
    float B3[3] = {tx3, ty3, 1};
    
    float C1[3], C2[3], C3[3];
    
    matrix_multiplication(A, B1, C1);
    matrix_multiplication(A, B2, C2);
    matrix_multiplication(A, B3, C3);
    
    float rx1 = C1[0] + cx, ry1 = C1[1] + cy;
    float rx2 = C2[0] + cx, ry2 = C2[1] + cy;
    float rx3 = C3[0] + cx, ry3 = C3[1] + cy;

    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    setcolor(GREEN);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);
}

// void scale(float x1, float y1, float x2, float y2, float x3, float y3, float sx, float sy) {
//     float A[3][3] = {
//         {sx, 0, 0},
//         {0, sy, 0},
//         {0, 0, 1}
//     };
    
//     float B1[3] = {x1, y1, 1};
//     float B2[3] = {x2, y2, 1};
//     float B3[3] = {x3, y3, 1};  
//     float C1[3], C2[3], C3[3];
    
//     matrix_multiplication(A, B1, C1);
//     matrix_multiplication(A, B2, C2);
//     matrix_multiplication(A, B3, C3);
    
//     setcolor(RED);
//     line(x1, y1, x2, y2);
//     line(x2, y2, x3, y3);
//     line(x3, y3, x1, y1);
    
//     setcolor(GREEN);
//     line(C1[0], C1[1], C2[0], C2[1]);
//     line(C2[0], C2[1], C3[0], C3[1]);
//     line(C3[0], C3[1], C1[0], C1[1]);
// } 

void scale(float x1, float y1, float x2, float y2, float x3, float y3, float sx, float sy) {
    float cx = (x1 + x2 + x3) / 3;
    float cy = (y1 + y2 + y3) / 3;

    float tx1 = x1 - cx, ty1 = y1 - cy;
    float tx2 = x2 - cx, ty2 = y2 - cy;
    float tx3 = x3 - cx, ty3 = y3 - cy;

    float A[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };
    
    float B1[3] = {tx1, ty1, 1};
    float B2[3] = {tx2, ty2, 1};
    float B3[3] = {tx3, ty3, 1};
    
    float C1[3], C2[3], C3[3];
    
    matrix_multiplication(A, B1, C1);
    matrix_multiplication(A, B2, C2);
    matrix_multiplication(A, B3, C3);
    
    float rx1 = C1[0] + cx, ry1 = C1[1] + cy;
    float rx2 = C2[0] + cx, ry2 = C2[1] + cy;
    float rx3 = C3[0] + cx, ry3 = C3[1] + cy;

    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    setcolor(GREEN);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);
} 

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    translate(300, 300, 350, 250, 400, 300, 100, 100);
    rotate(300, 100, 350, 50, 400, 100, 150);
    scale(100, 100, 150, 50, 200, 100, 2,2);

    getch();
    closegraph();
    return 0;
}

