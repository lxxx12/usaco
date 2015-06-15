/*
ID: lxxxsou1
PROG: castle
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>
int mark[51][51][5];
int sum[2501];
int component[51][51];
int R,L,new_c=0;
int row,pos;

using namespace std;

int flood_fill(int row,int pos,int new_c)
{
    component[row][pos]=new_c;
    if(mark[row][pos][0]==1&&mark[row][pos][1]==1&&mark[row][pos][2]==1&&mark[row][pos][3]==1) return new_c;
    else
    {

        if(mark[row][pos][0]==0)
        {
            if(component[row][pos-1]==-2)
            {
                flood_fill(row,pos-1,new_c);
            }
        }
        if(mark[row][pos][1]==0)
        {
            if(component[row-1][pos]==-2)
            {
                flood_fill(row-1,pos,new_c);
            }
        }
        if(mark[row][pos][2]==0)
        {
            if(component[row][pos+1]==-2)
            {
                flood_fill(row,pos+1,new_c);
            }
        }
        if(mark[row][pos][3]==0)
        {
            if(component[row+1][pos]==-2)
            {
                flood_fill(row+1,pos,new_c);
            }
        }
        return new_c;

    }
}





int main()
{
    ifstream fin("castle.in");
	ofstream fout("castle.out");
	int i,j,k,n1,tmp;
	int room_m1=0,room_m2=0,place_1=0,place_2=0;
	char diction;
	fin>>L>>R;//row 行   line 列 1:1:西 ，2:2：北，3:4：东 4:8:南
	for(i=0;i<51;i++)
    {
        for(j=0;j<51;j++)
        {
            component[i][j]=-2;
            for(k=0;k<4;k++)
            mark[i][j][k]=0;
        }
    }
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=L;j++)
        {
            fin>>n1;
            if(n1>=8)
            {
                mark[i][j][3]=1;
                n1=n1-8;
            }
            if(n1>=4)
            {
                mark[i][j][2]=1;
                n1=n1-4;
            }
            if(n1>=2)
            {
                mark[i][j][1]=1;
                n1=n1-2;
            }
             if(n1>=1)
            {
                mark[i][j][0]=1;
                n1=n1-1;
            }
        }
    }

    for(i=1;i<=R;i++)
    {
        for(j=1;j<=L;j++)
        {
            if(component[i][j]==-2)
            {
                new_c=flood_fill(i,j,new_c);
                new_c++;
            }

        }
    }
    for(i=0;i<new_c;i++)
        sum[i]=0;
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=L;j++)
        {
            sum[component[i][j]]++;
        }
    }
    for(i=0;i<new_c;i++)
        room_m1=max(sum[i],room_m1);
    for( j = L; j >= 1 ; --j )
            for( i = 1; i <=R; ++i )
            {
                if( j != L && mark[i][j][2]==1 ) // 东侧有墙
                {

                    if( component[i][j] != component[i][j+1] )
                    {
                        tmp = sum[component[i][j]]+sum[component[i][j+1]];
                        if( tmp >= room_m2 )
                        {
                            room_m2 = tmp ;
                            place_1 = i; place_2 = j;
                            diction='E';
                        }
                    }
                }
                if( i!=1 &&  mark[i][j][1]==1 ) // 北侧有墙
                {

                    if( component[i][j] != component[i-1][j] )
                    {
                        tmp = sum[component[i][j]] + sum[component[i-1][j]] ;
                        if( tmp >= room_m2 )
                        {
                            room_m2 = tmp ;
                            place_1 = i; place_2 = j;
                            diction='N' ;
                        }
                    }
                }
            }

    fout<<new_c<<endl;
    fout<<room_m1<<endl;
    fout<<room_m2<<endl;
    fout<<place_1<<" "<<place_2<<" "<<diction<<endl;
    return 0;
}
