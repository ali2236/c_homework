#include <stdio.h>

int main()
{
    //input
    const int N = 100;
    char c1[100],c2[100];
    int n1[100] = {0},n2[100] = {0};
    int n1_length = N-1,n2_length = N-1;
    printf("Enter Number:");
    scanf("%s",&c1);
    printf("Enter Number:");
    scanf("%s",&c2);
    int i;
    // get length
    for(i=0;i<N;i++){
        if(c1[i]=='\0'){
            n1_length = i;
            break;
        }
    }
    for(i=0;i<N;i++){
        if(c2[i]=='\0'){
            n2_length = i;
            break;
        }
    }
    //convert
    int j=0;
    for(i=n1_length-1;i>=0;i--){
        n1[j] = c1[i] - '0';
        j++;
    }
    j=0;
    for(i=n2_length-1;i>=0;i--){
        n2[j] = c2[i] - '0';
        j++;
    }

    //sum
    int sum[100+1] = {0};
    for(i=0;i<N;i++){
        sum[i] += (n1[i] + n2[i]) % 10;
        sum[i+1] += (n1[i] + n2[i]) / 10;
        sum[i+1] += sum[i] / 10;
        sum[i] %= 10;
    }
    //print sum
    for(i=N;i>=0;i--)
        printf("%d",sum[i]);

    //Multiplication
    int mult[2*100] = {0};
    for(i=0;i<n1_length;i++){
        for(j=0;j<n2_length;j++){
            mult[i+j] += n1[i] * n2[j];
            mult[i+j+1] += mult[i+j]/10;
            mult[i+j] %= 10;
        }
    }
    //print multiplication
    printf("\n");
    for(i=2*N-1;i>=0;i--)
        printf("%d",mult[i]);
    return 0;
}
