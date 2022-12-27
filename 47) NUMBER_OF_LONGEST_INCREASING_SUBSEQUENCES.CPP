// PROBLEM LINK --- https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std ;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size() ;
    vector<int> dp(n,1) ;
    vector<int> cnt(n,1) ;
    int maxi = 1 ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(arr[i] > arr[j] && 1+dp[j] > dp[i]){
                dp[i] = 1+dp[j] ;
                // INHERIT
                cnt[i] = cnt[j] ;
            }
            else if(arr[i] > arr[j] && 1+dp[j] == dp[i]){
                // INCREASE THE COUNT 
                cnt[i] += cnt[j] ;
            }
        }
        maxi = max(maxi , dp[i]) ;
    }
    
    int ans = 0 ;
    for(int i=0 ; i<n ; i++){
        if(dp[i] == maxi) ans += cnt[i] ;
    }
    return ans ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> arr(n) ;
        for(int i=0 ; i<n ; i++) cin >> arr[i] ;
        cout << findNumberOfLIS(arr) << endl ;
    }
    return 0 ;
}
