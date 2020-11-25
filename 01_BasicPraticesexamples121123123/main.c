#include <stdio.h>
#define addtion 1
#define min 2
#define multi 3
#define tran 4
#define inv 5

void func(void (*fp)(int a[3][3], int b[3][3]));//�Լ� �����͸� �Ű������� ���� �Լ� (3*3 ���)
void prn(int a[3][3]);  // ���Ȯ�� �Լ�
void add(int a[3][3], int b[3][3]);  //���� �Լ�
void sub(int a[3][3], int b[3][3]);  //���� �Լ�
void mul(int a[3][3], int b[3][3]);  //���� �Լ�
void transpose(int a[3][3]);
void func1(void (*fp)(int c[2][2], int d[2][2]));//�Լ� �����͸� �Ű������� ���� �Լ� (3*3 ���)
void prn1(int a[2][2]);  // ���Ȯ�� �Լ�
void add1(int c[2][2], int d[2][2]);  //���� �Լ�
void sub1(int c[2][2], int d[2][2]);  //���� �Լ�
void mul1(int c[2][2], int d[2][2]);  //���� �Լ�
void transpose1(int c[2][2]);
void inverse1(int c[2][2]);

void main()
{
  int num;
  printf("1:3*3, 2:2*2");
  scanf("%d", &num);
  if (num == 1)
  {
    int sel;
    printf("1: ����, 2: ����, 3: ����, 4: ��ġ���");
    scanf("%d", &sel);

    switch (sel)
    {
    case addtion:func(add); break;//1�̸� func�� ���� ��� �߰�
    case min:func(sub); break;//2�̸� func�� ���� ��� �߰�
    case multi:func(mul); break;//3�̸� func�� ���� ��� �߰�
    case tran: func(transpose); break;//4�̸� func�� ��ġ��� ��� �߰�
    }
  }
  else if (num == 2)
  {
    int sel;
    printf("1: ����, 2: ����, 3: ����, 4: ��ġ���, 5: �����");
    scanf("%d", &sel);

    switch (sel)
    {
    case addtion:func1(add1); break;//1�̸� func�� ���� ��� �߰�
    case min:func1(sub1); break;//2�̸� func�� ���� ��� �߰�
    case multi:func1(mul1); break;//3�̸� func�� ���� ��� �߰�
    case tran: func1(transpose1); break;//4�̸� func�� ��ġ��� ��� �߰�
    case inv:func1(inverse1); break;//5�̸� func�� ����� ��� �߰�
    }
  }
}

void func(void (*fp)(int a[3][3], int b[3][3]))
{
  int a[3][3], b[3][3];
  int i, j, check;

  printf("a ��İ��� �Է��Ͻÿ�\n");

  while (1)
  {
    for (i = 0; i < 3; i++)
    {
      printf("%d ��: \n", i + 1);
      for (j = 0; j < 3; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }

    printf("a ����Դϴ�.\n");
    prn(a);

    printf("�Է��� ����� �½��ϱ�? YES(1), NO(2)");
    scanf("%d", &check);

    if (check == 1)
      break;

  }

  printf("\n\n");

  printf("b ��İ��� �Է��Ͻÿ�\n");

  while (1)
  {
    for (i = 0; i < 3; i++)
    {
      printf("%d ��: \n", i + 1);
      for (j = 0; j < 3; j++)
      {
        scanf("%d", &b[i][j]);

      }

    }
    printf("b ����Դϴ�. \n");
    prn(b);

    printf("�Է��� ����� �½��ϱ�? YES(1), NO(2)");
    scanf("%d", &check);

    if (check == 1)
      break;
  }

  fp(a, b);
}

void prn(int a[3][3])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%3d", a[i][j]);

    }
    printf("\n");

  }
}

void add(int a[3][3], int b[3][3])  //���� �Լ�
{
  int c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  prn(c);
}

void sub(int a[3][3], int b[3][3])  //���� �Լ�
{
  int c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
  prn(c);

}
void mul(int a[3][3], int b[3][3])
{
  int c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
    }
  }
  prn(c);
}

void transpose(int a[3][3])
{
  int transpose[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      transpose[i][j] = a[j][i];
    }
  }

  prn(transpose);
}

void func1(void (*fp)(int c[2][2], int d[2][2]))
{
  int c[2][2], d[2][2];
  int i, j, check;

  printf("a ��İ��� �Է��Ͻÿ�\n");

  while (1)
  {
    for (i = 0; i < 2; i++)
    {
      printf("%d ��: \n", i + 1);
      for (j = 0; j < 2; j++)
      {
        scanf("%d", &c[i][j]);
      }
    }

    printf("a ����Դϴ�.\n");
    prn1(c);

    printf("�Է��� ����� �½��ϱ�? YES(1), NO(2)");
    scanf("%d", &check);

    if (check == 1)
      break;

  }

  printf("\n\n");

  printf("b ��İ��� �Է��Ͻÿ�\n");

  while (1)
  {
    for (i = 0; i < 2; i++)
    {
      printf("%d ��: \n", i + 1);
      for (j = 0; j < 2; j++)
      {
        scanf("%d", &d[i][j]);

      }

    }
    printf("b ����Դϴ�. \n");
    prn1(d);

    printf("�Է��� ����� �½��ϱ�? YES(1), NO(2)");
    scanf("%d", &check);

    if (check == 1)
      break;
  }

  fp(c, d);
}

void prn1(int c[2][2])
{
  int i, j;
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("%3d", c[i][j]);

    }
    printf("\n");

  }
}

void add1(int c[2][2], int d[2][2])  //���� �Լ�
{
  int x[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      x[i][j] = c[i][j] + d[i][j];
    }
  }
  prn1(x);
}

void sub1(int c[2][2], int d[2][2])  //���� �Լ�
{
  int x[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      x[i][j] = c[i][j] - d[i][j];
    }
  }
  prn1(x);

}
void mul1(int c[2][2], int d[2][2])
{
  int x[2][2];
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      x[i][j] = c[i][0] * d[0][j] + c[i][1] * d[1][j] +c[i][2] * d[2][j];
    }
  }
  prn1(x);
}

void transpose1(int c[2][2])
{
  int transpose[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      transpose[i][j] = c[j][i];
    }
  }

  prn1(transpose);
}

void inverse1(int c[2][2])
{
  int d;
  int inverse1[2][2];
  d = c[0][0] * c[1][1] - c[0][1] * c[1][0];
  if (d == 0)
  {
    printf("����� �������� ����!!");
    return 0;
  }
  else
  {
    inverse1[0][0] = c[1][1] / d;
    inverse1[0][1] = -c[0][1] / d;
    inverse1[1][0] = -c[1][0] / d;
    inverse1[1][1] = c[0][0] / d;
  }

  prn1(inverse1);
}