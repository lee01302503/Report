#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int func(int n);
int poly(int n);

int main(void)
{
  printf("%d\n", func(-3));
  return 0;
}

int func(int n)
{
  int res;
  res = poly(n);
  if (res >= 0) return;
  else return -res;
}

int poly(int n)
{
  return((2 * n * n) + (3 * n));
}