#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void sum(num);

int main(void)
{
  sum(10);
  sum(100);
  return 0;

}

void sum(num)
{
  int i;
  int res = 0;

  for (i = 0; i <= num; i++)
  {
	res += i;
  }
  printf("The sum of 1 to %d is %d.\n", num, res);
  return;
}