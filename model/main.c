#include <stdio.h>
#include <stdlib.h>

int main()
{
     srand(time(NULL));
    const int N;
    printf("Enter N:");
    scanf("%d",&N);

    int a[N];
    int counter[N];
    int i;
    // create random array
    for(i=0;i<N;i++){
        a[i] = rand() % 100;
        counter[i] = 0;
    }

    //sort array
    int j;
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(a[j] > a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
    //print array
     for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
    printf("\n\n");
    /////////////////////////////////////// code
    int max = 1,value = a[0];
    int t_max,t_value;
    for(i=0;i<N;){
        t_value = a[i];
        t_max = 1;
        for(j=i;j<N;j++){

                if(j<N-1){
                    if(a[j]==a[j+1]){
                        t_max++;
                    }else{
                        if(t_max > max){
                            max = t_max;
                            value = t_value;
                        }
                        i = j+1;
                        break;
                    }
                } else {
                    if(t_max>max){
                        max = t_max;
                        value = t_value;
                    }
                    i = j+1;
                    break;
                }
            }
        }

        printf("value = %d\t max = %d",value,max);

    return 0;
    }
