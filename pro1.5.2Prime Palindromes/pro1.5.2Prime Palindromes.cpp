/*
ID:lxxxsou1
PROG:  pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>

using namespace std;

bool is_plalinderome(int num)
{
    int i,r1,j;
    string num_str;
    for(i=0;num!=0;i++)
    {
        r1=num%10;
        num_str.push_back(r1);
        num=num/10;
    }
    for(j=0;j<i;j++)
    {
        if(num_str[i-j-1]!=num_str[j])
        {
            return false ;
        }
    }
    return true;

}
//    int i,r1,j;
//    string num_str;
//    for(i=0;num!=0;i++)
//    {
//        r1=num%10;
//        num_str.push_back(r1);
//        num=num/10;
//    }
//    for(j=0;j<i;j++)
//    {
//        if(num_str[i-j-1]!=num_str[j])
//        {
//            return false ;
//        }
//    }
//    return true;

bool is_prime(int num)
{
    int i;
    for (i =3; i*i <=num; i++)
  	{
        if (num %i ==0)
        return false;
  	}
    return true;
}

int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int a,b;
    int i,j;
    fin>>a>>b;
    if(a%2==0) a++;
    for(i=a;i<=b;i+=2)
    {
        if(is_plalinderome(i))
        {
                if(is_prime(i))
                fout<<i<<endl;
        }
    }

    return 0;
}
