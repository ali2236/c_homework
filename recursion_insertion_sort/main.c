#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int a[],int n){
    if(n==0)
        return;

    //get the biggest number index
    int index = maxIndex(a,0,n-1);

    //swap it with the last number
    int t = a[n-1];
    a[n-1] = a[index];
    a[index] = t;

    insertion_sort(a,n-1);
}

int maxIndex(int a[],int p,int r){
    if(p==r)
        return p;
    int mIndex = maxIndex(a,p+1,r);
    return (a[p]>a[mIndex])?p:mIndex;
}


int main()
{
    srand(time(NULL));
    const int n = 10;
    int a[n];
    int i;

    for(i=0;i<n;i++)
        a[i] = rand() % 100;

    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    insertion_sort(a,n);

        printf("\n\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
