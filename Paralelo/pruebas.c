#include <stdlib.h>
#include<stdio.h>
#include<time.h>
/*
 float arc4random2(){
     return arc4random();
 }*/ 

int main(int argc, char const *argv[])
{
    srand ((int)time(NULL));
    float x =(float)(rand()%100);
    printf("%f",x);
    return 0;
}
