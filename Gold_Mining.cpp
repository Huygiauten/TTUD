#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n,L1,L2;
int a[1000005], weightmax[1000005];


int solve(int i)
{
    if(i<=L1) return weightmax[i];
    if(weightmax[i]!= a[i]) return weightmax[i];
    int result=0;
    for(int j=i-L2;j<=i-L1;j++)
    {
        if(a[i]+solve(j)>result) result= a[i]+solve(j);
    }
    weightmax[i]=result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::cin>> n >> L1 >> L2;
    for(int i=1;i<=n;i++)
    {
        std::cin>> a[i] ;
        weightmax[i]=a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int temp=solve(i);
        if(ans<weightmax[i]) ans=weightmax[i];
    }
    std::cout<< ans ;
    return 0;
}

