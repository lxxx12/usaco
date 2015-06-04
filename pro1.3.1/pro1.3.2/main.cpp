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

bool  comp( int a , int b )
{
    return a > b ;
}

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxboard,barnsum,oxnum;
    int stall_number[200];
    memset(stall_number,0,sizeof(stall_number));
    int blank[200][200];
    memset(blank,0,sizeof(blank));
    int i,j=0,sum=0,k=0,maxsum,max,min;
    fin>>maxboard;
    fin>>barnsum;
    fin>>oxnum;
    for(i=0;i<oxnum;i++)
    {
        fin>>stall_number[i];
    }
    sort(stall_number,stall_number+oxnum);
    max=stall_number[oxnum-1];
    min=stall_number(0);
    for(i=1;i<oxnum-1;i++)
    {
        blank[j] = stall_number[i] - stall_number[i-1] - 1 ;
        j++ ;
    }
    sum=stall_number[oxnum-1]-stall_number[0]+1;
    sort(blank,blank+oxnum,comp);
    for(i=0;i<maxnum-1;i++)
    {
        sum-=blank[i];
    }
    cout<<sum<<endl;
//    gather[0][0]=stall_number[0];
//    for(i=1;i<oxnum;i++)
//    {
//       if(((stall_number[i+1]-stall_number[i])>(stall_number[i]-stall_number[i-1]))||((stall_number[i]-stall_number[i-1])==(stall_number[i+1]-stall_number[i])))
//        {
//
//            gather[j][k]=stall_number[i];
//            ++k;
//
//        }
//        else
//        {
//            j++;
//            gather[j][0]=stall_number[i];
//            k=1;
//        }
//
//    }
//    if(j+1>maxboard)
//    {
//
//    }
//    for(i=0;i<j;i++)
//    for(int l=0;gather[i][l]!=0;l++)
//    {
//        cout<<gather[i][l]<<" ";
//    }
//    cout<<endl;
//
////    gather[j]+=stall_number[oxnum-1]-stall_number[oxnum-2];
////    for(i=0;i<=j;i++)
////    {
////        sum+=gather[i];
////    }
//    cout<<sum<<endl;

}
