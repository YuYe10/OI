#include <stdio.h>
int main()
{
    double open,high,low,close;
    scanf("%lf%lf%lf%lf",&open,&high,&low,&close);

    if(close<open){
        printf("BW-Solid");
        if(low<open && low<close){
            printf(" with Lower Shadow");
            if(high>open && high>close){
                printf(" and Upper Shadow");
            }else{
            if(high>open && high>close){
                printf(" with Upper Shadow");
        }}}}else if(close>open){
            printf("R-Hollow");
            if(low<open && low<close){
                printf(" with Lower Shadow");
                    if(high>open && high>close){
                        printf(" and Upper Shadow");
                    }
            }else{
                if(high>open && high>close){
                    printf(" with Upper Shadow");
                }
        }}else{
        printf("R-Cross");
        if(low<open && low<close){
            printf(" with Lower Shadow");
                if(high>open && high>close){
                    printf(" and Upper Shadow");
                }
        }else{
            if(high>open && high>close){
                printf(" with Upper Shadow");
                }
        }
        }
    return 0;
}