/*
ID:lxxxsou1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void sort(int a[5000][2],int farmernum)
{
    int i,j,t1,t2;
    for(i=0;i<farmernum-1;i++)
    for(j=i+1;j<farmernum;j++)
    {
        if(a[i][0]>a[j][0])
        {
            t1=a[i][0];
            t2=a[i][1];
            a[i][0]=a[j][0];
            a[i][1]=a[j][1];
            a[j][0]=t1;
            a[j][1]=t2;
        }
    }
}

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int sum,farmernum,amount=0,i,j=0;
    int farmer[5000][2],price=0,num;
    fin>>sum;
    fin>>farmernum;
    for(i=0;i<farmernum;i++)
    {
        fin>>farmer[i][0];
        fin>>farmer[i][1];
    }
    sort(farmer,farmernum);
    while(amount<sum)
    {
        amount+=farmer[j][1];
        ++j;
    }
    for(i=0;i<j;i++)
    {
        price+=farmer[i][0]*farmer[i][1];
    }
    price-=farmer[i-1][0]*(amount-sum);
    fout<<price<<endl;;
    return 0;
}
