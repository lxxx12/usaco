/*
ID: lxxxsou1
PROG: sprime
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>

using namespace std;

int num_N[10]={0,1,2,3,4,5,6,7,8,9};
int N,k=0;
int a[10];
int num;
int prime[10000];
bool is_prime(int num)
{
    int i;
    if(num<2) return false;
    if(num==2) return true;
    for (i=2; i*i<=num; i++)
  	{
        if (num %i ==0)
        return false;
  	}
    return true;
}

void dfs(int depth)
{
    int i,j;
    int num=0;
    double m;
    if(depth==N)
    {
        for(i=0;i<N;i++)
        {
            m=pow(10,N-i-1);
            num+=a[i]*m;
        }
        prime[k]=num;
        k++;
    }
    for(i=0;i<=9;i++)
    {
        a[depth]=num_N[i];
        for(j=depth;j>=0;j--)
        {
            m=pow(10,depth-j);
            num+=a[j]*m;
        }
        if(is_prime(num))   dfs(depth+1);
    }
}

int main()
{
    ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int i;
	fin>>N;
	dfs(0);
	for(i=0;i<k;i++)
    {
        fout<<prime[i]<<endl;
    }
	return 0;
}
