#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Enter a,b,c:\n");
    scanf("%d %d %d",&a,&b,&c);

    if (a+b > c && a+c > b && b+c > a) {
        if ((a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == a*a + b*b)) {
            printf("right angle triangle.\n");
        }
        else if ( a == b && b == c && a == c) {
            printf("all equal sides triangle.\n");
        }
        else if ( a == b || b == c || a == c) {
            printf("two equal sides triangle.\n");
        } else {
            printf("different sides triangle.\n");
        }
    } else {
        printf("not a triangle.\n");
    }
    return 0;
}
