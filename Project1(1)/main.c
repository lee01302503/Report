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

  if (a >= 360.0)//More than 360 degrees
  {
	a -= (((int)a / 360) * 360.0);//Divide the number you entered by 360 degrees, multiply the quotient by 360, and store it in the variable a
	res = a - 180.0;//Subtract 180 again from the stored variable a.
	printf("%.1lf", res);//Output the result value
  }

  else//Less than 360 degrees
  {
	res = a - 180.0;//Subtract 180 degrees from the input value
	printf("%.1lf", res);//Output the result value
  }

  return 0;
}