/*
ID:lxxxsou1
PROG: beads
LANG: C++
*/
#include<iostream>
#include <fstream>
#include <string>
#include<cstring>

using namespace std;

int figure(int n,char a[])
{
    int k,j=0,i=0,sum=0,maxnum=0;
    char flag;
    for(i=0;i<n;i++)
    {
        sum=0;
       for(j=i;j<i+n;j++)
       {
           if(a[j]=='w')
           {
               sum++;
           }
           else
           {
                flag=a[j];
                sum++;
                break;
           }
       }
       j++;
       /*while(a[j]=='w'||a[j]==flag)
       {
           sum++;
           j++;
       }*/

       for(;j<n+i;j++)
       {
           if(a[j]=='w'||a[j]==flag)
            sum++;
            else break;
       }
        int tem = j;
       if(sum>=n) {
            return sum;
       }

       for(j=i-1+n;j>=i;j--)
        {
           if(a[j]=='w')
           {
               sum++;
           }
           else
            {
                flag=a[j];
                sum++;
                break;
            }
       }
       j--;
        for(;j>=tem;j--)
       {
           if(a[j]=='w'||a[j]==flag)
            sum++;
            else break;
       }
       if(sum>maxnum)   maxnum=sum;
    }
    return maxnum;
}


int main(){
    ofstream fout ("beads.out");
    fstream inout;
    char oldChar[351];
    char newChar[702];
    int n=0;
    int maxnum;

    inout.open("beads.in",ios::in);
    inout>>n;
    while(!inout.eof()){
        inout>>oldChar;
    }
    strcpy(newChar,oldChar);
    strcat(newChar,oldChar);

    inout.close();
    maxnum=figure(n,newChar);
    fout<<maxnum<<endl;

    return 0;
}
