#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);
int main(void)
{
  double max, mid, min;

  printf("real number3 input : ");
  scanf("%lf%lf%lf", &max, &mid, &min);
  line_up(&max, &mid, &min);
  printf("Sorted values : %.1lf, %.1lf, %.1lf", max, mid, min);
}

void swap(double *pa, double *pb)
{
  double temp;

  temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
  if (*maxp < *midp)
  {
	swap(maxp, midp);
  }
  if (*maxp < *minp)
  {
	swap(maxp, minp);
  }
  if (*midp < *minp)
  {
	swap(midp, minp);
  }
}