#ifndef POISSON_H_INCLUDED
#define POISSON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

double mean(double a[100]); //定义mean 函数,用该函数计算k值在	10000个数据中出现的频率，即概率
int lsearch(int a[100],int x); //定义search函数,用该函数计算数值k在随机生成的100个数中出现的次数
void func(double prob); //定义function函数,用该函数判断是否满足泊松分布
double fact(int k);//定义fact函数，用该函数计算k的阶乘

double mean(double a[100])
{
    int i;//定义循环变量i
    double average,sum=0;//定义变量average用来保存100次随机生成数组中k出现的频率的平均数
    for(i=0; i<100; i++)
    {
        sum=sum+a[i];//累加
    }
    average=sum/100.0;//计算平均数
    return average;//返回结果
}

int lsearch(int a[100],int x)
{
    int i,counter=0; //定义循环变量i
    for(i=0; i<100; i++)
    {
        if(a[i]==x)
            counter++;//计算k值在数组中出现的次数
    }
    return counter; //返回结果
}
double fact(int k)
{
    double result;
    if(k==1||k==0)
        result=1;
    else
        result=k*fact(k-1);

    return result;
}
void func(double prob)
{
    int k;
    double r,c;//c表示k的阶乘
    r=100*prob;
    printf("请重新输入k值:");
    scanf("%d",&k);
    c=fact(k);
    if(prob*c==pow(r,k)*exp(-r))
        printf("%d服从参数为%.4lf的泊松分布",k,r);
    else
        printf("%d不服从参数为%.4lf的泊松分布",k,r);
}




#endif // POISSON_H_INCLUDED
