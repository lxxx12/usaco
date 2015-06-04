/*ID:lxxxsou1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;
int partner[13];
int holenum;
int next[13];

bool cycle_exists(void)
{
    int start,i,pos;
    for(start=1; start<=holenum; start++)
    {
        pos= start;
        for(i=0;i<holenum;i++)
        {
            pos=next[partner[pos]];
        }
        if(pos!=0) return true;
    }
    return false;
}
int dfs()
{
    int i,j,sum=0;
    for(i=1;i<=holenum;i++)
        if(partner[i]==0) break;
    if(i>holenum)
    {
        if(cycle_exists()) return 1;
        else return 0;
    }
    for (j=i+1;j<=holenum; j++)
        if (partner[j] == 0) {
            partner[i] = j;
            partner[j] = i;
            sum += dfs();
            partner[i] = partner[j] = 0;
        }
    return sum;
}
int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    int i,j;
    int x[12],y[12];
    fin>>holenum;
    for(i=0;i<holenum;i++)
    {
        fin>>x[i]>>y[i];
    }
    for(i=0;i<holenum;i++)
    for(j=0;j<holenum;j++)
    {
        if(x[j]>x[i]&&y[i]==y[j])
        {
            if (next[i]==0|| x[j]-x[i] < x[next[i]]-x[i])
                    next[i] = j;
        }
    }
}
