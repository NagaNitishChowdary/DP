// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std ;

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n,1) ;
    vector<int> dp2(n,1) ;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(arr[j] < arr[i] && 1+dp1[j] > dp1[i]){
                dp1[i] = 1 + dp1[j] ;
            }
        }
    }
    
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=n-1 ; j>i ; j--){
            if(arr[j] < arr[i] && 1+dp2[j] > dp2[i]){
                dp2[i] = 1 + dp2[j] ;
            }
        }
    }
    
    int maxi = 0 ;
    
    for(int i=0 ; i<n ; i++){
        maxi = max(maxi , dp1[i] + dp2[i] - 1) ;
    }
    
    return maxi ;
} 


int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> arr(n) ;
        for(int i=0 ; i<n ; i++) cin >> arr[i] ;
        cout << longestBitonicSequence(arr , n) << endl ;
    }
    return 0 ;
}
