#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "poisson.h"


int main(void)
{
    int i,j,k,count,random[100];//定义循环变量i和j,整数型变量count，随机数组random[100]
    double p[100],prob;
    printf("请输入k值:");//k为X可能的取值
    scanf("%d",&k);
    for(j=0; j<100; j++)
    {
        srand((unsigned)time(NULL));
        printf("第%d组随机生成0~100的数: \n",j+1);
        for (i = 0; i < 100; i++)
        {
            int num = rand()%100+1;//对100取余操作
            random[i]=num;
            printf("% 4d",random[i]);
            if((i+1)%10==0) printf("\n");
        }
        count=lsearch(random,k);
        p[j]=count/100.0;
        printf("%d在第%d组中的概率为%.2lf\n",k,j+1,p[j]); //输出数值k在随机生成的100个数中出现的频率
        printf("\n");
    }
    printf("\n");
    prob=mean(p);//调用mean函数
    printf("%d出现的概率为:%.4lf",k,prob);//输出k值在10000个数据中出现的频率，即概率
    printf("\n");
    func(prob);//调用函数function

    return 0;
}


