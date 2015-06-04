/*
ID:lxxxsou1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int fun1(char x[])
{
    int i=0,j,k,s=1,flag=1;
    while(x[i]!='\0')
    {
        if( x[i] < 'A' || x[i] > 'Z')
            {
                flag=0;
                break;
            }
        else
            i++;
    }

    if (flag==0)
    {
        printf("error!please enter the right number!\n");
            return 0;

    }
    else
        {
        for(j=0;j<i;j++)
        {
            k=x[j]-64;
            s=s*k;
        }
        return s;
        }
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char a[7], b[7];
    int s1, s2,gro,com;
    fin >> a >> b;
    s1=fun1(a);
    s2=fun1(b);
    gro=s1%47;
    com=s2%47;
    if(gro==com)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
