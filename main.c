#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "poisson.h"
double mean(double a[100]); //定义mean 函数,用该函数计算k值在	10000个数据中出现的频率，即概率
int search(int a[100],int x); //定义search函数,用该函数计算数值k在随机生成的100个数中出现的次数
double function(double prob); //定义function函数,用该函数判断是否满足泊松分布
double fact(int k);//定义fact函数，用该函数计算k的阶乘

int main(void)
{
    int i,j,k,count,random[100];//定义循环变量i和j,整数型变量count，随机数组random[100]
    double p[100],prob;
    printf("请输入k值");//k为X可能的取值
    scanf("%d",&k);
    for(j=0; j<100; j++)
    {
        for (i = 0; i < 100; i++)
        {
            int num = rand()%100+1;//对100取余操作
            random[i]=num;
            printf("第%d次随机生成0~100的数: %d \n",i+1,random[i]);
        }
        count=search(random,k);
        printf("出现次数为%d\n",count);//输出数值k在随机生成的100个数中出现的次数
        p[j]=count/100.0;
        printf("%d出现的频率为%lf\n",k,p[j]); //输出数值k在随机生成的100个数中出现的频率

        printf("\n");
    }
    printf("\n");
    prob=mean(p);//调用mean函数
    printf("%d出现的概率为:%lf",k,prob);//输出k值在10000个数据中出现的频率，即概率
    printf("\n");
    function(prob);//调用函数function

    return 0;
}


