/* compare_dates.c by Dylan Skroskznik
    Program assumes years are in the same century. */

#include <stdio.h>

int main(void)
{
  int month1, day1, year1, month2, day2, year2;
  int first_earlier = 0;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month1, &day1, &year1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month2, &day2, &year2);

  if (year1 != year2)
    first_earlier = year1 < year2;
  else if (month1 != month2)
    first_earlier = month1 < month2;
  else
    first_earlier = day1 < day2;

  if (first_earlier)
    printf("%d/%d/%d is earlier than %d/%d/%d\n",
        month1, day1, year1, month2, day2, year2);
  else
    printf("%d/%d/%d is earlier than %d/%d/%d\n",
        month2, day2, year2, month1, day1, year1);

  return 0;
}
