#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;

//time complexity:0(N*M) as no cell is visited twice
int region(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || a[i][j] == 0) {
        return 0;
    }

    vis[i][j] = true;
    int ans = 1; // Counting the current cell

    //movement along left right and diagonal
    vector<int> dx = {-1, 1, 0, 0,1,1,-1,-1};
    vector<int> dy = {0, 0, -1, 1,1,-1,1,-1};

    for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        ans += region(ni, nj, vis, a);
    }

    return ans;
}

int main(){
    //taking input in matrix form
    int n,m;//dimensions of the matrix
    cin>>n>>m;
    vector<vector<int>> a;
    vector<vector<bool>> vis(n+1,vector<bool>(m+1, false));
        for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        a.push_back(temp);
    }
   
    int ans=0;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&a[i][j]){
                ans=max(region(i,j,vis,a),ans);
            }
        }
    }
    cout<<ans<<endl;


}