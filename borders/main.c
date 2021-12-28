#include <stdio.h>
#include <stdlib.h>

const char
 rm = 185,
  v = 186,
 tr = 187,
 br = 188,
 bl = 200,
 tl = 201,
 bm = 202,
 tm = 203,
 lm = 204,
  h = 205,
 mm = 206;

void printGridWithRandomNumbers(int hight,int width){
    int y,x;
    for(y=0;y<hight*2+1;y++){
        for(x=0;x<width*2+1;x++){
            char c = '%';

            //put number
            if(x%2!=0&&y%2!=0)
                c='0'+rand()%10;


            //put corner
            else if(x==0&&y==0)
                c=tl;
            else if(x==0&&y==hight*2)
                c=bl;
            else if(x==width*2&&y==0)
                c=tr;
            else if(x==width*2&&y==hight*2)
                c=br;

            //put 3way border
            else if(x%2==0 && y==0)
                c=tm;
            else if(y%2==0 && x==0)
                c=lm;
            else if(x%2==0 && y==hight*2)
                c=bm;
            else if(y%2==0 && x==width*2)
                c=rm;

            //put 4way border
            else if(x%2==0&&y%2==0)
                c=mm;

            // put horizontal or vertical line
            else if(y%2!=0)
                c=v;
            else if(x%2!=0)
                c=h;

            printf("%c",c);
        }
        printf("\n");
    }

}

int main()
{
    printGridWithRandomNumbers(5,10);
    return 0;
}
