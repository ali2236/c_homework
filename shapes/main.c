#include <stdio.h>
#include <math.h>

int main()
{
    int number,reverse = 0;
    printf("Enter n:");
    scanf("%d",&number);

    //reverse number
   while(number!=0){
        int digit = number%10;
        reverse = reverse * 10 + digit;
        number /= 10;
    }
    //print each digit using switch statement
    while(reverse!=0){
        int digit = reverse%10;
        reverse /=10;

        int n = 7;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                switch (digit){
                case 0:
                    if(i==0 || j==0 || i==n-1 || j==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 1:
                    if(j==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 2:
                    if(i==0 || (j==n-1 && i<n/2) || i==n/2 || (j==0 && i>n/2) || i==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 3:
                    if(i==0 || i==n/2 || i==n-1 || j==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 4:
                    if((j==0 && i<n/2)|| i==n/2 || j==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 5:
                    if(i==0 || (j==0 && i<n/2) || i==n/2 || (j==n-1 && i>n/2) || i==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 6:
                    if(j==0 || i==0 || i==n/2 || i==n-1 || (j==n-1 && i>n/2))
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 7:
                    if(i==0 || j==n-1 ||(i<=n/2 && j==0))
                       printf("#");
                    else
                        printf(" ");
                    break;
                case 8:
                    if(i==0 || i==n/2 || i==n-1 || j==0 || j==n-1)
                        printf("#");
                    else
                        printf(" ");
                    break;
                case 9:
                    if(j==n-1 || i==0 || i==n/2 || i==n-1 || (j==0 && i<n/2))
                        printf("#");
                    else
                        printf(" ");
                    break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
