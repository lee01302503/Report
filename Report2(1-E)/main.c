#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a, b, tot;
  double avg;

  printf("Two subject score : ");
  scanf("%d%d", &a, &b);
  tot = a + b;
  avg = tot / 2.0;

  printf("Avg : %.1lf\n", avg);

  return 0;
}