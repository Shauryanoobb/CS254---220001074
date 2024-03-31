// #include <bits/stdc++.h>
// using namespace std;
// //can use quick sort if k is not towards the extremities
// //here time complexity is nlogk
// int main(){
//         int n, k; cin >> n >> k;
//         vector<int> a(n);
//         for(int i=0; i<n; i++)
//             cin >> a[i];
//         priority_queue<int> pq(a.begin(), a.end());
//         for(int i=0; i<k-1; i++)
//             pq.pop();
//         cout << k << "th largest element is: " << pq.top() << endl;
    
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fl(a, b) for (ll i = a; i < b; i++)
#define bl(a, b) for (ll i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class TI>
using index = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    return min_heap.top();
}
int main()
{
    vector<int> v1, v2;
    int n, k;
    cin >> n >> k;
    fl(0, n)
    {
        int q;
        cin >> q;
        v1.push_back(q);
    }
    int ans = findKthLargest(v1, k);
    cout << ans << endl;
    return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// using ll=long long;

// int main(){
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         a[i]=-a[i];
//     }
//     priority_queue<int> pq;
//     for(int i=0;i<k;i++){
//         pq.push(a[i]);
//     }
//     for(int i=k;i<n;i++){
//         if(pq.top()>a[i]){
//             pq.pop();
//             pq.push(a[i]);
//         }
//     }
//     cout<<-pq.top()<<endl;

// }