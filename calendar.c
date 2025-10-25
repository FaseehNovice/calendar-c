/*
* Name: calendar.c
* Purpose: Prints calendar of a given year
* Author: Faseeh-Ur-Rehman
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MONTHS_IN_YEAR 12

int last_day_in_month = 0;

bool isLeapYear(int year){
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int numberOfDaysInMonth(int year, int month){
    int months[] = {31 , 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month != 2)
        return months[month - 1 ];

    if(isLeapYear(year))
        return 29;

    return 28;
}

char* getMonthName(int month){
    char *months[] = {"January", "February", "March", "April",
                      "May", "June", "July", "August",
                      "September","October","November","December"};

    return months[month];
}

int printMonth(int daysInMonth, int startDayOfMonth){

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
    return daysPassed_PerWeek;

}

void printCalendar(int year){
    int days_one_Month;
    int Lastday_of_prevMonth = 0;
    printf("\n-------------------------------------\n");
    for(int i = 0; i < MONTHS_IN_YEAR ; i++){
        printf("             %s                     ",getMonthName(i));
        printf("\n-------------------------------------\n");
        days_one_Month = numberOfDaysInMonth(year, i + 1);
        Lastday_of_prevMonth = printMonth(days_one_Month,Lastday_of_prevMonth);
        printf("\n-------------------------------------\n");
    }
}


int main(void){

    printCalendar(2025);
    exit(EXIT_SUCCESS);
}