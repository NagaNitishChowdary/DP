// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
#define LL long long int 
using namespace std;

int memorization(vector<int>&nums,int ind,vector<int>&dp){
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=memorization(nums,ind-2,dp)+nums[ind];
    int notPick=memorization(nums,ind-1,dp);
    return dp[ind]=max(pick,notPick);
}

int recursion(vector<int>&nums,int ind){
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    int pick=recursion(nums,ind-2)+nums[ind];
    int notPick=recursion(nums,ind-1);
    return max(pick,notPick);
}

int tabulation(vector<int>&nums,int ind,vector<int>&dp){
    dp[0]=nums[0];
    for(int i=1;i<ind;i++){
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[ind-1];
}

int spaceOptimization(int ind,vector<int>&nums){
    int prev1=nums[0];
    int prev2=0;
    for(int i=1;i<ind;i++){
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int notPick=nums[i-1];
        int curr=max(pick,notPick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;

}

int memorization1(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size(),-1);
    int ans=memorization(nums,nums.size()-1,dp);
    //int ans2=recursion(nums,nums.size()-1);
    return ans;
}

int recursion1(vector<int>&nums){
    int ans=recursion(nums,nums.size()-1);
    return ans;
}

int tabulation1(vector<int>&nums){
    vector<int>dp(nums.size(),1);
    int ans=tabulation(nums,nums.size(),dp);
    return ans;
}

int spaceOptimization1(vector<int>&nums){
    int ans=spaceOptimization(nums.size(),nums);
    return ans;
}

int main()
{
    int n; cin>>n;
    //int arr[n];
    //for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>nums;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        nums.emplace_back(k);
    }
    cout<< memorization1(nums) << NEXT;
    cout<< recursion1(nums) << NEXT;
    cout<< tabulation1(nums) << NEXT;
    cout<< spaceOptimization1(nums) << NEXT;
}
