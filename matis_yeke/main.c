#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    const int N = 3;
    int a[N][N];
    int i,j;
    //random matrix
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            a[i][j] = rand() % 2;

    int bottom_zero = 1,top_zero = 1;
    for(i=0;i<N;i++){
        for(j=0;j<i;j++){
            if(a[i][j] != 0)
                bottom_zero = 0;
            if(a[j][i] != 0)
                top_zero = 0;
        }
    }

    if(bottom_zero && top_zero)
        printf("Identity matrix");
    else if(top_zero)
        printf("lower triangular matrix");
    else if(bottom_zero)
        printf("upper triangular");
    else
        printf("not a special type");
    return 0;
}
