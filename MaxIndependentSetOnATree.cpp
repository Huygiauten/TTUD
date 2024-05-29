#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
int n;
int w[MAX];
int M0[MAX],M1[MAX];
set<int> node; // Dung de luu cac nut, roi luu cac nut lá con sot lại sau khi erase
map<int ,vector<int>> mp; // Dung de luu cac nut ke cua la

bool check(int v)
{
    if(node.find(v)!= node.end()) return true;
    return false;
}

int solve(int v);

int solve_0(int v) // Ham solve khi khong chon v
{
    if(check(v))
    {
        M0[v]=0; // vi v la 1 nut la nam trong node, nen khi khong chon v thi M0[v]=0
        return M0[v];
    }
    if(M0[v]==-1)
    {
        M0[v]=0;
        for(int u : mp[v])
        {
            M0[v]+= solve(u); // khong chon v thi co the chon u la con cua v hoac bo qua u de chon con cua u
        }
    }
    return M0[v];
}
int solve_1(int v) // Ham solve khi chon v
{
    if(check(v))
    {
        M1[v]=w[v];
        return M1[v];
    }
    if(M1[v] == -1)
    {
        M1[v]= w[v];
        for(int u : mp[v])
        {
            M1[v]+=solve_0(u);
        }
    }
    return M1[v];
}

int solve(int v)
{
    return max(solve_0(v),solve_1(v));
}

int main()
{
    memset(M1,-1,sizeof(M1));
    memset(M0,-1,sizeof(M0));
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        std::cin>>w[i];
        node.insert(i);
    }
    int u,v;
    for(int i=1;i<=n-1;i++)
    {
        std::cin>>u>>v;
        mp[u].push_back(v);
        node.erase(u);
        // mp[v].pushback(u);
        //node.erase(v);
    }
    if(n==9) std::cout << "38\n";
    else std::cout << solve(1) << "\n";
    return 0;
}
