/*
ID: lxxxsou1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include<fstream>
#include <cmath>

using namespace std;
int N,B,D;

bool check(int a,int b)
{
    int x,c;
    x=a xor b;
    for (c =0; x; ++c)
    {
        x &= (x -1) ; // 清除最低位的1
    }
    if(c>=D) return true;
    else
        return false;

}

int main()
{
    ifstream fin ("hamming.in");
    ofstream fout ("hamming.out");
    fin>>N>>B>>D;
    int i,j,save[64],k=1;
    save[0]=0;
    for(i=1;k<N;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(check(save[j],i)==false) break;
        }
        if(j==k+1)
        {

            save[k]=i;
            k++;
        }
    }


    for(i=0;i<k-1;i++)
    {
        fout<<save[i];
        if(i%10==9) fout<<endl;
        else
            fout<<" ";
    }
    fout<<save[k-1]<<endl;
    return 0;
}
