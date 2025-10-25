/*
* Name: printCalendar.c
* Purpose: Prints Days of one mont
* Author: Faseeh-Ur-Rehman
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printCalendar(int daysInMonth, int startDayOfMonth){

    printf("Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

    int dayNumber = 1;
    int daysPassed_PerWeek = 0;
    bool isFirstWeek = true;

    while(dayNumber <= daysInMonth){

        if(daysPassed_PerWeek < startDayOfMonth && isFirstWeek){
                printf("     ");
                daysPassed_PerWeek++;
                continue;
        }

        isFirstWeek = false;
        printf(" %2d  ",dayNumber++);

        daysPassed_PerWeek++;
        if(daysPassed_PerWeek == 7){
            daysPassed_PerWeek = 0;
            printf("\n");
        }

    }


}

int main(void){
    printCalendar(31,6);

    exit(EXIT_SUCCESS);
}