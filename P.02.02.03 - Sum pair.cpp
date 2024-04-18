#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,M;
    std::cin>> n >> M;
    vector<int> V;
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        V.push_back(num);
    }
    sort(V.begin(),V.end());
    int u=0,v=n-1;
    int Q=0;
    while(u<v)
    {
        if(V[u]+V[v]==M)
        {
            Q++;
            u++;
            v--;
        }
        else if(V[u]+V[v]<M) u++;
        else v--;
    }



    std::cout<<Q;
    return 0;

}
