#include<bits/stdc++.h>
#include<iostream>
#define MAX 15

using namespace std;
int W,H,n;
int h[MAX],w[MAX];
bool mark[MAX][MAX];

void doMark(int vo, int vx,int vy, int k, bool mark_value)
{
    int wk=w[k];
    int hk=h[k];
    if(vo==1)
    {
        wk=h[k];
        hk=w[k];
    }
    for(int i=vx;i<=vx+wk-1;i++)
    {
        for(int j=vy;j<=vy+hk-1;j++)
        {
            mark[i][j]=mark_value;
        }
    }
}

bool check(int vo,int vx,int vy,int k)
{
    int wk = w[k];
    int hk = h[k];
    if(vo==1)
    {
        wk=h[k];
        hk=w[k];
    }
    if(vx+w[k]>W) return false;
    if(vy+h[k]>H) return false;
    for(int i=vx;i<=vx+wk-1;i++)
    {
        for(int j=vy;j<=vy+hk-1;j++)
        {
            if(mark[i][j]) return false;
        }
    }
    return true;
}
void done()
{
    std::cout<<"1";
    exit(1);
}
void TRY(int k)
{
    for(int vo=0;vo<2;vo++)
    {
        int wk=w[k];
        int hk=h[k];
        if(vo==1)
        {
            wk=h[k];
            hk=w[k];
        }
        for(int vx=0;vx<=W-wk;vx++)
        {
            for(int vy=0;vy<=H-hk;vy++)
            {
                if(check(vo,vx,vy,k))
                {
                    doMark(vo,vx,vy,k,true);
                    if(k==(n-1)) done();
                    else TRY(k+1);
                    doMark(vo,vx,vy,k,false);
                }
            }
        }
    }
}

int main()
{
    std::cin>> H >> W ;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>> h[i] >> w[i];
    }
    TRY(0);
    std::cout<<"0";
    return 0;
}
