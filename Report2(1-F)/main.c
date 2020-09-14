#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int hour, min, sec;
  double time = 3.76;

  hour = (int)time;
  time -= hour;
  time *= 60.0;
  min = (int)time;
  time -= min;
  time *= 60.0;
  sec = (int)time;
  printf("3.76times %dhour %dmin %dsec.\n", hour, min, sec);

  return 0;
}