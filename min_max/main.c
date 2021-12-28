#include <stdio.h>


int main()
{
    //Variables
    int a,b,c;

    printf("Enter a,b,c:\n");
    //input
    scanf("%d %d %d",&a,&b,&c);

    //calculations
    int max = a;
    int min = a;

    if (b>max)
        max = b;
    else
        min = b;
    if (c>max)
        max = c;
    else if (c < min)
        min = c;

    //output
    printf("min = %d \t max = %d",min,max);

    return 0;
}
