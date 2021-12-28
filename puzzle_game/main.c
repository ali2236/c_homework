#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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

const int UP = 72;
const int DOWN = 80;
const int RIGHT = 77;
const int LEFT = 75;

const int N = 5;
const int M = 5;

const float sleep = 10;
int shuffle_amount = 80;

int X;
int Y;

int lastNum;
int Running = 0;
int won = 0;
long frames = 0;
long moves = 0;

void printArray2D(int a[N][M]);
void initPuzzle(int a[N][M]);
void move(int a[N][M],int x,int y);
void swap(int *a,int *b);
void handleInput(int a[N][M]);
void shuffle_puzzle(int a[N][M],int amount);
void moveToMid(int a[N][M]);
void checkIfWon(int a[N][M]);
void printGrid(int a[N][M]);

void main(){
    srand(time(NULL));
    int puzzle[N][M];
    initPuzzle(puzzle);
    while(Running){
        system("cls");
        printf(" position:(%d,%d) frames:%d fps:%.2f\n\n",X,Y,frames++,1000/sleep);
        handleInput(puzzle);
        //printArray2D(puzzle);
        printGrid(puzzle);
        checkIfWon(puzzle);
        Sleep(sleep);
    }
    if(won){
        system("cls");
        printf("You Won!\nmoves:%d",moves);
    }
}

void printArray2D(int a[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(a[i][j] != lastNum)
                printf("%2d ",a[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void initPuzzle(int a[N][M]){
    int i,j,c=1;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            a[i][j] = c++;
        }
    }
    lastNum = c-1;

    X = M-1;
    Y = N-1;

    shuffle_puzzle(a,shuffle_amount);
    moveToMid(a);
    checkIfWon(a);
    while(won){
        initPuzzle(a);
    }
    Running = 1;
}

void move(int a[N][M],int x,int y){
    //horizontal movement
    if(X+x>=0&&X+x<M){
        swap(&a[Y][X],&a[Y][X+x]);
        X += x;
    }
    //vertical movement
    if(Y+y>=0&&Y+y<N){
        swap(&a[Y][X],&a[Y+y][X]);
        Y += y;
    }

    if(Running){
        moves++;
    }
}

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void handleInput(int a[N][M]){
    while(_kbhit()){
        char c = _getch();
        c = _getch();
        if(c==UP){
            move(a,0,1);
        }else if(c==DOWN){
            move(a,0,-1);
        }else if(c==RIGHT){
            move(a,-1,0);
        }else if(c==LEFT){
            move(a,1,0);
        }
    }
}

void shuffle_puzzle(int a[N][M],int amount){
    while(amount--){
        int dir = rand() % 4;
        if(dir==0){
            move(a,1,0);
        }else if(dir==1){
            move(a,-1,0);
        }else if(dir==2){
            move(a,0,1);
        }else if(dir==3){
            move(a,0,-1);
        }
    }
}

void moveToMid(int a[N][M]){
    //X
    while(X!=M/2){
        if(X>M/2){
            swap(&a[Y][X],&a[Y][X-1]);
            X += -1;
        }else if(X<M/2){
            swap(&a[Y][X],&a[Y][X+1]);
            X += 1;
        }
    }
    //Y
    while(Y!=N/2){
        if(Y>N/2){
            swap(&a[Y][X],&a[Y-1][X]);
            Y += -1;
        }else if(Y<N/2){
            swap(&a[Y][X],&a[Y+1][X]);
            Y += 1;
        }
    }
}

void checkIfWon(int a[N][M]){
    if(X==M-1&&Y==N-1){
        int i,j,c=1,flag=1;
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                if(a[i][j]!=c++)
                    flag = 0;
            }
        }
            if(flag){
            won=1;
            Running = 0;
        }else{
            won=0;
        }
    }else{
        won=0;
    }
}

void printGrid(int a[N][M]){
    int y,x;
    for(y=0;y<N*2+1;y++){
        for(x=0;x<M*2+1;x++){
            char c = '%';

            //put number
            if(x%2!=0&&y%2!=0){
                    if(a[y/2][x/2] != lastNum)
                        printf("%2d",a[y/2][x/2]);
                    else
                        printf("  ");
                continue;
            }

            //put corner
            else if(x==0&&y==0)
                c=tl;
            else if(x==0&&y==N*2)
                c=bl;
            else if(x==M*2&&y==0)
                c=tr;
            else if(x==M*2&&y==N*2)
                c=br;

            //put 3way border
            else if(x%2==0 && y==0)
                c=tm;
            else if(y%2==0 && x==0)
                c=lm;
            else if(x%2==0 && y==N*2)
                c=bm;
            else if(y%2==0 && x==M*2)
                c=rm;

            //put 4way border
            else if(x%2==0&&y%2==0)
                c=mm;

            // put horizontal or vertical line
            else if(y%2!=0)
                c=v;
            else if(x%2!=0){
                printf("%c%c",h,h);
                continue;
            }

            printf("%c",c);
        }
        printf("\n");
    }

}
