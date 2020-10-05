#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a;

  printf("Enter the month as an intger : ");
  scanf("%d", &a);

  if ((1 <= a) && (a <= 12))//Print only between 1 and 12
  {
	if ((a == 1) || (a == 2) || (a == 12))//January, February, and December are set for winter
	{
	  printf("Winter");//Output in winter when conditions are met
	}
	else if ((a == 3) || (a == 4) || (a == 5))//March, Apriland May are set for spring
	{
	  printf("Spring");//Output in spring when conditions are met
	}
	else if ((a == 6) || (a == 7) || (a == 8))//June, July and August are set for summer
	{
	  printf("Summer");//Output in summer when conditions are met
	}
	else//The remaining September, October, and November are set to fall
	{
	  printf("Autumn");//Output in autumn when conditions are met
	}
  }
  else
  {
	printf("error...");//Error message out of range
  }


  return 0;
}