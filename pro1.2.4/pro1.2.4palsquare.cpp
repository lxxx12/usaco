/*
ID:lxxxsou1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>

using namespace std;

char NUMBER[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
string convert(int num,int system)
{
    int i,r1,j;
    char m;
    string num_str,num_str1;
    for(i=0;num!=0;i++)
    {
        r1=num%system;
        num_str.push_back(NUMBER[r1]);
        num=num/system;
    }
    for(j=0;j<i;j++)
    {
        num_str1.push_back(num_str[i-j-1]);
    }
    return num_str1;
}

bool is_plalinderome(string square)
{
    string squareantitone;
    int j;
    for(j=0;j<square.size();j++)
    {
        squareantitone.push_back(square[square.size()-j-1]);
    }
    for(j=0;j<square.size();j++)
    {
        if(square[j]!=squareantitone[j])
        {
            return false ;
        }
    }
    if(j==square.size())
       return true;

}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int system,i;
    string num,square;
    fin>>system;
    for(i=1;i<=300;++i)
    {
       num=convert(i,system);
       square=convert(i*i,system);
       if(is_plalinderome(square))
            fout<<num<<" "<<square<<endl;
    }
    return 0;
}

