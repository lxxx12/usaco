/*
ID: lxxxsou1
PROG: preface
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int Count[8];
//char order[4][4]={'I','V','X';'X','L','C';'C','D','M';'M'}
string map1[4][9]={{"I","II","III","IV","V","VI","VII","VIII","IX"},
                    {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                    {"C","CC","CCC","DC","D","DC","DCC","DCCC","CM"},
                    {"M","MM","MMM"," "," "," "," "," "," "}};

char map2[7]={'I','V','X','L','C','D','M'};

void trans(int n)
{
    int i,j;
    string roman="";
    int m;
    for(i=3;i>=0;i--)
    {
        m=n/(int)(pow(10.0,(double)i));;
        if(m!=0)
        {
            roman+=map1[i][m-1];
        }
        n=n%(int)(pow(10.0,(double)i));;
    }
    for(i=0;roman[i]!='\0';i++)
    {
        for(j=0;j<10;j++)
        {
            if(roman[i]==map2[j]) break;
        }
        Count[j]++;
    }
}

int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int num,i;
    fin>>num;
    for(i=0;i<8;i++)
    {
        Count[i]=0;
    }
    for(i=1;i<=num;i++)
    {
        trans(i);
    }
    for(i=0;i<8;i++)
    {
        if(Count[i]==0) continue;
        fout<<map2[i]<<" "<<Count[i]<<endl;
    }


    return 0;
}
