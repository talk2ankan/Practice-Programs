/*
 * DDA Line Drawing Algorithm
 */

#include <stdio.h>
#include <math.h>
#include <graphics.h>

void ddaLine(int x0, int y0, int x1, int y1) {
    float x, y, xInc, yInc;
    int dx, dy, step, i;

    dx = x1-x0;
    dy = y1-y0;


    /* if dx>dy set step=dx; else set step=dy */
    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    /* plot the initial pixels */
    x = round(x0);
    y = round(y0);

    putpixel(x, y, 5);

    /* calculate the factor to increment x and y */
    xInc = dx/(float)step;
    yInc = dy/(float)step;

    /* plot the rest of the line */
    for(i = 0 ; i < step ; i++) {
        x += xInc;
        y += yInc;

        putpixel(round(x), round(y), 5);
    }
}

int main() {
    int gd=DETECT, gm;
    int x0, y0,
        x1, y1;

    printf("Enter (x0, y0): ");
    scanf("%d %d", &x0, &y0);

    printf("Enter (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    initgraph(&gd, &gm, NULL);

    ddaLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}