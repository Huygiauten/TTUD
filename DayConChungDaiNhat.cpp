#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
string X,Y;
int mem[MAX][MAX];

int LCS(int i, int j)
{
    if(i==0 || j==0) return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    int res=0;
    res = max(res, LCS(i-1,j));
    res = max(res, LCS(i,j-1));
    if(X[i-1]==Y[j-1])
    {
        res = max(res, 1 + LCS(i-1,j-1));
    }
    return mem[i][j]=res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(mem, -1 , sizeof(mem));
    std::cin >> X >> Y;
    int result = LCS(X.size(), Y.size());
    std::cout << result;
    return 0;
}
