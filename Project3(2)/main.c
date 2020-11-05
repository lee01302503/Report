#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* made by Prof. Lee
*/
int main(void)
{
  double x[2]; // x����
  double y[2]; // y����
  double z[2]; // ������ ����
  double a[2]; // ���� ����
  double b;// ������ ũ��
  double c[2];//���� ������ ���� ����
  double c1[2];// vector projecton
  double d[2]; // �־��� ���� ���� ���� �� ������ ���ǵǴ� ����
  double distance;//�Ÿ�
  int i, yn;
  printf("������ ������ ���ͷ� ��ȯ\n");
  
  while (1)
  {
	printf("x1, x2 : \n");
	for (i = 0; i < 2; i++)
	{
	  scanf("%lf", &x[i]);
	}
	printf("x������ ������ �����ϴ� : x1 : %.4lf, x2 : %.4lf\n", x[0], x[1]);
	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
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
	printf("y������ ������ �����ϴ� : y1 : %.4lf, y2 : %.4lf\n", y[0], y[1]);
	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }

  a[0] = (y[0] - x[0]);
  a[1] = (y[1] - x[1]);
  printf("���� ���� : (%.4lf)i + (%.4lf)j\n", a[0], a[1]);
  b = sqrt(pow(a[0], 2) + pow(a[1], 2));
  printf("������ ũ�� : %.4lf\n", b);
  printf("\n");

  c[0] = ((1 / b) * a[0]);
  c[1] = ((1 / b) * a[1]);
  printf("���������� ���� ���� : (%.4lf)i + (%.4lf)j\n", c[0], c[1]);

  printf("\n");
  printf("������ ���� �Է�\n");
  while (1)
  {
	printf("z1, z2 : \n");
	for (i = 0; i < 2; i++)
	{
	  scanf("%lf", &z[i]);
	}
	printf("������ ������ ������ �����ϴ� : z1 : %.4lf, z2 : %.4lf\n", z[0], z[1]);
	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }

  printf("�־��� ���� ���� ���� �� ������ ���� �Ǵ� ����\n");
  d[0] = (z[0] - y[0]);
  d[1] = (z[1] - y[1]);
  printf("(%.4lf)i + (%.4lf)j\n", d[0], d[1]);//�־��� ���� ���� ���� �� ������ ���� �Ǵ� ����

  printf("\n\n");
  printf("Vector projection\n");
  c1[0] = d[0] - (((d[0] * c[0]) + (d[1] * c[1])) * c[0]);//Vector projection i��
  c1[1] = d[1] - (((d[0] * c[0]) + (d[1] * c[1])) * c[1]);//Vector projection j��
  printf("Vector projection : (%.4lf) + (%.4lf)\n", c1[0], c1[1]);
  printf("\n\n");

  distance = sqrt(pow(c1[0], 2) + pow(c1[1], 2));
  printf("distance : %.4lf", distance);// �Ÿ�
  return 0;
}