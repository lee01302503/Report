#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* made by Prof. Lee
*/
int nRandom(void);

int main(void)
{
  int a;
  char b;
  while (1)
  {
	printf("frontside(1), backside(0) : ");
	scanf("%d", &a);
	if ((0 <= a) && (a <= 1))// Execute when the entered number is 1 and 0
	{
	  if (a == nRandom())//Matches any number
	  {
		printf("Success!!!\n");
	  }
	  else//Doesn't match any number.
	  {
		printf("Different....\n");
	  }
	  printf("continue???( y or n)");
	  getchar();//clean buffer
	  scanf("%c", &b);
	  if (b == 'n')
		break;
	  else if (b == 'y')
		continue;
	}
	else
	{
	  printf("Please check number....\n");
	}
	
  }
}

int nRandom(void)//Specify random number function
{
  int a;
  srand((unsigned)(time(NULL)));//Random number initialization
  a = rand() % 2;//Takes 0 and 1 using the coefficient operator.
  return a;
}