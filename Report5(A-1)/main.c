#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
double average(double a, double b);

int main(void)
{
  double res;
  res = average(1.5, 3.4);
  printf("Result : %.1lf", res);
}

double average(double a, double b)
{
  double temp;
  temp = a + b;
  return(temp / 2.0);
}