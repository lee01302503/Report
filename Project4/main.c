#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sum 0
#define min 1
#define muiti 2
#define tra 3
#define inve 4
/* made by Prof. Lee
*/
void func(void (*fp)(double a[3][3], double b[3][3]));//�Լ� �����͸� �Ű������� ���� �Լ� (3*3 ���)
void arr(double a[3][3]);			//��� ���
void add(double a[3][3], double b[3][3]);	//����
void sub(double a[3][3], double b[3][3]);	//����
void mul(double a[3][3], double b[3][3]);	//����
void transpose(double a[3][3]); // ��ġ���
void inverse(double a[3][3]); // �����
void func1(void (*fd)(double c[2][2], double d[2][2]));// �Լ� �����͸� �Ű������� ���� �Լ�(2*2���)
void arr1(double c[2][2]);			//��� ���
void add1(double c[2][2], double d[2][2]);	//����
void sub1(double c[2][2], double d[2][2]);	//����
void mul1(double c[2][2], double d[2][2]);	//����
void transpose1(double c[2][2]);// ��ġ���
void inverse1(double c[2][2]);//�����

void main()
{
  int num;//2*2 �Ǵ� 3*3��� ��ȣ ������ ����			

  printf("2*2����̸� 1��, 3*3����̸� 2�� : ");
  scanf("%d", &num);
  if (num == 1)
  {
	int sel;
	printf("0: ����, 1 : ����, 2 : ����, 3 : ��ġ���, 4 : �����");
	scanf("%d", &sel);

	switch (sel)
	{
	case sum:func1(add1); break;//0�̸� func1�� ���� ��� �߰�
	case min:func1(sub1); break;//1�̸� func1�� ���� ��� �߰�
	case muiti:func1(mul1); break;//2�̸� func1�� ���� ��� �߰�
	case tra: func1(transpose1); break;//3�̸� func1�� ��ġ��� ��� �߰�
	case inve:func1(inverse1); break;//4�̸� func1�� ����� ��� �߰�
	}
  }
  else if (num == 2)
  {
	int sel;
	printf("0: ����, 1 : ����, 2 : ����, 3 : ��ġ���, 4 : �����");
	scanf("%d", &sel);

	switch (sel)
	{
	case sum:func(add); break;//0�̸� func�� ���� ��� �߰�
	case min:func(sub); break;//1�̸� func�� ���� ��� �߰�
	case muiti:func(mul); break;//2�̸� func�� ���� ��� �߰�
	case tra: func(transpose); break;//3�̸� func�� ��ġ��� ��� �߰�
	case inve:func(inverse); break;//4�̸� func�� ����� ��� �߰�
	}
  }


}


void func(void (*fp)(double a[3][3], double b[3][3]))
{
  double a[3][3], b[3][3];
  int i, j, yn;
  printf("a����� �Է��Ͻÿ�\n"); //a��� �Է�

  while (1)//���� ���� - ��İ� �Է��� �ٸ� �� �ٽ� �Է�
  {

	for (i = 0; i < 3; i++)
	{
	  printf("%d ��: \n", i + 1);
	  for (j = 0; j < 3; j++)
	  {
		scanf("%lf", &a[i][j]);
	  }
	}

	printf("a ����� ������ �����ϴ�. \n");
	arr(a);

	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }


  printf("\n\n");


  printf("b����� �Է��Ͻÿ�\n"); //b��� �Է�

  while (1)//���� ���� - ��İ� �Է��� �ٸ� �� �ٽ� �Է�
  {

	for (i = 0; i < 3; i++)
	{
	  printf("%d ��: \n", i + 1);
	  for (j = 0; j < 3; j++)
	  {
		scanf("%lf", &b[i][j]);
	  }
	}

	printf("b ����� ������ �����ϴ�. \n");
	arr(b);

	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }

  fp(a, b);// �Լ� �����ͷ� ����Ű�� �Լ��� ȣ��
}

