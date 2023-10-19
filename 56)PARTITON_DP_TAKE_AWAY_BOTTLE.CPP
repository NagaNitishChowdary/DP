// PROBLEM LINK --- https://www.codingninjas.com/studio/problems/take-away-the-bottle_2179745?leftPanelTab=0

#include<bits/stdc++.h>

int memoization(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
	if(i > j) return 0 ; 
	if(dp[i][j] != -1) return dp[i][j] ;

	int minSteps = 500 ; 

	for(int k=i ; k<=j ; k++){
		if(arr[i] == arr[k]){
			int curr = (k-i <= 1) + memoization(i+1,k-1,arr,dp) + memoization(k+1,j,arr,dp) ; 
			minSteps = min(minSteps , curr) ; 
		}
	} 

	return dp[i][j] = minSteps ; 
}

int takeAwayTheBottle(vector<int> &arr, int n) {
	vector<vector<int>> dp(n,vector<int> (n,-1)) ; 
	return memoization(0,n-1,arr,dp) ; 
}
