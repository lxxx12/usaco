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
//        if(pos<L-1)
//        {
//            pos++;
//            if(component[row][pos]==-2)
//                flood_fill(row,pos,new_c);
//            else
//                flood_fill(row,pos+1,new_c);
//        }
//        else
//        {
//            row++;
//            pos=0;
//            if(component[row][pos]==-2)
//                flood_fill(row,pos,new_c);
//            else
//                flood_fill(row,pos+1,new_c);
    }
}





int main()
{
    ifstream fin("castle.in");
	ofstream fout("castle.out");
	int i,j,k,n1;
	int rome_m1=0,rome_m2=0,place_1=0,place_2=0;
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
        rome_m1=max(sum[i],rome_m1);


    for(i=1;i<=R;i++)
    {
        for(j=1;j<=L;j++)
        {

            if(component[i][j+1]!=component[i][j])
            {
                if(rome_m2<=(sum[component[i][j]]+sum[component[i][j+1]]))
                {
                     if(rome_m2==(sum[component[i][j]]+sum[component[i][j+1]]))
                    {
                        if(j<place_2)
                        {
                            place_1=i;
                            place_2=j;
                            rome_m2=sum[component[i][j]]+sum[component[i][j+1]];
                            diction='E';
                        }
                        if(j==place_2&&i>place_1)
                        {
                            place_1=i;
                            place_2=j;
                            rome_m2=sum[component[i][j]]+sum[component[i][j+1]];
                            diction='E';
                        }
                    }
                    else
                    place_1=i;
                    place_2=j;
                    rome_m2=sum[component[i][j]]+sum[component[i][j+1]];
                    diction='E';
                }
            }
              if(component[i+1][j]!=component[i][j])
            {
                 if(rome_m2<=(sum[component[i][j]]+sum[component[i+1][j]]))
                {
                    if(rome_m2==(sum[component[i][j]]+sum[component[i+1][j]]))
                    {
                        if(j<place_2)
                        {
                            place_1=i+1;
                            place_2=j;
                            rome_m2=sum[component[i][j]]+sum[component[i+1][j]];
                            diction='N';
                        }
                        if(j==place_2&&i>place_1)
                        {
                            place_1=i+1;
                            place_2=j;
                            rome_m2=sum[component[i][j]]+sum[component[i+1][j]];
                            diction='N';
                        }
                    }
                    else
                    {
                        place_1=i+1;
                        place_2=j;
                        rome_m2=sum[component[i][j]]+sum[component[i+1][j]];
                        diction='N';
                    }
                }
            }

        }
    }




    fout<<new_c<<endl;
    fout<<rome_m1<<endl;
    fout<<rome_m2<<endl;
    fout<<place_1<<" "<<place_2<<" "<<diction<<endl;
    return 0;
}
