#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    float grade;
}student;

void student_sort(student s[],int n){
    int i;
    for(i=0;i<n;i++){
        int j = i;
        student key = s[j];
        while(j>0 && s[j-1].grade>key.grade){
            s[j] = s[j-1];
            j--;
        }
        s[j] = key;
    }
}

int main()
{
    student array[3];
    student a = {1,"a",12.5};
    student b = {1,"b",15.65};
    student c = {1,"C",17.4};
    array[0] = c;
    array[1] = b;
    array[2] = a;
    printf("%.2f\t%.2f\t%.2f\n",array[0].grade,array[1].grade,array[2].grade);
    student_sort(array,3);
    printf("%.2f\t%.2f\t%.2f\n",array[0].grade,array[1].grade,array[2].grade);
    return 0;
}
