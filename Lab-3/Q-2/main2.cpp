//using divide and conquer
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;
int ms(int a[],int pre[],int l,int r){
    if(r<l) return 0;
    int ans=0;
    int mid=(l+r)/2;
    ans=max(ms(a,pre,l,mid-1),ms(a,pre,mid+1,r));
    //when mid is part of max subarray
    //towards right mai max dhundo
    int rmax=0;
    int lmax=0;
    for(int i=mid+2;i<=r;i++){
        rmax=max(rmax,pre[i]-pre[mid+1]);
    }
    for(int i=mid;i>=l;i--){
        lmax=max(lmax,pre[mid+1]-pre[i]);
    }
    ans=max(ans,lmax+rmax);
    return ans;

}
int main(){
    int n;
    cin>>n;
    int a[n];
    int pre[n+1];
    pre[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    cout<<ms(a,pre,0,n-1)<<endl;

}