#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static double a = 100;
static double b = 100;

double cost(double x, double y);

double avg(double* aData);

double* partD(double* aX, double* aY);

double mse(double* aX, double* aY);

int main()
{

  FILE* readFile = NULL;
  FILE* writeFile = NULL;

  double aX[100];
  double aY[100];

  double aResult[1000];

  double learningRate = 0.1;
  printf("a = %lf \tb = %lf\n", a, b);

  if (0 == fopen_s(&readFile, "dataset_for_project.csv", "r"))
  {
    for (int i = 0; i < 100; i++)
    {
      char str[1000] = "";
      fscanf(readFile, "%s", str);
      aX[i] = atof(strtok(str, ","));
      aY[i] = atof(strtok(str, ","));
    }
    fclose(readFile);
  }
  else
  {
    printf("해당 파일이 존재하지 않습니다.");
  }

  int i = 0;

  for (i = 0; i < 1000; i++)
  {
    //비용함수 편미분 구하기
    double* aPartD = partD(aX, aY);

    //10번 시행마다 a와 b 출력
    printf("a = %lf \tb = %lf\n", a, b);

    //a와 b의 값 조정
    a -= learningRate * aPartD[0];
    b -= learningRate * aPartD[1];


    aResult[i] = mse(aX, aY);

    if (i != 0)
    {
      if (aResult[i - 1] <= aResult[i])
      {
        break;
      }
    }
  }

  fopen_s(&writeFile, "result.txt", "w");
  fprintf(writeFile, "a = %lf\t b = %lf", a, b);
  fclose(writeFile);

  return 0;
}

double mse(double* aX, double* aY)
{
  double aCost[100];

  for (int i = 0; i < 100; i++)
  {
    aCost[i] = cost(aX[i], aY[i]);
  }
  return avg(aCost);
}

double cost(double x, double y)
{
  double preData = a * x + b;
  return (preData - y) * (preData - y);
}

double avg(double* aData)
{
  double sum = 0;
  for (int i = 0; i < 100; i++)
  {
    sum += aData[i];
  }
  return sum / 100;
}

double* partD(double* aX, double* aY)
{
  double aResultA[100];
  double aResultB[100];
  double aResult[2];

  for (int i = 0; i < 100; i++)
  {
    aResultA[i] = 2 * aX[i] * aX[i] * a - aX[i] * aY[i] + aX[i] * b;
    aResultB[i] = 2 * b - aY[i] + aX[i] * a;
  }
  aResult[0] = avg(aResultA);
  aResult[1] = avg(aResultB);

  return aResult;
}