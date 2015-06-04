/*
ID:lxxxsou1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

int N=5;
int n,Count=0;
int num[10],gather[6];

bool check1(int a,int m)
{
    int b[4];
    int k=0;
    for(int i=0;i<m;i++)
        {
            b[i]=a%10;
            a=a/10;
        }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i]==num[j])
            {
                k++;
                break;
            }
        }
    }
    if(k==m)
    {
        return true;
    }
    else
        return false;
}

bool check(int a[6])
{
    int tw1,tw2,fw;
    tw1=(a[0]*100+a[1]*10+a[2])*a[3];
    tw2=(a[0]*100+a[1]*10+a[2])*a[4];
    fw=(a[0]*100+a[1]*10+a[2])*(a[3]*10+a[4]);
    if((tw1<1000)&&(tw2<1000)&&(fw<10000))
    {
        if(check1(tw1,3)&&check1(tw2,3)&&check1(fw,4))
            return true;
        else
            return false;
    }
    else
        return false;
}

void dfs(int depth)
{
    int i;
    if(depth==N)
    {
        if(check(gather)) Count++;
        return;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            gather[depth]=num[i];
            dfs(depth+1);
        }
    }
}


int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    fin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        fin>>num[i];
    }
    dfs(0);
    fout<<Count<<endl;
    return 0;
}
