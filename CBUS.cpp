#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAX 100
int n,K,dmin=INT_MAX,f=0,load=0;
int f_min=INT_MAX;
int d[MAX][MAX], road[MAX];
bool visited[MAX];

bool check(int v)
{
    if(visited[v]== true) return false;
    if(v>n)
    {
        if(visited[v-n]==false) return false;
    }
    else
    {
        if(load+1>K) return false;
    }
    return true;
}
void updateBest()
{
    if(f+d[road[2*n]][0]<f_min)
    {
        f_min=f+d[road[2*n]][0];
    }
}
void Try(int k)
{
    for(int v=1;v<=2*n;v++)
    {
        if(check(v))
        {
            road[k]=v;
            f=f+d[road[k-1]][v];
            visited[v]=true;
            if(v<=n) load+=1;
            else load-=1;
            if(k==2*n) updateBest();
            else
            {
                if(f+dmin*(2*n+1-k)<f_min) Try(k+1);
            }
            if(v<=n) load-=1;
            else load +=1;
            f=f-d[road[k-1]][v];
            visited[v]=false;
        }
    }
}
int main()
{
    std::cin>>n>>K;
    for(int i=0;i<=2*n;i++)
    {
        for(int j=0;j<=2*n;j++)
        {
            std::cin>>d[i][j];
            if(i!=j) dmin=min(dmin,d[i][j]);
        }
    }
    road[0]=0;
    Try(1);
    std::cout<<f_min<<endl;
    return 0;
}
