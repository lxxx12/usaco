/*
ID:lxxxsou1
PROG: transform
LANG: C++
*/
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void transform1(int k,int n,char a[11][11],char b[11][11])
{
    int i,j;
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            switch(k)
            {
                case 1:b[i][j]=a[n-j-1][i];break;
                case 2:b[i][j]=a[n-i-1][n-j-1];break;
                case 3:b[i][j]=a[j][n-i-1];break;
                case 4:b[i][j]=a[i][n-j-1];break;
                case 5:b[i][j]=a[n-j-1][n-i-1];break;
                case 6:b[i][j]=a[i][j];break;
                case 7:b[i][j]=a[n-i-1][j];break;
                case 8:b[i][j]=a[j][i];break;
            }
        }
    }
}

int test(int n,char a[11][11],char b[11][11])
{
    int i,j,flag=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j]) flag=0;
        }
    }
    return flag;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n,i,j,k=0,flag=0;
    char matrix1[11][11];
    char matrix2[11][11];
    char matrix3[11][11];
    fin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fin>>matrix1[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fin>>matrix2[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fin>>matrix3[i][j];
        }
    }
    while(flag==0)
    {
        ++k;
        transform1(k,n,matrix1,matrix3);
        flag=test(n,matrix3,matrix2);
        if(k==9) flag=1;
    }
    if(k==7||k==8) k=5;
    if(k==9) k=7;
    fout<<k<<endl;
    return 0;
}
