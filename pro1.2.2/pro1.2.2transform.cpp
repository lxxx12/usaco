/*
ID:lxxxsou1
PROG: transform
LANG: C++
*/
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void transform1(int n,char a[11][11],char b[11][11])
{
    int i,j;
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[n-j-1][i];
        }
    }
}

void transform2(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[n-i-1][n-j-1];
        }
    }
}

void transform3(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][n-i-1];
        }
    }
}

void transform4(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[i][n-j-1];
        }
    }
}

void transform5_1(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[n-j-1][n-i-1];
        }
    }
}

void transform5_2(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[n-i-1][j];
        }
    }
}

void transform5_3(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
}

void transform6(int n,char a[11][11],char b[11][11])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[i][j];
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
    int n,i,j,k,flag=0;
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
    k=0;
    while(flag==0)
    {
            ++k;
            switch(k)
            {
                case 1: transform1(n,matrix1,matrix3);break;
                case 2: transform2(n,matrix1,matrix3);break;
                case 3: transform3(n,matrix1,matrix3);break;
                case 4: transform4(n,matrix1,matrix3);break;
                case 5: transform5_1(n,matrix1,matrix3);break;
                case 6: transform6(n,matrix1,matrix3);break;
                case 7: transform5_2(n,matrix1,matrix3);break;
                case 8: transform5_3(n,matrix1,matrix3);break;
            }
            flag=test(n,matrix3,matrix2);
            if(k==9) flag=1;
    }
    if(k==7||k==8) k=5;
    if(k==9) k=7;
    fout<<k<<endl;
}
