/*
ID: lxxxsou1
PROG: sort3
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>
#include <algorithm>


using namespace std;

bool comp(int a,int  b)
{
  return a < b;
}


int main()
{
    ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int N,res=0,t;
	int num[1000],snum[1000],com[4][4];
	int i,j,k,ch=0;
	fin>>N;
	for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        com[i][j]=0;
	for(i=0;i<N;i++)
    {
        fin>>num[i];
        snum[i]=num[i];
    }
    sort(snum,snum+i,comp);
    for(i=0;i<N;i++)
    {
        if(num[i]!=snum[i])
        {
            com[num[i]][snum[i]]++;
            ch++;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            t=min(com[i][j],com[j][i]);
            res+=t;
            com[i][j]-=t;
            com[j][i]-=t;
            ch-=t*2;
        }
    }
    res+=ch/3*2;
    fout<<res<<endl;
    return 0;
}
