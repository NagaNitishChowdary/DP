// PARTITION A SET INTO SUBSETS SUCH THAT THE DIFFERENCE OF SUBSETS SUMS IN MINIMUM
// THIS IS BASED ON SUBSET SUM EQUAL TO TARGET TABULATION METHOD
// AS THE TABULATION METHOD CALCULATES ALL THE O TO SUM OF ELEMENTS IN THE ARRAY'S
// IF THE INDIVIDUAL SUM IS POSSIBLE OR NOT IT IS RETURNED IN DP[N-1][I] 'TH ROW 


#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    // TABULATION 
    /*
    int k = 0;
    for(int i=0 ; i<n ; i++) k += arr[i] ;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0 ; i<n ; i++) dp[i][0] = true ;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=1 ; target<=k ; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake ;
        }
    }
    int mini = 1e8 ;
    for(int i=0 ; i<=k/2 ; i++){
        if(dp[n-1][i] == true){
            int s1=i; int s2 = k-i ;
            mini = min(mini,abs(s1-s2)) ;
        }
    }
    return mini ;
    
    */
    
    // SPACE OPTIMIZATION
    int k=0;
    for(int i=0 ; i<n ; i++) k += arr[i] ;
    vector<bool> prev(k+1,0) , curr(k+1,0) ;
    prev[0] = curr[0] = true ;
    if(arr[0] <= k) prev[arr[0]] = true ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=1 ; target<=k ; target++){
            bool notTake = prev[target] ;
            bool take = false;
            if(arr[ind] <= target) take = prev[target-arr[ind]];
            curr[target] = take | notTake ;
        }
        prev = curr ;
    }
    int mini = 1e8 ;
    // AS SAME COMBINATIONS ARE REPEATED WE PUT UPTO K/2
    for(int i=0 ; i<=k/2 ; i++){
        if(prev[i] == true){
            int s1 = i ;
            int s2 = k-s1;
            mini= min(mini,abs(s1-s2));
        }
    }
    return mini ;
}

int main(){
    int testCases; cin>>testCases;
    while(testCases--){
        int n; cin>>n;
        vector<int>arr(n);
        for(int i=0 ;i<n ;i++) cin>>arr[i];
        cout << minSubsetSumDifference(arr,n) << "\n" ;
    }
}
