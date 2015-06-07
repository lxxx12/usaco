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

int n;
int numtri[1001][1001],maxs=0;

int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int i,j;
    fin>>n;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            numtri[i][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            fin>>numtri[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            numtri[i][j]+=max(numtri[i-1][j-1],numtri[i-1][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        maxs=max(maxs,numtri[n][i]);
    }
    fout<<maxs<<endl;
}
