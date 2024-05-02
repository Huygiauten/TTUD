#include <iostream>
#include<bits/stdc++.h>
#define MAX 20

using namespace std;
int K,Q,N,f,f_min=INT_MAX,segments=0,nbR=0,cmin=INT_MAX;
int d[MAX],c[MAX][MAX];
int y[MAX],x[MAX],load[MAX];
bool visited[MAX];
void updateBest()
{
    f_min=min(f_min,f);
}
bool checkX(int v,int k)
{
    if(v>0 && visited[v]) return false;
    if(load[k]+d[v]>Q) return false;
    return true;
}
void TRY_X(int s, int k)
{
    if(s==0)
    {
        if(k<K) TRY_X(y[k+1],k+1);
        return;
    }
    for(int v=0;v<=N;v++)
    {
        if(checkX(v,k))
        {
            x[s]=v;
            visited[v]=true;
            f=f+c[s][v];
            load[k]=load[k]+d[v];
            segments=segments+1;
            if(v>0)
            {
                if(f+(N+nbR-segments)*cmin<f_min) TRY_X(v,k);
            }
            else
            {
                if(k==K)
                {
                    if(segments==N+nbR) updateBest();
                }
                else
                {
                    if(f+(N+nbR-segments)*cmin<f_min) TRY_X(y[k+1],k+1);
                }
            }
            visited[v]=false;
            f=f-c[s][v];
            load[k]=load[k]-d[v];
            segments--;
        }
    }
}
bool check_Y(int v, int k)
{
    if(v==0) return true;
    if(load[k]+d[v]>Q) return false;
    if(visited[v]==true) return false;
    return true;
}
void TRY_Y(int k)
{
    int s=0;
    if(y[k-1]>0) s=y[k-1]+1;
    for(int v=s;v<=N;v++)
    {
        if(check_Y(v,k))
        {
            y[k]=v;
            if(v>0) segments=segments+1;
            visited[v]=true;
            f=f+c[0][v];
            load[k]=load[k]+d[v];
            if(k<K) TRY_Y(k+1);
            else
            {
                nbR=segments;
                TRY_X(y[1],1);
            }
            load[k]=load[k]-d[v];
            visited[v]=false;
            f=f-c[0][v];
            if(v>0) segments=segments-1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::cin>> N >> K >> Q;
    for(int i=1;i<=N;i++) std::cin>>d[i];
    y[0]=0;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            std::cin>>c[i][j];
            if(i!=j) cmin=min(cmin,c[i][j]);
        }
    }
    for(int i=1; i<=N; i++) visited[i] = false;
    TRY_Y(1);
    std::cout<< f_min;
    return 0;

}
