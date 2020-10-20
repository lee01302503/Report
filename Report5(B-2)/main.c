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
  printf("1부터 %d까지의 합은 %d입니다.\n", num, res);
  return;
}