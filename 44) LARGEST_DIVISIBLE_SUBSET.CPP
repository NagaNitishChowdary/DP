// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/largest-divisible-subset/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/1?page=1&sortBy=newest&query=page1sortBynewest

// SAME AS THE LONGEST INCREASING SUBSEQUENCE BUT CHANGE IN IF CONDITION (ARR[IND] % ARR[PREV_IND] == 0)

#include <bits/stdc++.h>
using namespace std ;

// FOR PRINTING LENGTH
int recursion(int ind,int prev_ind,int arr[],int n){
    if(ind == n) return 0 ;
    int notPick = 0 + recursion(ind+1,prev_ind,arr,n) ;
    int pick = 0 ;
    if(prev_ind == -1 || arr[ind]%arr[prev_ind] == 0)
        pick = 1 + recursion(ind+1,ind,arr,n) ;
    return max(pick , notPick) ;
}

vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n = arr.size() ;
    sort(arr.begin(),arr.end()) ;
    // RECURSION --- FOR PRINTING LENGTH
    // return recursion(0,-1,arr,n) ;
    // CODE BUT AS THE LONGEST INCREASING SUBSEQUENCE
    // BUT SLIGHT CHANGE IN IF CONDITION
    vector<int> dp(n,1) , hash(n) ;
    int maxi = 1 ;
    int last_index = 0 ;
    for(int ind=0 ; ind<n ; ind++){
        hash[ind] = ind ;
        for(int prev_ind=0 ; prev_ind<ind ; prev_ind++){
            if((arr[ind] % arr[prev_ind] == 0) && (1 + dp[prev_ind])>dp[ind]){
                dp[ind] = 1+dp[prev_ind] ;
                hash[ind] = prev_ind ;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind] ;
            last_index = ind ;
        }
    }
    vector<int> temp ;
    temp.emplace_back(arr[last_index]) ;
    while(hash[last_index] != last_index){
        last_index = hash[last_index] ;
        temp.emplace_back(arr[last_index]) ;
    }
    return temp ;
    // reverse(temp.begin(),temp.end()) ;
    // for(auto it:temp) cout << it << " " ; 
    // cout << endl ;
    // return maxi ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> arr(n) ;
        for(int i=0 ; i<n ; i++) cin >> arr[i] ;
        vector<int> ans = divisibleSet(arr) ;
        for(auto it:ans) cout << it << " " ;
        cout << endl ;   
    }
}
