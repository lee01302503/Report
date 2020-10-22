#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void swap(int* pa, int *pb);

int main(void)
{
  int a = 10, b = 20;
  int* pa = &a, * pb = &b, * pt;
  pt = pa;
  pa = pb;
  pb = pt;
  printf("%d, %d", *pa, *pb);

  return 0;
}