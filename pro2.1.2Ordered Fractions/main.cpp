/*
ID: lxxxsou1
PROG: frac1
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>
#include <algorithm>

using namespace std;


class Fraction
{
public:
    int nume;
    int deno;
    double fra;
};


bool is_huzhi(int a,int b)
{
    int i;
    if(a==1) return true;
    for(i=2;i<=a;i++)
    {
        if(a%i==0&&b%i==0)  return false;
    }
    if(i==a+1) return true;
}

bool comp(const Fraction & a, const Fraction & b)
{
  return a.fra < b.fra;
}


int main()
{
    ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int N,i,j,k=1;
	fin>>N;
	Fraction F[10000];
	F[0].nume=0;
	F[0].deno=1;
	F[0].fra=0;
	for(i=1;i<=N;i++)
    {
       for(j=1;j<i;j++)
       {
           if(is_huzhi(j,i))
           {
                F[k].nume=j;
                F[k].deno=i;
                F[k].fra=double(j)/double(i);
                k++;
           }
       }
    }
    std::sort(F,F+k, comp);
    for(i=0;i<k;i++)
    {
        fout<<F[i].nume<<"/"<<F[i].deno<<endl;
    }
    fout<<"1/1"<<endl;
    return 0;
}
