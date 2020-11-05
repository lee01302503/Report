#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void arr(double a[3][3]);			//행렬 출력
void add(double a[3][3], double b[3][3]);	//덧셈
void sub(double a[3][3], double b[3][3]);	//뺄셈
void mul(double a[3][3], double b[3][3]);	//곱셈
void transpose(double a[3][3]); // 전치행렬
void inverse(double a[3][3]); // 역행렬
void arr1(double c[2][2]);			//행렬 출력
void add1(double c[2][2], double d[2][2]);	//덧셈
void sub1(double c[2][2], double d[2][2]);	//뺄셈
void mul1(double c[2][2], double d[2][2]);	//곱셈
void transpose1(double c[2][2]);// 전치행렬
void inverse1(double c[2][2]);//역행렬

void main()
{
  double a[3][3], b[3][3];
  double c[2][2], d[2][2];	//배열 초기화
  int i, j, cho, yn, num;			//i,j는 for문 cho는 연산자 선택 yn은 행렬값 확인시 사용

  printf("2*2행렬이면 1번, 3*3행렬이면 2번 : ");
  scanf("%d", &num);
  if (num == 1)
  {
	printf("a행렬을 입력하시오\n"); //a행렬 입력

	while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
	{

	  for (i = 0; i < 2; i++)
	  {
		printf("%d 행: \n", i + 1);
		for (j = 0; j < 2; j++)
		{
		  scanf("%lf", &c[i][j]);
		}
	  }

	  printf("a 행렬은 다음과 같습니다. \n");
	  arr1(c);

	  printf("입력한 값이 맞습니까? YES[1], NO[2]");
	  scanf("%d", &yn);

	  if (yn == 1)				//맞을 시 break
		break;
	}


	printf("\n\n");


	printf("b행렬을 입력하시오\n"); //b행렬 입력

	while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
	{

	  for (i = 0; i < 2; i++)
	  {
		printf("%d 행: \n", i + 1);
		for (j = 0; j < 2; j++)
		{
		  scanf("%lf", &d[i][j]);
		}
	  }

	  printf("b 행렬은 다음과 같습니다. \n");
	  arr1(d);

	  printf("입력한 값이 맞습니까? YES[1], NO[2]");
	  scanf("%d", &yn);

	  if (yn == 1)				//맞을 시 break
		break;
	}

	printf("\n\n");

	printf("다음중 어떤 연산을 할 것입니까?");
	printf("[1]덧셈 [2]뺄셈 [3]곱셈 [4]전치행렬 [5]역행렬\n");
	scanf("%d", &cho);

	if (cho == 1)
	  add1(c, d);
	else if (cho == 2)
	  sub1(c, d);
	else if (cho == 3)
	  mul1(c, d);
	else if (cho == 4)
	  transpose1(c);
	else if (cho == 5)
	  inverse1(c);
  }
  else if (num == 2)
  {
	printf("a행렬을 입력하시오\n"); //a행렬 입력

	while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
	{

	  for (i = 0; i < 3; i++)
	  {
		printf("%d 행: \n", i + 1);
		for (j = 0; j < 3; j++)
		{
		  scanf("%lf", &a[i][j]);
		}
	  }

	  printf("a 행렬은 다음과 같습니다. \n");
	  arr(a);

	  printf("입력한 값이 맞습니까? YES[1], NO[2]");
	  scanf("%d", &yn);

	  if (yn == 1)				//맞을 시 break
		break;
	}


	printf("\n\n");


	printf("b행렬을 입력하시오\n"); //b행렬 입력

	while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
	{

	  for (i = 0; i < 3; i++)
	  {
		printf("%d 행: \n", i + 1);
		for (j = 0; j < 3; j++)
		{
		  scanf("%lf", &b[i][j]);
		}
	  }

	  printf("b 행렬은 다음과 같습니다. \n");
	  arr(b);

	  printf("입력한 값이 맞습니까? YES[1], NO[2]");
	  scanf("%d", &yn);

	  if (yn == 1)				//맞을 시 break
		break;
	}

	printf("\n\n");

	printf("다음중 어떤 연산을 할 것입니까?");
	printf("[1]덧셈 [2]뺄셈 [3]곱셈 [4]전치행렬 [5]역행렬\n");
	scanf("%d", &cho);

	if (cho == 1)
	  add(a, b);
	else if (cho == 2)
	  sub(a, b);
	else if (cho == 3)
	  mul(a, b);
	else if (cho == 4)
	  transpose(a);
	else if (cho == 5)
	  inverse(a);
  }


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
  int i, j;
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
	printf("역행렬 존재하지 않음!!");
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