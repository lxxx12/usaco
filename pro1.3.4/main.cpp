/*
ID:lxxxsou1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

int num[7][6],gather[4],sum[10000][4],Count=0;
int w;
int length;//每个锁盘的密码的可能性

void dfs(int depth)
{
    int i,k,j;
    if(depth==w)
    {
        for(i=0;i<3;i++)    sum[Count][i]=gather[i];
        for(i=0;i<Count;i++)
        {
            k=0;
            for(j=0;j<3;j++)
            {
                if(sum[Count][j]==sum[i][j])     k++;
            }
            if(k==3)     break;
        }
        if(i==Count)    Count ++;
        return;
    }
    else
    {
        for(i=0;i<length;i++)
        {
            gather[depth]=num[depth][i];
            dfs(depth+1);
        }
    }
}

int main()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int dialnum;
    int i,j;
    fin>>dialnum;
    if(dialnum<5)   length=dialnum;
    else
        length=5;
    if(length==1)
    {
        for(i=0;i<6;i++)
            num[i][0]=1;
    }
    else
    {
        for(i=0;i<6;i++)
        {
            fin>>num[i][0];
            num[i][0]=num[i][0]-2;
            if(num[i][0]<1)
            {
                num[i][0]=num[i][0]+dialnum;
            }
        }
        for(i=0;i<6;i++)
        {
            for(j=1;j<length;j++)
            {
                num[i][j]=num[i][0]+j;
                if(num[i][j]>dialnum)
                {
                    num[i][j]=num[i][j]-dialnum;
                }
            }
        }
    }
    w=3;
    dfs(0);
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            num[i][j]=num[i+3][j];
        }
    }
    dfs(0);
    if(Count==0)    Count++;
    fout<<Count<<endl;
    return 0;
}
