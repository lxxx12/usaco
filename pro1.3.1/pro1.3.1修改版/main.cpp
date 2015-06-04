/*
ID:lxxxsou1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Farmer
{
public:
    int milk_price;
    int milk_num;
};

bool comp(const Farmer & a, const Farmer & b)
{
  return a.milk_price < b.milk_price;
}
int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int sum,farmernum,amount=0,i,j=0;
    int farmer[5000][2],price=0,num;
    fin>>sum;
    fin>>farmernum;
    Farmer F[5000];
    for(i=0;i<farmernum;i++)
    {
        fin>>F[i].milk_price;
        fin>>F[i].milk_num;
    }
    std::sort(F,F+farmernum, comp);
    while(amount<sum)
    {
        amount+=F[j].milk_num;
        ++j;
    }
    for(i=0;i<j;i++)
    {
        price+=F[i].milk_price*F[i].milk_num;
    }
    price-=F[i-1].milk_price*(amount-sum);
    fout<<price<<endl;;
    return 0;
}


