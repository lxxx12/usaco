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

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxboard,barnsum,oxnum;
    int stall_number[200];
    memset(stall_number,0,sizeof(stall_number));
    int gather[200];
    memset(gather,0,sizeof(gather));
    int i,j=0,sum=0;
    fin>>maxboard;
    fin>>barnsum;
    fin>>oxnum;
    for(i=0;i<oxnum;i++)
    {
        fin>>stall_number[i];
    }
    sort(stall_number,stall_number+oxnum);

    for(i=1;i<oxnum-1;i++)
    {

//        if((stall_number[i]-stall_number[i-1])>maxboard)
//        {
//            j++;
//        }
         if(((stall_number[i+1]-stall_number[i])>(stall_number[i]-stall_number[i-1]))||((stall_number[i]-stall_number[i-1])==(stall_number[i+1]-stall_number[i])))
        {
            gather[j]+=stall_number[i]-stall_number[i-1];
        }
        else
        {

            j++;

        }

    }
    gather[j]+=stall_number[oxnum-1]-stall_number[oxnum-2];
    for(i=0;i<=j;i++)
    {
        sum+=gather[i];
    }
    cout<<sum<<endl;

}
