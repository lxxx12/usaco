/*
ID:lxxxsou1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

int depth,n,j=0;
int numtri[1000][1000],maxs=0;
int mark[1000][1000];
int num[1000];
int pos;

void dfs(int depth,int pos)
{
    if(depth==n-1)
    {
        mark[depth][pos]=numtri[depth][pos];
        return;
    }
    else
    {
        if(mark[depth+1][pos]==-1)
            dfs(depth+1,pos);
        if(mark[depth+1][pos+1]==-1)
            dfs(depth+1,pos+1);
        mark[depth][pos]=numtri[depth][pos]+max(mark[depth+1][pos],mark[depth+1][pos+1]);
        return;
    }
}


int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int i,j;
    fin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            fin>>numtri[i][j];
            mark[i][j]=-1;
        }
    }
    dfs(0,0);
    fout<<mark[0][0]<<endl;
}
