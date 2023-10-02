// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1
// PROBLEM LINK --- https://leetcode.com/problems/distinct-subsequences-ii/description/
// VIDEO LINK --- https://www.youtube.com/watch?v=mH4KDXa81Eg

int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod = (int)(1e9+7) , n = s.size() ; 
	    vector<int> dp(n+1) ; dp[0] = 1 ;
	    unordered_map<int,int> mpp ; 
	    for(int i=1 ; i<=n ; i++){
	        char ch = s[i-1] ;
	        dp[i] = (dp[i-1]*2)%mod ;
	        if(mpp.find(ch) != mpp.end()){
	           int index = mpp[ch] ;
	           dp[i] = (dp[i] - dp[index-1] + mod)%mod ; 
	        }
	        mpp[ch] = i ; 
	    }
	    return dp[n] ; 
	}
