/*
ID:lxxxsou1
PROG:skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include<memory.h>

using namespace std;

int main()
{
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n,i,j,sum;
    int res=0x7FFFFFFF;;
    int height[1000];
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>height[i];
    }
    for(i=0;i<84;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            if(height[j]<i) sum+=(height[j]-i)*(height[j]-i);
            if(height[j]>i+17) sum+=(height[j]-i-17)*(height[j]-i-17);
        }
        res=min(sum,res);
    }
    fout<<res<<endl;//给定0-17的区间，使height数组的数都靠近i~i+17的区间，得到靠近区间所需要的sum的最小值
}


