#include <stdio.h>
#include <stdlib.h>

void emptyMaze(int *a[],int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for (j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}

void printMaze(int n,int m,int *a[]){
    int i,j;
    for(i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    const int N = 12;
    const int M = 12;
    int maze[N][M];
    emptyMaze(maze,N,M);
    printMaze(N,M,maze);
    return 0;
}
