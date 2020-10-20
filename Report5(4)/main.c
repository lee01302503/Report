#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* made by Prof. Lee
*/
double Euclideandistance(double x1, double x2, double y1, double y2);//Specify the Euclideandistance function

int main(void)
{
  double x1, x2 = 0.0;
  double y1, y2 = 0.0;

  printf("Enter point(x1, x2) : \n");//Enter distance
  scanf("%lf%lf", &x1, &x2);
  printf("Enter point(y1, y2) : \n");//Enter distance
  scanf("%lf%lf", &y1, &y2);

  printf("Euclidean distance : %.4lf\n", Euclideandistance( x1, x2, y1, y2));
}

double Euclideandistance(double x1, double x2, double y1, double y2)
{
  double  Euclideandistance;
  Euclideandistance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));//Using the sqrt function and the pow function
  return Euclideandistance;
}
