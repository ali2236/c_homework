#include <stdio.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    const int N = 5;
    int a[N][N];
    int i,j;
    //randomize
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            a[i][j] = rand() % 10;
    }
    //side_rotate
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            int t = a[i][j];
            a[i][j] = a[N-j-1][N-i-1];
            a[N-j-1][N-i-1] = t;
        }
    }
    //print mat
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
