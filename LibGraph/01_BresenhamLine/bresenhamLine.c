#include <stdio.h>
#include <graphics.h>

void brsLine(int x0, int y0, int x1, int y1) {
    int dx = x1-x0;
    int dy = y1-y0;

    //-- calculate D and plot the initial points
    int D = 2*dy - dx;
    putpixel(x0, y0, 5);

    int x, y;

    for(x = x0+1 ; x < x1 ; x++) {
        putpixel(x, y, 5);

        if(D > 0) {
            //-- increase y and plot(x, y)
            y += 1;

            //-- calculate new value of D
            D += 2 * (dy - dx);
        }
        else { //-- D < 0
            //-- calculate the new value of D
            D += 2*dy;
        }
    }
}

int main() {
    int x0, y0,
        x1, y1;
    int gd = DETECT, gm;

    printf("Enter values for (x0, y0): ");
    scanf("%d %d", &x0, &y0);

    printf("Enter values for (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    initgraph(&gd, &gm, NULL);

    brsLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}