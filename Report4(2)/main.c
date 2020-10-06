#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a,i,j;
  int n;//prime number
  int cnt = 0;
  printf("Please enter an integer greater than 2 : ");
  scanf("%d", &a);

  if (2<=a)//input number greater 2
  {
	for (i = 2; i < a; i++)//Starting at 2 and increasing until the number entered
	{
	  n = 1;//prime number
	  for (j = 2; j < i; j++)
	  {
		if (i % j == 0)// not prime number
		{
		  n = 0;
		  break;
		}
	  }
	  if (n == 1)
	  {
		printf("%5d", i);// 5 spaces up
		cnt++;//Increment number input per line.
		if(cnt % 5==0)//This is the condition when the number in a line is a multiple of 5
		{
		  printf("\n");//If the conditions are met, move the cursor down.
		}
	  }
	}
  }
  else//Write an error message when entering a number less than 2
  {
	printf("Error... Please enter an integer greater than 2");
  }
  return 0;
}