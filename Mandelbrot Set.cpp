#include <iostream>
#include <graphics.h>
#include <windows.h>
using namespace std;

/*
Function: z(n+1) = z(n)*z(n) + c, where z(n+1), z(n) & c are complex numbers of the form "a + ib" & i=sqrt(-1)

Working: Plotting the color of each pixel in graph based upon the value of n until which the function remains bounded in the range of [-2, 2]
         for each value in the domain of c. Domain of c depends upon the scaling factor or multiplication factor, i.e. how much the graph is zoomed-in or zoomed-out
         at the time when it is visualized. Initial values of c_real lie in the range of [-200, 200] & c_img lie in the range of [-120, 120].
         Real part of complex number is mapped with x-axis and imaginary part of the number is mapped with y-axis of the graph.

         To conclude, the number of iterations for z(n) to reach a modulus greater than 2 has been used to determine the color of the pixel. This pixel is the position of point c on complex plane.
*/

class mandelbrot
{
    int width, height;      // Width & Height of the display screen
    int x_mid, y_mid;       // Mid point of the graph
    float z_real[2], z_img[2], c_real, c_img, MultFactor, IncValue;
    char key_pressed;

    void changeFrameOfReference()
    {
        if(key_pressed == '+')
        {
            IncValue /= 2;
            MultFactor *= 2;
        }
        else if(key_pressed == '-')
        {
            IncValue *= 2;
            MultFactor /= 2;
        }
        else
        {
            switch(key_pressed)
            {
            case 75:        // LEFT ARROW KEY
                x_mid += 200;
                break;
            case 77:        // RIGHT ARROW KEY
                x_mid -= 200;
                break;
            case 72:        // UP ARROW KEY
                y_mid += 100;
                break;
            case 80:        // DOWN ARROW KEY
                y_mid -= 100;
                break;
            }
        }
    }

    int nWhenFunctionExceeds2()
    {
        // Calculating the value of z(n+1) = z(n)*z(n) + c, starting from z(0)=0

        // Base Condition: z(0) = 0
        // Therefore, z(1) = 0 + c
        z_real[0]=c_real, z_img[0]=c_img;

        for(int n=2; n<100; n++)
        {
            z_real[1] = (z_real[0] * z_real[0]) - (z_img[0] * z_img[0]) + c_real;
            z_img[1] = (2 * z_real[0] * z_img[0]) + c_img;

            if(abs(z_real[1])>=2.0 || abs(z_img[1])>=2.0)
            {
                return n;
            }
            else if(z_real[1] == z_real[0] && z_img[1] == z_img[0])
            {
                return 100;
            }
            z_real[0] = z_real[1];
            z_img[0] = z_img[1];
        }
        return 100;
    }

    void drawgraph()
    {
        //setfillstyle(SOLID_FILL, CYAN);
        //floodfill(0, 0, WHITE);


        // for each value of c in [-2, 2], calculating the value of z(n+1) = z(n)*z(n) + c, starting from z(0)=0
        for(c_real=-2; c_real<=2; c_real+=IncValue)         // Range At Initial Zoom Scale: -200 to +200 pixels
        {
            for(c_img=-1.2; c_img<=1.2; c_img+=IncValue)    // Range At Initial Zoom Scale: -120 to +120 pixels
            {
                int x_temp = c_real * MultFactor;
                int y_temp = c_img * MultFactor;

                if(x_mid+x_temp>=0 && x_mid+x_temp<=width && y_mid+y_temp>=0 && y_mid+y_temp<=height)
                {
                    // Finding the maximum value of n until which the function z(n+1) = z(n) + c remains bounded in the range [-2, 2]
                    int n = nWhenFunctionExceeds2();

                    switch(n/10)
                    {
                        /*case 0:
                            putpixel(x_mid+x_temp, y_mid+y_temp, BLUE);
                            break;*/
                        case 1:
                            putpixel(x_mid+x_temp, y_mid+y_temp, BLUE);
                            break;
                        case 2:
                            putpixel(x_mid+x_temp, y_mid+y_temp, WHITE);
                            break;
                        case 3:
                            putpixel(x_mid+x_temp, y_mid+y_temp, LIGHTMAGENTA);
                            break;
                        case 4:
                            putpixel(x_mid+x_temp, y_mid+y_temp, MAGENTA);
                            break;
                        case 5:
                            putpixel(x_mid+x_temp, y_mid+y_temp, YELLOW);
                            break;
                        case 6:
                            putpixel(x_mid+x_temp, y_mid+y_temp, LIGHTRED);
                            break;
                        case 7:
                            putpixel(x_mid+x_temp, y_mid+y_temp, RED);
                            break;
                        case 8:
                            putpixel(x_mid+x_temp, y_mid+y_temp, LIGHTGRAY);
                            break;
                        case 9:
                            putpixel(x_mid+x_temp, y_mid+y_temp, DARKGRAY);
                            break;
                        /*case 10:
                            putpixel(x_mid+x_temp, y_mid+y_temp, BLACK);
                            break;*/
                    }
                }
            }
        }

        char* message = "Use ARROW keys to move and '+' & '-' keys to Zoom In & Out";
        outtextxy(width/2 - textwidth(message)/2, 0, message);
    }

public:

    mandelbrot()
    {
        key_pressed=0;
        MultFactor=100, IncValue=0.01;
        z_real[0]=0.0, z_img[0]=0.0;
        width = GetSystemMetrics(SM_CXSCREEN);          //1536
        height = GetSystemMetrics(SM_CYSCREEN) -26;     //838
        initwindow(width, height, "MANDELBROT SET", -3, -1, false, true);
        x_mid=width/2, y_mid=height/2;
    }

    void CALL_DRAW_FUNCTION()
    {
        drawgraph();
        while(key_pressed!=27)  // ESC KEY
        {
            key_pressed = getch();
            if(key_pressed=='+' || key_pressed=='-' || key_pressed==75 || key_pressed==77 || key_pressed==72 || key_pressed==80)  // ARROW KEYS
            {
                changeFrameOfReference();
                cleardevice();
                drawgraph();
            }
        }
    }

    ~mandelbrot()
    {
        closegraph();
    }
};

int main()
{
    mandelbrot object;
    object.CALL_DRAW_FUNCTION();
    return 0;
}
