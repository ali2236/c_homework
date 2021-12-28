#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    const int N = 2,M = 3,P = 4;
    int a[N][M],b[M][P];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            a[i][j] = rand()%10;
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<P;j++){
            b[i][j] = rand()%10;
        }
    }

    //print a,b
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<M;i++){
        for(j=0;j<P;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //multiply a&b
    //if possible
    // c = N*P
    int c[2][4]={0};
    int x,y,k,l,m;
    for(x=0;x<N;x++)
        for(y=0;y<P;y++){
            l=j=0;
            for(k=0;k<M;k++)
                c[x][y] += a[x][j++]*b[l++][y];
        }

    //print c
    for(i=0;i<N;i++){
        for(j=0;j<P;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
