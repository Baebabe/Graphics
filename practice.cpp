#include <graphics.h>
#include<iostream>
using namespace std;
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    //circle(200, 200, 150);

    //arc(200,200,30,310,100);//start angle and end angle are measured from positive x axis

    //bar(10,10,20,20);

    //ellipse(300, 300, 0, 180, 100, 50);

    //circle(200, 200, 150);
    // setfillstyle(SOLID_FILL, RED);
    // floodfill(200, 200, WHITE);

    // setbkcolor(BLUE);
    // int bgcolor=getbkcolor();
    // cout<<"The background color is"<<bgcolor<<endl;
    getch();
    closegraph();
    return 0;
}
