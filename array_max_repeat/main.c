#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    // count repeats in array
    for(i=0;i<N;i++){
        int num = a[i];
        counter[num] += 1;
    }
    // get the number with the most number of repeats
    int mostRepeatedNumber = 0;
    for(i=1;i<N;i++){
        if(counter[i]>counter[mostRepeatedNumber]){
            mostRepeatedNumber = i;
        }
    }
    // print the array
    for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
    printf("\n\n");
    printf("Most repeated number is %d\n",mostRepeatedNumber);
    // print indexes where they contain the mostRepeatedNumber
    for(i=0;i<N;i++){
        if(a[i] == mostRepeatedNumber)
            printf("in %d\n",i);
    }

    return 0;
}
