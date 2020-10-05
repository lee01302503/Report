#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a;
  printf("Please enter the year : ");//enter year
  scanf("%d", &a);

  if (((a % 4) == 0) || ((a % 400) == 0))//Dividing the year by 4, 100 and 400 is a leap year.
  {
	printf("%d : leap year", a);//Output as leap year of the year
  }
  else//A year divided only by 4 and 100 is a normal year
  {
	printf("%d : common year", a);//Output of the common year of the year
  }

  return 0;
}