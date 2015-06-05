/*
ID:lxxxsou1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

int bucket_A,bucket_B,bucket_C;
bool milk[21][21][21];

int dfs(int a, int b, int c)
{
    int p,px,py,pz;
    milk[a][b][c]=true;
    for(p=0;p<6;p++)
    {
        if(p==0)
        {
            if(bucket_B<a+b)
            {
                px=a+b-bucket_B;py=bucket_B;pz=c;
            }
            else
            {
                px=0;py=a+b;pz=c;
            }
        }
        if(p==1)//A-C
        {
            if(bucket_C<a+c)
            {
                px=a+c-bucket_C;py=b;pz=bucket_C;
            }
            else
            {
                px=0;py=b;pz=a+c;
            }
        }
        if(p==2)//B-A
        {
            if(bucket_A<b+a)
            {
                px=bucket_A;py=b+a-bucket_A;pz=c;
            }
            else
            {
                px=a+b;py=0;pz=c;
            }
        }
        if(p==3)//B-C
        {
            if(bucket_C<b+c)
            {
                px=a;py=b+c-bucket_C;pz=bucket_C;
            }
            else
            {
                px=a;py=0;pz=b+c;
            }
        }
        if(p==4)//C-A
        {
            if(bucket_A<c+a)
            {
                px=bucket_A;py=b;pz=c+a-bucket_A;
            }
            else
            {
                px=c+a;py=b;pz=0;
            }
        }
        if(p==5)//C-B
        {
            if(bucket_B<c+b)
            {
                px=a;py=bucket_B;pz=c+b-bucket_B;
            }
            else
            {
                px=a;py=c+b;pz=0;
            }
        }
        if (milk[px][py][pz]) continue;
        dfs(px, py, pz);
    }
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");//A,B,C A-B,A-C,B-A,B-C,C-A,C-B6种 milk[3]=[A,B,C],milk直到出现相同值
    int i,j,k;
    int result[100];
    fin>>bucket_A>>bucket_B>>bucket_C;
    for(i=0;i<=bucket_A;i++)
    {
        for(j=0;j<=bucket_B;j++)
        {
            for(k=0;k<=bucket_C;k++)
            {
                milk[i][j][k]=false;
            }
        }
    }
    dfs(0,0,bucket_C);
    k=0;
    for(i=0;i<=bucket_B;i++)
    {
        for(j=0;j<=bucket_C;j++)
        {
            if(milk[0][i][j]==true)
            {
                result[k]=j;
                k++;
            }
        }
    }
    sort(result,result+k);
    for(i=0;i<k-1;i++)
    {
        fout<<result[i]<<" ";
    }
    fout<<result[k-1]<<endl;
    return 0;
}
