#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  double kg = 0, m = 0, BMI = 0;
  char a = "Standard!!\n", b ="You need management weight...\n" , res;

  printf("kg cm : ");
  scanf("%lf%lf", &kg, &m);

  m /= 100.0; // Convert cm to m
  BMI = kg / (m * m);

  //a = "Standard!!\n";
  //b = "You need management weight...\n";
  res = ((20.0 <= BMI) && (BMI < 25.0)) ? a : b;//printf("Standard!!\n") : printf("You need management weight!!\n");
  printf("%s", "res");

  return 0;
}