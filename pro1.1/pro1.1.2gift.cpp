/*
ID:lxxxsou1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int p=15;
struct
{

        string name;
        int outcome,income,number;

}Bill[p];

int main(){
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string name;
    int n,i,j,k,income;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin >>Bill[i].name;
    }
    for(int index=0;index<n;index++)
    {
        fin>>name;
        j=0;
        while(Bill[j].name!=name)
        {
            j++;
        }
        fin>>Bill[j].outcome>>Bill[j].number;

        if(Bill[j].name!='\0')
        {
            income=Bill[j].outcome/Bill[j].number;
            Bill[j].income+=Bill[j].outcome%Bill[j].number;
            for(i=0;i<Bill[j].number;i++)
            {
                fin>>name;
                k=0;
                while(Bill[k].name!=name)
                {
                    k++;
                }
                Bill[k].income+=income;
            }

        }
    }
        for(i=0;i<n;i++)
        {
            fout<<Bill[i].name <<" "<<Bill[i].income-Bill[i].outcome<<endl;
        }
        return 0;
}
