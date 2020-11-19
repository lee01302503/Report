#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* made by Prof. Lee
*/
int main(void)
{
  struct position {
    double x[2]; //x����
    double y[2]; //y����
  };

  struct vector {
    double z[2]; // ������ ����
    double a[2]; // ���� ����
    double b;// ������ ũ��
    double c[2];//���� ������ ���� ����
    double c1[2];// vector projecton
    double d[2]; // �־��� ���� ���� ���� �� ������ ���ǵǴ� ����
    double distance;//�Ÿ�
  };

  struct position pos;
  struct vector vec;


  int i, yn;
  printf("������ ������ ���ͷ� ��ȯ\n");

  while (1)
  {
    printf("x1, x2 : \n");
    for (i = 0; i < 2; i++)
    {
      scanf("%lf", &pos.x[i]);
    }
    printf("x������ ������ �����ϴ� : x1 : %.4lf, x2 : %.4lf\n", pos.x[0], pos.x[1]);
    printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //���� �� break
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
    printf("y������ ������ �����ϴ� : y1 : %.4lf, y2 : %.4lf\n", pos.y[0], pos.y[1]);
    printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //���� �� break
      break;
  }

  vec.a[0] = (pos.y[0] - pos.x[0]);
  vec.a[1] = (pos.y[1] - pos.x[1]);
  printf("���� ���� : (%.4lf)i + (%.4lf)j\n", vec.a[0], vec.a[1]);
  vec.b = sqrt(pow(vec.a[0], 2) + pow(vec.a[1], 2));
  printf("������ ũ�� : %.4lf\n", vec.b);
  printf("\n");

  vec.c[0] = ((1 / vec.b) * vec.a[0]);
  vec.c[1] = ((1 / vec.b) * vec.a[1]);
  printf("���������� ���� ���� : (%.4lf)i + (%.4lf)j\n", vec.c[0], vec.c[1]);

  printf("\n");
  printf("������ ���� �Է�\n");
  while (1)
  {
    printf("z1, z2 : \n");
    for (i = 0; i < 2; i++)
    {
      scanf("%lf", &vec.z[i]);
    }
    printf("������ ������ ������ �����ϴ� : z1 : %.4lf, z2 : %.4lf\n", vec.z[0], vec.z[1]);
    printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
    scanf("%d", &yn);

    if (yn == 1)            //���� �� break
      break;
  }

  printf("�־��� ���� ���� ���� �� ������ ���� �Ǵ� ����\n");
  vec.d[0] = (vec.z[0] - pos.y[0]);
  vec.d[1] = (vec.z[1] - pos.y[1]);
  printf("(%.4lf)i + (%.4lf)j\n", vec.d[0], vec.d[1]);//�־��� ���� ���� ���� �� ������ ���� �Ǵ� ����

  printf("\n\n");
  printf("Vector projection\n");
  vec.c1[0] = vec.d[0] - (((vec.d[0] * vec.c[0]) + (vec.d[1] * vec.c[1])) * vec.c[0]);//Vector projection i��
  vec.c1[1] = vec.d[1] - (((vec.d[0] * vec.c[0]) + (vec.d[1] * vec.c[1])) * vec.c[1]);//Vector projection j��
  printf("Vector projection : (%.4lf) + (%.4lf)\n", vec.c1[0], vec.c1[1]);
  printf("\n\n");

  vec.distance = sqrt(pow(vec.c1[0], 2) + pow(vec.c1[1], 2));
  printf("distance : %.4lf", vec.distance);// �Ÿ�
  return 0;
}

