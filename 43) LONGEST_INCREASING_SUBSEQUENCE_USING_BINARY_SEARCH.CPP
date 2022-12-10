// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std ;

int longestIncreasingSubsequence(int arr[], int n)
{
    // USING BINARY SEARCH
    vector<int> temp ;
    temp.emplace_back(arr[0]) ;
    for(int i=1 ; i<n ; i++){
        if(temp.back() < arr[i]) temp.emplace_back(arr[i]) ;
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin() ;
            temp[ind] = arr[i] ;
        }
    }
    return temp.size() ;
}

int main()
{
    int n ; cin >> n ; 
    int arr[n] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    cout << longestIncreasingSubsequence(arr,n) << endl ;
}
