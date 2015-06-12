/*
ID:lxxxsou1
PROG:  pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>

using namespace std;//回文的运算使用折叠法 偶数折叠与奇数折叠    偶数 1-9 1-9 奇数 1-9 1-9 1-9
int a,b;
int ppr[1000000];
int p=0;

bool is_prime(int num)
{
    int i;
    for (i =2; i*i <=num; i++)
  	{
        if (num %i ==0)
        return false;
  	}
    return true;
}
void gen(int num,int is_odd)
{
    int num_N[10];
    double m;
    int num1;
    int sum,i,j,k,r,len;
    num1=num;
    for(len=0;num1!=0;len++)
    {
        num1=num1/10;
    }
    for(i=0;num!=0;i++)
    {
        r=num%10;
        num_N[len-i-1]=r;
        num=num/10;
    }
    if(is_odd==1)
    {
        for(j=i+1;j<=2*i;j++)
            num_N[j]=num_N[2*i-j];
        for(k=0;k<=9;k++)
        {
            num_N[i]=k;
            sum=0;
            for(j=2*i;j>=0;j--)
            {
                m=pow(10,2*i-j);
                sum+=num_N[j]*m;
            }
            if(sum>=a&&sum<=b)
            {
                if(is_prime(sum))
                {
                    ppr[p]=sum;
                    p++;
                }
            }
        }
    }
    if(is_odd==0)
    {
        for(j=i;j<2*i;j++)
            num_N[j]=num_N[2*i-j-1];
        sum=0;
        for(j=2*i-1;j>=0;j--)
        {
            m=pow(10,2*i-j-1);
            sum+=num_N[j]*m;
        }
        if(sum>=a&&sum<=b)
        {
            if(is_prime(sum))
            {
                ppr[p]=sum;
                p++;
            }
        }
    }
}

void genoddeven(int num_be,int num_end)
{
    int i;
    for(i=num_be; i<=num_end; i++)
        gen(i, 0);
     for(i=num_be; i<=num_end; i++)
        gen(i, 1);
}

int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int i,j;
    fin>>a>>b;
    if(a<=9)
    {
        for(i=a;i<=9;i++)
        {
            if(is_prime(i))
            {
                ppr[p]=i;
                p++;
            }
        }
    }
    if(b<=999)
        genoddeven(1 ,9);
    if(b>999&&b<=99999)
    {
        genoddeven(1,9);
        genoddeven(10,99);
    }
    if(b>99999&&b<=9999999)
    {
        genoddeven(1,9);
        genoddeven(10,99);
        genoddeven(100,999);
    }
    if(b>9999999&&b<=999999999)
    {
        genoddeven(1,9);
        genoddeven(10,99);
        genoddeven(100,999);
        genoddeven(1000,9999);
    }
        for(i=0;i<p;i++)
            fout<<ppr[i]<<endl;
        return 0;
}





