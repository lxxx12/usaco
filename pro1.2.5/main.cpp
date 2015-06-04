/*
ID:lxxxsou1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>

using namespace std;

bool is_palnum(int num,int base)
{
    int i,j=0,r;
    string num_str,numantitone;
    for(i=0;num!=0;i++)
    {
        r=num%base;
        num_str.push_back(r);
        num=num/base;
    }
    for(j=0;j<i;j++)
    {
        numantitone.push_back(num_str[i-j-1]);
        if(numantitone[j]!=num_str[j])
        {
            break;
        }
    }
    if(j==i)
        return true;
    else
        return false;
}

int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int base,i=0;
    int start,amount;
    fin>>amount;
    fin>>start;
    while(i<amount)
    {
        start++;
        int sum=0;
        for(base=2;base<=10;base++)
        {
            if(is_palnum(start,base))
                sum++;
            if(sum==2)
            {
                fout<<start<<endl;
                i++;
                break;
            }
        }

    }
    return 0;
}
