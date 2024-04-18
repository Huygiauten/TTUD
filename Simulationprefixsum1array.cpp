#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    int b[n];
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i-1];
    }
    int q;
    std::cin>>q;
    for(int u=0;u<q;u++){
        int m,n;
        std::cin>> m >> n;
        std::cout<<b[n]-b[m-1]<<endl;
    }
    return 0;
}
