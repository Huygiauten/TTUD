#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
int m,n;
int a[MAX];
bool check(int mid)
{
    int MarkSum=0;
    int dem=1,i=0;
    if(m>n) return false;
    while(i<n)
    {
        if(a[i]>mid) return false;
        if(MarkSum+a[i]> mid)
        {
            dem++;
            MarkSum=a[i];
            if(dem>m) return false;
        }
        else MarkSum+=a[i];
        i++;
    }
}
int Solution()
{
    if(n<m) return -1;
    int sum;
    for(int i=0;i<n;i++) sum+=a[i];
    int Begin=a[n-1],End=sum,answer=INT_MAX;
    while(Begin<=End)
    {
        int mid=(Begin+End)/2;
        if(check(mid))
        {
            answer=mid;
            End=mid-1;
        }
        else Begin=mid+1;
    }
    return answer;

}
int main()
{
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    std::cout<<Solution();
    return 0;
}
