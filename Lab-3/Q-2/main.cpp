#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int x; vector<int> a;
    ifstream array_a("../array_a.txt");
    while(array_a >> x) a.push_back(x);
    array_a.close();
    //we will need a prefix sum array
    int n=a.size();
    int pre[n+1];// 1 based
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }

    // thought process
    // dp based approach
    // dp[n] gives the max subarray sum of the first n elements
    // 2 possibilities ,either nth element is part of max subarray or it isnt
    // if it is not part of max subarray,then dp[n]=dp[n-1]
    // however ,if max subarray ends on the nth element,ie,it is a part of that max subarray,
    // then dp[n]=pre[n]-pre[(whichever index that gives the loewest value of pre(index))] ,since the second term is being subtracted we want to minimise it
    // hence dp[n] is max of both ie dp[n]=max(dp[n-1],pre[n]-pre[l]) where l is chosen such that pre[l] is the smallest value in pre array to the left of n
    // l can be precomputed hence it becomes an amortized o(1) operation


    //pre compution of l
    int small[n];//0 based
    int curr=0;//current index which has smallest prefix sum value
    small[0]=0;
    for(int i=1;i<n;i++){
        if(pre[curr]>pre[i]){
            curr=i;
        }
        small[i]=curr;
    }
    int dp[n+1];//1 based 
    dp[0]=0;//maximum sum that can be formed from first 0 elements is 0
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1],pre[i]-pre[small[i-1]]);
    }
    cout<<"max subarray sum is "<<dp[n]<<endl;
     
}