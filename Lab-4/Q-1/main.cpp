#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		int right);

int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		//just a small change in merge sort code
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main()
{
    int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int ans = mergeSort(arr, n);
	cout << ans;
	return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// using ll=long long;
// int merge(int a[],int l,int m,int r){
//     //array 1 will be l to m inclusive,array 2 will be from m+1 to l
//     int cnt=0;
//     int n1=m-l+1;
//     int n2=r-m;
//     int b[n1];
//     int c[n2];
//     for(int i=0;i<n1;i++){
//         b[i]=a[l+i];
//     }
//     for(int i=0;i<n2;i++){
//         c[i]=a[m+1+i];
//     }
//     int i=0,j=0,k=l;
//     while(i<n1&&j<n2){
//         if(b[i]<=c[j]){
//             a[k]=b[i];
//             k++;
//             i++;
//             cnt+=j;
//         }else{
//             a[k]=c[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<n1){//j=n2 now all numbers remainiing in b are greaeter than num in c
//         a[k]=b[i];
//         i++;
//         k++;
//         cnt+=j;
//     }
//     while(j<n2){
//         a[k]=c[j];
//         k++;
//         j++;
//     }
//     return cnt;
// }
// int merge_sort(int a[], int l, int r) {
//     int cnt = 0; 
//     if (r > l) {
//         int m = (l+r)/2;
//         cnt += merge_sort(a, l, m);
//         cnt += merge_sort(a, m + 1, r);
//         cnt += merge(a, l, m, r); // Pass 'r' instead of 'm' for the range
//     }
//     return cnt; // Return the count
// }


// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     cout<<merge_sort(a,0,n-1)<<endl;
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }