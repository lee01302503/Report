#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int ary[5] = { 1,2,3,4,5 };
  int* pa, * pb, * pc;
  int i;
  pa = (int*)malloc(sizeof(ary));

  for (i = 0; i < 5; i++)
  {
	pa[i] = ary[i];
  }

  pb = (int*)calloc(pa[3], sizeof(int));
  pc = (int*)realloc(NULL, pa[4]);

  printf("pa size : %d\n", sizeof(ary));
  printf("pb size : %d\n", sizeof(int)*pa[3]);
  printf("pc size : %d\n", sizeof(pc[5]));

  return 0;
}