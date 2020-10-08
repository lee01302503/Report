#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  double a, res;
  printf("enter input degree : ");//Angle input
  scanf("%lf", &a);

  res = (((int)a) % 360) - 180.0;//Converts the entered value from - 180 to 179
  
  
  printf("%.1lf = %.1lf", a, res);//Output conversion value

  return 0;
}