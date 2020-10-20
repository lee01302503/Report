#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
double centi_to_meter(int cm);

int main(void)
{
  double res;

  res = centi_to_meter(187);
  printf("%.2lfm\n", res);

  return 0;
}

double centi_to_meter(int cm)
{
  double meter;
  meter = cm / 100.0;
  return(meter);
}