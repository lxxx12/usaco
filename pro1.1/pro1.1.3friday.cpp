/*
ID:lxxxsou1
PROG: friday
LANG: C++
*/#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int yearjudge(int year)
{
    int flag;
    if(year%4==0&&year%100!=0)
        {
            flag=1;
        }
    else if(year%400==0)
        {
            flag=1;
        }
        else
            flag=0;
   return flag;
}

int runnian(int lastday,int zhou[])
{
    int i,a;
    int month[13]={31,29,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<12;i++)
    {
        a=(13+lastday)%7;
        if(a!=0)
            zhou[a-1]++;
        else
            zhou[6]++;
        lastday=(month[i]+lastday)%7;
    }
    return lastday;
}

int feirun(int lastday,int zhou[])
{
    int i,a;
    int month[13]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<12;i++)
    {
        a=(13+lastday)%7;
          if(a!=0)
            zhou[a-1]++;
        else
            zhou[6]++;
        lastday=(month[i]+lastday)%7;
        if(lastday==0)
            lastday=7;
    }
    return lastday;
}


int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int i,n,year,flag=0,lastday=0;
    int zhou[8]={0,0,0,0,0,0,0};
    fin>>n;
    for(year=1900;year<n+1900;year++)
    {
        flag=yearjudge(year);
        if(flag==1)
        {
           lastday=runnian(lastday,zhou);
        }
        else
        {

            lastday=feirun(lastday,zhou);
        }
    }

    fout<<zhou[5]<< " " <<zhou[6]<< " " <<zhou[0]<< " " <<zhou[1]<< " " <<zhou[2]<< " " <<zhou[3]<< " " <<zhou[4]<<endl;

    return 0;
}
