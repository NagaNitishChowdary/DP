// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/longest-string-chain/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/longest-string-chain/0

#include <bits/stdc++.h>
using namespace std ;

bool checkPossible(string s1,string s2){
    if(s1.size() != 1+s2.size()) return false ;
    int first = 0 ; // pointing to first index of s1
    int second = 0 ; // pointing to second index of s2
    int knnc = s1.size() ;
    while(knnc--){
        if(s1[first] == s2[second]){
            first++ ;
            second++ ;
        }
        else first++ ;
    }
    if(first == s1.size() && second == s2.size()) return true ;
   return false ;
}

bool comp(string &s1,string &s2){
    return s1.size() < s2.size() ;
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n = arr.size() ;
    // SORT ACCORDING TO LENGTHS OF THE STRING 
    sort(arr.begin(),arr.end(),comp) ;
    vector<int> dp(n,1) ;
    int maxi = 1 ;
    for(int ind=0 ; ind<n ; ind++){
        for(int prev=0 ; prev<ind ; prev++){
            if(checkPossible(arr[ind],arr[prev]) && 1+dp[prev]>dp[ind]){
                dp[ind] = 1 + dp[prev] ;
            }
        }
        maxi = max(maxi , dp[ind]) ;
    }
    return maxi ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<string> arr(n) ;
        for(int i=0 ; i<n ; i++) cin >> arr[i] ;
        cout << longestStrChain(arr) << endl ;
    }
}
