#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* made by Prof. Lee
*/
int main(void)
{
  double x[2]; // x절편
  double y[2]; // y절편
  double z[2]; // 임의의 한점
  double a[2]; // 직선 벡터
  double b;// 벡터의 크기
  double c[2];//직선 벡터의 방향 벡터
  double c1[2];// vector projecton
  double d[2]; // 주어진 점과 직선 위의 한 점으로 정의되는 벡터
  double distance;//거리
  int i, yn;
  printf("직선의 방적식 벡터로 변환\n");
  
  while (1)
  {
	printf("x1, x2 : \n");
	for (i = 0; i < 2; i++)
	{
	  scanf("%lf", &x[i]);
	}
	printf("x절편은 다음과 같습니다 : x1 : %.4lf, x2 : %.4lf\n", x[0], x[1]);
	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }

  printf("\n\n");

  while (1)
  {
	printf("y1, y2 : \n");
	for (i = 0; i < 2; i++)
	{
	  scanf("%lf", &y[i]);
	}
	printf("y절편은 다음과 같습니다 : y1 : %.4lf, y2 : %.4lf\n", y[0], y[1]);
	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }

  a[0] = (y[0] - x[0]);
  a[1] = (y[1] - x[1]);
  printf("직선 벡터 : (%.4lf)i + (%.4lf)j\n", a[0], a[1]);
  b = sqrt(pow(a[0], 2) + pow(a[1], 2));
  printf("벡터의 크기 : %.4lf\n", b);
  printf("\n");

  c[0] = ((1 / b) * a[0]);
  c[1] = ((1 / b) * a[1]);
  printf("직선벡터의 방향 벡터 : (%.4lf)i + (%.4lf)j\n", c[0], c[1]);

  printf("\n");
  printf("임의의 한점 입력\n");
  while (1)
  {
	printf("z1, z2 : \n");
	for (i = 0; i < 2; i++)
	{
	  scanf("%lf", &z[i]);
	}
	printf("임의의 한점은 다음과 같습니다 : z1 : %.4lf, z2 : %.4lf\n", z[0], z[1]);
	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }

  printf("주어진 점과 직선 위의 한 점으로 정의 되는 벡터\n");
  d[0] = (z[0] - y[0]);
  d[1] = (z[1] - y[1]);
  printf("(%.4lf)i + (%.4lf)j\n", d[0], d[1]);//주어진 점과 직선 위의 한 점으로 정의 되는 벡터

  printf("\n\n");
  printf("Vector projection\n");
  c1[0] = d[0] - (((d[0] * c[0]) + (d[1] * c[1])) * c[0]);//Vector projection i값
  c1[1] = d[1] - (((d[0] * c[0]) + (d[1] * c[1])) * c[1]);//Vector projection j값
  printf("Vector projection : (%.4lf) + (%.4lf)\n", c1[0], c1[1]);
  printf("\n\n");

  distance = sqrt(pow(c1[0], 2) + pow(c1[1], 2));
  printf("distance : %.4lf", distance);// 거리
  return 0;
}