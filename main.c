/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int algopd(int x, int y, int righe, int colonne, int a[][6]);
int algo(int x, int y, int righe, int colonne);
int main()
{
    int a[6][6]={};
    printf("%d\n",algopd(0,0,6,6,a));
    printf("%d\n",algo(0,0,6,6));
    return 0;
}

int algopd(int x, int y, int righe, int colonne, int a[][6])
{
    if(x==righe-1&&y==colonne-1) return 1;
    else if(y==colonne-1) return algopd(x+1,y,righe,colonne,a);
    else if(x==righe-1) return algopd(x,y+1,righe,colonne,a);
    if(a[x][y]==0)
            a[x][y]=algopd(x+1,y,righe,colonne,a)+algopd(x,y+1,righe,colonne,a);
    return a[x][y];
}

int algo(int x, int y, int righe, int colonne)
{
    if(x==righe-1&&y==colonne-1) return 1;
    else if(y==colonne-1) return algo(x+1,y,righe,colonne);
    else if(x==righe-1) return algo(x,y+1,righe,colonne);
    return algo(x+1,y,righe,colonne)+algo(x,y+1,righe,colonne);
}