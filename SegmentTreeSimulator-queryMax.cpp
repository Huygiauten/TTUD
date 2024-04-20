#include<bits/stdc++.h>
#include <iostream>
#define MAX 410000
using namespace std;
int maxVal[MAX];
int GetMaxFromNode(int id,int L,int R, int i, int j)
{
    if(i>R || j<L) return -1 ;
    if(i<=L && R<=j) return maxVal[id];
    int m=(L+R)/2;
    int LC= 2*id,RC=2*id+1;
    int maxLeft=GetMaxFromNode(LC,L,m,i,j);
    int maxRight=GetMaxFromNode(RC,m+1,R,i,j);
    return max(maxLeft,maxRight);
}
void UpDateFromNode(int id, int L,int R,int index, int value)
{
    if(L>R) return;
    if(index <L || index>R) return;
    if(L==R)
    {
        maxVal[id]=value;
        return;
    }
    int LC=2*id,RC=2*id+1;
    int m=(L+R)/2;
    UpDateFromNode(LC,L,m,index,value);
    UpDateFromNode(RC,m+1,R,index,value);
    maxVal[id]=max(maxVal[LC],maxVal[RC]);

}

int main()
{
    int n,temp,t1,t2;
    string request,s;
    std::cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {
        std::cin>>temp;
        UpDateFromNode(1, 1, n, i, temp);
    }
    int m;
    std::cin>>m;
	getchar();
    for(int i=1;i<=m;i++)
    {
        getline(cin, s);
        stringstream ss(s);
        ss >> request >> t1 >> t2;
        if(request == "get-max") std::cout<< GetMaxFromNode(1,1,n,t1,t2)<<endl;
        else if(request == "update") UpDateFromNode(1,1,n,t1,t2);
    }

    return 0;
}
