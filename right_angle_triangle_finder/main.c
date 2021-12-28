#include <stdio.h>
int main()
{
        int a = 1,b = 1,c = 1,n = 0;
    printf("Enter max number to try:\n");
    scanf("%d",&n);

    while ( a < n ) {
        while ( b < n) {
            while ( c < n) {
                if (a+b > c && a+c > b && b+c > a) {
                if ((a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == a*a + b*b)) {
                    printf("%d : %d : %d \n",a,b,c);
                    }
                }
                c = c + 1;
            }
            b = b + 1;
            c = 1;
        }
        a = a + 1;
        b = 1;
        c = 1;
    }


    return 0;
}
