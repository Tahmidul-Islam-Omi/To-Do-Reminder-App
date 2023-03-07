#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define a struct to hold date and time values
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// compare function for qsort to sort date and time values in ascending order
int compareDateTime(const void *a, const void *b) {
    struct DateTime *date1 = (struct DateTime *) a;
    struct DateTime *date2 = (struct DateTime *) b;

    // compare year
    if (date1->year != date2->year) {
        return date1->year - date2->year;
    }

    // compare month
    if (date1->month != date2->month) {
        return date1->month - date2->month;
    }

    // compare day
    if (date1->day != date2->day) {
        return date1->day - date2->day;
    }

    // compare hour
    if (date1->hour != date2->hour) {
        return date1->hour - date2->hour;
    }

    // compare minute
    if (date1->minute != date2->minute) {
        return date1->minute - date2->minute;
    }

    // if both date and time values are equal, return 0
    return 0;
}

int main() {
    // initialize 5 date and time values
    struct DateTime values[5] = {
        {2022, 2, 28, 10, 30},
        {2022, 2, 28, 12, 0},
        {2022, 2, 27, 9, 15},
        {2022, 2, 27, 10, 0},
        {2022, 2, 28, 9, 0}
    };

    // sort date and time values using qsort
    qsort(values, 5, sizeof(struct DateTime), compareDateTime);

    // print sorted date and time values
    printf("Sorted Date and Time values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d-%02d-%02d %02d:%02d\n", values[i].year, values[i].month, values[i].day, values[i].hour, values[i].minute);
    }

    return 0;
}
