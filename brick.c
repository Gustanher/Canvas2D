#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gl_canvas2d.h"


int mx, my; //coordenadas do mouse
int xrect = 100, r = 10, vidas = 3;
float random = 1, x = 250, y = 250, vx = (rand() / (float)RAND_MAX) * 10 - 5,vy = (rand() / (float)RAND_MAX) * 10 - 5;


//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
    color(1);
    x += vx;
    y += vy;
    rectFill(xrect, 400, xrect + 150, 420 );
    circleFill(x,y,r,20);
    if(x - r < 0)
    {
        x = r;
        vx = -vx + ((rand() / (float)RAND_MAX) * 2 - 1);
        vy += ((rand() / (float)RAND_MAX) * 2 - 1);
    }
    if(x + r > 500)
    {
        x = 500 - r;
        vx = -vx + ((rand() / (float)RAND_MAX) * 2 - 1);
        vy += ((rand() / (float)RAND_MAX) * 2 - 1);
    }
    if(y - r < 0)
    {
        y = r;
        vy = -vy + ((rand() / (float)RAND_MAX) * 2 - 1);
        vx += ((rand() / (float)RAND_MAX) * 2 - 1);
    }
    if(y + r > 500)
    {
        vidas--;
        x = 250;
        y = 250;
    }
    if(vidas <= 0)
        {
            color(0);
            rectFill(0,0,500,500);
            color(4);
            text(200, 250, "Fim de Jogo" );


        }
    if(y > (400) && y < (420)&& (x >= xrect) && (x <= xrect + 150))
    {
        y = 400 - r;
        vy = -vy + ((rand() / (float)RAND_MAX) * 2 - 1);
    }

    if(xrect >= 500 - 150)
    {
        xrect = 500 - 150;
    }
    else if(xrect <= 0)
    {
        xrect = 0;
    }


    text(250,50, vidas);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   mx = x; //guarda as coordenadas do mouse para exibir dentro da render()
   my = y;
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nClicou Tecla: %d" , key);
   if ( key == 200)
    {
        xrect -= 40;
    }
    if (key == 202)
    {
        xrect += 40;
    }
}


//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou Tecla: %d" , key);
}


int main(void)
{
   srand(time(NULL));
   int screenWidth = 500, screenHeight = 500; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
   init(&screenWidth, &screenHeight, "Canvas 2D");
   run();
}
