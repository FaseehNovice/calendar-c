/*
* Name: calendar.c
* Purpose: Prints calendar of a given year
* Author: Faseeh-Ur-Rehman
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MONTHS_IN_YEAR 12

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

int getFirstDayOfYear(int year){
    struct tm first_day_of_year = {0};
    first_day_of_year.tm_year = year - 1900;
    first_day_of_year.tm_mon = 0;
    first_day_of_year.tm_mday = 1;

    time_t rawTime = mktime(&first_day_of_year);

    struct tm *localTime = localtime(&rawTime);

    return localTime->tm_wday;
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
    int Lastday_of_prevMonth = getFirstDayOfYear(year) - 1;
    printf("\n-------------------------------------\n");
    for(int i = 0; i < MONTHS_IN_YEAR ; i++){
        printf(ANSI_COLOR_CYAN"             %s                     "ANSI_COLOR_RESET ,getMonthName(i));
        printf("\n-------------------------------------\n");
        days_one_Month = numberOfDaysInMonth(year, i + 1);
        Lastday_of_prevMonth = printMonth(days_one_Month,Lastday_of_prevMonth);
        printf("\n-------------------------------------\n");
    }
}


int main(void){

    int get_year;
    printf("Enter Year for Calendar: ");

    if(scanf("%d",&get_year) != 1){
        printf("ERROR: Invalid Input");
        exit(EXIT_FAILURE);
    }
    printCalendar(get_year);

    exit(EXIT_SUCCESS);
}