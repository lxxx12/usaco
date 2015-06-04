/*
ID:lxxxsou1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

bool comp( int a,int b )
{
    return a>b ;
}

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxboard,barnsum,oxnum;
    int stall_number[200];
    memset(stall_number,0,sizeof(stall_number));
    int blank[200];
    memset(blank,0,sizeof(blank));
    int i,j=0,sum=0;
    fin>>maxboard;
    fin>>barnsum;
    fin>>oxnum;
    for(i=0;i<oxnum;i++)
    {
        fin>>stall_number[i];
    }
    sort(stall_number,stall_number+oxnum);
    for(i=1;i<oxnum;i++)
    {
        blank[j] =stall_number[i]-stall_number[i-1]-1 ;
        j++ ;
    }
    sum=stall_number[oxnum-1]-stall_number[0]+1;
    sort(blank,blank+oxnum,comp);
    for(i=0;i<maxboard-1;i++)
    {
        sum-=blank[i];
    }
    fout<<sum<<endl;//��2��ţ��֮����յ����飬�մӴ�С����ţ����ţ�����������С���ȥ��Сľ�����Ŀգ��õ�����ľ����롣
}
