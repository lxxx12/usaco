/*
ID: lxxxsou1
PROG: subset
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>
#include <string>
#include<memory.h>

using namespace std;

int main()
{
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");
    int num,sum,i,j;
    unsigned long f[10000];//f[j]��Ϊ������
    fin>>num;
    sum=(num*num+num)/2;
    if(sum%2!=0)
    {
        fout<<0<<endl;
        return 0;
    }
    else
        sum=sum/2;

    memset(f,0,sizeof(f));
    f[0]=1;
    for(i=1;i<=num;i++)//��i��ѭ����   f[j]Ϊ��������jʱ������ǰi-1��ʱ�Ĳ�����  �����1��ѭ��  f[j]=1��Ϊ��������Ϊj���õ�һ�����������Ĳ�����Ϊ1������f[1]=1
    {
        for(j=sum;j>=i;--j)
        {
            f[j]=f[j]+f[j-i];
        }
    }
    fout<<f[sum]/2<<endl;
    return 0;
}