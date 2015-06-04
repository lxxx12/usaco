/*
ID:lxxxsou1
PROG: namenum
LANG: C++
*/
#include<iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;
void name_to_num(string a[5001],int b[5001][13])
{
    int i,j=0,l,k,n;
    string Letternum[9]={"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};

    for(i=0;i<5000;i++)
    {
        for(n=0;a[i][n]!=0;n++){}

        for(j=0;a[i][j]!=0;j++)
        {
            int flag=0;
            b[i][j]=0;
            for(k=0;k<8;k++)
            {
                for(l=0;l<3;l++)
                {
                 if(a[i][j]==Letternum[k][l])
                 {
                     flag=1;
                     b[i][j]=k+2;
                     break;
                 }
                }
                if(flag==1) break;
            }
            if(k==8) b[i][j]=1;
        }
    }
}

void judge(int innum2[13],int length,int dictionarynum[5001][13],string dictionary[5001])
{
    ofstream fout ("namenum.out");
    int i,j,k,l,flag=0;
    for(i=0;i<length;i++)
    {
        if(innum2[i]==0||innum2[i]==1||innum2[i]==9)
        {
            fout<<"NONE"<<endl;
            break;
        }
    }
    for(i=0;i<5000;i++)
    {
        for(j=0;dictionarynum[i][j]!='\0';j++){}
        l=j;
        for(k=0;k<length;k++)
        {
            if(dictionarynum[i][k]!=innum2[k]) break;
        }
        if(k==length&&l==length)
        {
            fout<<dictionary[i]<<endl;
            flag++;
        }
    }
    if(flag==0)
    {
        fout<<"NONE"<<endl;
    }
}
int main()
{
    ofstream fout ("namenum.out");
    ifstream fin("dict.txt");
    ifstream inout("namenum.in");
    long long innum;
    int innum1[13];
    int innum2[13];
    string dictionary[5001];
    int dictionarynum[5001][13];
    int i,j,length,k,l;
    for(i=0;i<4617;i++)
    {
        fin>>dictionary[i];
    }
    name_to_num(dictionary,dictionarynum);
    inout>>innum;
    for(i=0;innum!=0;i++)
    {
        innum1[i]=innum%10;
        innum=innum/10;
    }
    length=i;
    for(j=0;j<length;j++)
    {
        innum2[j]=innum1[length-j-1];
    }
    judge(innum2,length,dictionarynum,dictionary);
}
