#include<stdio.h>
int main(){
    int a,b,c,isThreeZero=1;
    while (isThreeZero!=0){
        isThreeZero=inputThree(&a,&b,&c);
        if(isThreeZero!=0)sortThree(&a,&b,&c);
        else printf("Three Zeros Entered. The End!");
    }
    return 0;
}
int inputThree(int* a,int* b,int* c){
    printf("Input three integers values: ");
    scanf("%d%d%d",a,b,c);
    return *a==0&&*b==0&&*c==0?0:1;
}
void sortThree(int* a,int* b,int* c){
    sortTwo(a,b);
    sortTwo(a,c);
    sortTwo(b,c);
}
void sortTwo(int* a,int* b){
    if(*a>*b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
}
