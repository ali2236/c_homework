#include <stdio.h>
int main()
{
    //Vars
    int a,b,c;
    int high,mid,low;
    printf("Enter a,b,c:\n");
    scanf("%d %d %d",&a,&b,&c);

    if (a > b){
        high = a;
        mid = b;
    } else {
        high = b;
        mid = a;
    }
    if (c > mid) {
        int temp = mid;
        mid = c;
        low = temp;
        if (mid > high) {
            int temp = high;
            high = mid;
            mid = temp;
        }
    } else {
        low = c;
    }

    printf("%d %d %d",high,mid,low);
    return 0;
}
