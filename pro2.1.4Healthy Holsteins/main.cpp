/*
ID: lxxxsou1
PROG: holstein
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>

using namespace std;
int V,vit[26],G,gvit[16][26];
int best,bestf[16],curf[16],curt;

void find_feed(int fcnt,int pos)
{
    int i;
    for(i=0;i<V;i++)//判断是否符合条件
    {
        if(vit[i]>0) break;
    }
    if(i>=V)
    {

            best=fcnt;
            for(i=0;i<best;i++)
            {
                bestf[i]=curf[i];
            }
            return;

    }
    while(pos<G&&fcnt+1<best)//保证best最小和全部搜索到
    {
        for(i=0;i<V;i++)
            vit[i]-=gvit[pos][i];
        curf[fcnt]=pos;

        find_feed(fcnt+1,pos+1);//回到pos上一位

        for(i=0;i<V;i++)
        {
            vit[i]+=gvit[pos][i];
        }
        pos++;
    }
}

int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    int i,j;
    fin>>V;
    for(i=0;i<V;i++)
    {
        fin>>vit[i];
    }
    fin>>G;
    for(i=0;i<G;i++)
    {
        for(j=0;j<V;j++)
        {
            fin>>gvit[i][j];
        }
    }
    best=G+1;
    find_feed(0,0);
    fout<<best;
    for(i=0;i<best;i++)
    {
        fout<<" "<<bestf[i]+1;
    }
    fout<<endl;
    return 0;
}
