#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A_PRN printf("Standard!!\n")
#define B_PRN printf("You need weight management!!\n")
#pragma warning(disable:6031)

/* made by Prof. Lee
*/
int main(void)
{
  double kg = 0, m = 0;
  double BMI = 0;

  printf("kg, cm : ");
  scanf("%lf%lf", &kg, &m);

  m /= 100; // Convert cm to m
  BMI = kg / (m * m);

  if((20.0 <= BMI) && (BMI < 25.0)) A_PRN;

  else B_PRN;

  return 0;
}