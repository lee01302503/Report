#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* made by Prof. Lee
*/
int main(void)
{
  struct position {
    double x[2]; //x절편
    double y[2]; //y절편
  };

  struct vector {
    double z[2]; // 임의의 한점
    double a[2]; // 직선 벡터
    double b;// 벡터의 크기
    double c[2];//직선 벡터의 방향 벡터
    double c1[2];// vector projecton
    double d[2]; // 주어진 점과 직선 위의 한 점으로 정의되는 벡터
    double distance;//거리
  };

  struct position pos;
  struct vector vec;


  int i, yn;
  printf("직선의 방적식 벡터로 변환\n");

  while (1)
  {
    printf("x1, x2 : \n");
    for (i = 0; i < 2; i++)
    {
      scanf("%lf", &pos.x[i]);
    }
    printf("x절편은 다음과 같습니다 : x1 : %.4lf, x2 : %.4lf\n", pos.x[0], pos.x[1]);
    printf("입력한 값이 맞습니까? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //맞을 시 break
      break;
  }

  printf("\n\n");

  while (1)
  {
    printf("y1, y2 : \n");
    for (i = 0; i < 2; i++)
    {
      scanf("%lf", &pos.y[i]);
    }
    printf("y절편은 다음과 같습니다 : y1 : %.4lf, y2 : %.4lf\n", pos.y[0], pos.y[1]);
    printf("입력한 값이 맞습니까? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //맞을 시 break
      break;
  }

  vec.a[0] = (pos.y[0] - pos.x[0]);
  vec.a[1] = (pos.y[1] - pos.x[1]);
  printf("직선 벡터 : (%.4lf)i + (%.4lf)j\n", vec.a[0], vec.a[1]);
  vec.b = sqrt(pow(vec.a[0], 2) + pow(vec.a[1], 2));
  printf("벡터의 크기 : %.4lf\n", vec.b);
  printf("\n");

  vec.c[0] = ((1 / vec.b) * vec.a[0]);
  vec.c[1] = ((1 / vec.b) * vec.a[1]);
  printf("직선벡터의 방향 벡터 : (%.4lf)i + (%.4lf)j\n", vec.c[0], vec.c[1]);

  printf("\n");
  printf("임의의 한점 입력\n");
  while (1)
  {
    printf("z1, z2 : \n");
    for (i = 0; i < 2; i++)
    {
      scanf("%lf", &vec.z[i]);
    }
    printf("임의의 한점은 다음과 같습니다 : z1 : %.4lf, z2 : %.4lf\n", vec.z[0], vec.z[1]);
    printf("입력한 값이 맞습니까? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //맞을 시 break
      break;
  }

  printf("주어진 점과 직선 위의 한 점으로 정의 되는 벡터\n");
  vec.d[0] = (vec.z[0] - pos.y[0]);
  vec.d[1] = (vec.z[1] - pos.y[1]);
  printf("(%.4lf)i + (%.4lf)j\n", vec.d[0], vec.d[1]);//주어진 점과 직선 위의 한 점으로 정의 되는 벡터

  printf("\n\n");
  printf("Vector projection\n");
  vec.c1[0] = vec.d[0] - (((vec.d[0] * vec.c[0]) + (vec.d[1] * vec.c[1])) * vec.c[0]);//Vector projection i값
  vec.c1[1] = vec.d[1] - (((vec.d[0] * vec.c[0]) + (vec.d[1] * vec.c[1])) * vec.c[1]);//Vector projection j값
  printf("Vector projection : (%.4lf) + (%.4lf)\n", vec.c1[0], vec.c1[1]);
  printf("\n\n");

  vec.distance = sqrt(pow(vec.c1[0], 2) + pow(vec.c1[1], 2));
  printf("distance : %.4lf", vec.distance);// 거리
  return 0;
}