void arr(double a[3][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  printf("%.4lf\t", a[i][j]);
	}
	printf("\n");
  }
}
void add(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][j] + b[i][j];
	}
  }

  arr(c);
}
void sub(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][j] - b[i][j];
	}
  }

  arr(c);
}
void mul(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
	}
  }

  arr(c);
}
void transpose(double a[3][3])
{
  double transpose[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  transpose[i][j] = a[j][i];
	}
  }

  arr(transpose);
}

void inverse(double a[3][3])
{
  double inv[3][3];
  double determinant = 0;
  determinant = a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
  double idet = 1 / determinant;
  if (determinant == 0)
  {
	printf("No inverse matrix exists.\n");
  }
  else
  {
	inv[0][0] = (a[1][1] * a[2][2] - a[2][1] * a[1][2]) * idet;
	inv[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]) * idet;
	inv[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]) * idet;
	inv[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]) * idet;
	inv[1][1] = (a[0][0] * a[2][2] - a[0][2] * a[2][0]) * idet;
	inv[1][2] = (a[1][0] * a[0][2] - a[0][0] * a[1][2]) * idet;
	inv[2][0] = (a[1][0] * a[2][1] - a[2][0] * a[1][1]) * idet;
	inv[2][1] = (a[2][0] * a[0][1] - a[0][0] * a[2][1]) * idet;
	inv[2][2] = (a[0][0] * a[1][1] - a[1][0] * a[0][1]) * idet;
  }

  arr(inv);
}

void func1(void (*fd)(double c[2][2], double d[2][2]))
{
  double c[2][2], d[2][2];	//�迭 �ʱ�ȭ
  int i, j, yn;
  printf("a����� �Է��Ͻÿ�\n"); //a��� �Է�

  while (1)//���� ���� - ��İ� �Է��� �ٸ� �� �ٽ� �Է�
  {

	for (i = 0; i < 2; i++)
	{
	  printf("%d ��: \n", i + 1);
	  for (j = 0; j < 2; j++)
	  {
		scanf("%lf", &c[i][j]);
	  }
	}

	printf("a ����� ������ �����ϴ�. \n");
	arr1(c);

	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }


  printf("\n\n");


  printf("b����� �Է��Ͻÿ�\n"); //b��� �Է�

  while (1)//���� ���� - ��İ� �Է��� �ٸ� �� �ٽ� �Է�
  {

	for (i = 0; i < 2; i++)
	{
	  printf("%d ��: \n", i + 1);
	  for (j = 0; j < 2; j++)
	  {
		scanf("%lf", &d[i][j]);
	  }
	}

	printf("b ����� ������ �����ϴ�. \n");
	arr1(d);

	printf("�Է��� ���� �½��ϱ�? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//���� �� break
	  break;
  }

  fd(c, d); //�Լ� �����ͷ� ����Ű�� �Լ��� ȣ��
}

void arr1(double c[2][2])
{
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  printf("%.4lf\t", c[i][j]);
	}
	printf("\n");
  }
}
void add1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][j] + d[i][j];
	}
  }

  arr1(e);
}
void sub1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][j] - d[i][j];
	}
  }

  arr1(e);
}
void mul1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][0] * d[0][j] + c[i][1] * d[1][j];
	}
  }

  arr1(e);
}

void transpose1(double c[2][2])
{
  double transpose[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  transpose[i][j] = c[j][i];
	}
  }

  arr1(transpose);
}

void inverse1(double c[2][2])
{
  double d;
  double inv[2][2];
  d = c[0][0] * c[1][1] - c[0][1] * c[1][0];
  if (d == 0)
  {
	printf("����� �������� ����!!");
	return 0;
  }
  else
  {
	inv[0][0] = c[1][1] / d;
	inv[0][1] = -c[0][1] / d;
	inv[1][0] = -c[1][0] / d;
	inv[1][1] = c[0][0] / d;
  }

  arr1(inv);
}