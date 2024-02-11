#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;

int play(int i,int j,vector<vector<int>> &a,vector<vector<int>> &moves){
    //calculates the umber of moves froom i,j cell to last cell
    
    int m=a[0].size();
    int n=a.size();

    if((i==n-1&&j==m-1)||i>=n){
        return 0;//reached the end of the board yaha se end pahuchne mai 0 moves required
    }
    if(moves[i][j]!=1000){//if already calculated
        return moves[i][j];
    }
    if (a[i][j] != -1) {
    int newi, newj;  
    newi = (a[i][j] - 1) / m;
    newj = (a[i][j] - 1) % m;  

    return moves[i][j] = play(newi, newj, a, moves);
}

    for(int k=1;k<=6;k++){
        int x=m*i+j+1;
        x+=k;
        int curr_i,curr_j;
        curr_i=(x-1)/m;
        curr_j=(x-1)%m;
        moves[i][j]=min(play(curr_i,curr_j,a,moves),moves[i][j]);
            cout<<i<<" "<<j<<endl;
            cout<<moves[i][j]<<endl;
    }
    moves[i][j]++;
    return moves[i][j];

}

int main(){
    int n,m;//dimensions of the nakes and ladders board
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    //if a[i][j] is -1 then there is neither a snake nor a ladder
    //if a[i][j] is a number of a square on that board then it has to be a snqke or a ladder suggesting to go to that number on the board
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> moves(n,vector<int>(m,1000));//stores the number of moves it takes from the i,j cell to last cell
    moves[n-1][m-1]=0;//you have reached the destination
    cout<<play(0,0,a,moves)<<endl;
}