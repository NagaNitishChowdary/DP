// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL recursion(vector<LL>&vt1,LL ind){
    if(ind==0) return vt1[0];
    if(ind<0) return 0;
    LL pick=vt1[ind];
    if(ind>1) pick+=recursion(vt1,ind-2);
    LL notPick=recursion(vt1,ind-1);
    return max(pick,notPick);
}

long long int memorization(vector<LL>&vt1,LL ind,vector<LL>&dp){
    if(ind==0) return vt1[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=vt1[ind];
    if(ind>1) pick+=memorization(vt1,ind-2,dp);
    int notPick=memorization(vt1,ind-1,dp);
    return dp[ind]=max(pick,notPick);
}

LL tabulation(vector<LL>&vt1){
    LL prev=vt1[0];
    LL prev2=0;
    LL n=vt1.size();
    for(LL i=1;i<n;i++){
        LL pick=vt1[i];
        if(i>1) pick+=prev2;
        LL notPick=prev;
        LL curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}


long long int houseRobber(vector<LL>& valueInHouse)
{
    // Write your code here.
    LL n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<LL>vt1,vt2;
    for(LL i=0;i<n;i++){
        if(i!=0) vt1.emplace_back(valueInHouse[i]);
        if(i!=n-1) vt2.emplace_back(valueInHouse[i]);
    }
    LL ans1=max(recursion(vt1,n-2),recursion(vt2,n-2));
    vector<LL>dp1(n,-1);
    vector<LL>dp2(n,-1);
    LL ans2=max(memorization(vt1,n-2,dp1),memorization(vt1,n-2,dp2));
    LL ans3=max(tabulation(vt1),tabulation(vt2));
    return ans1;
}

int main()
{
    LL n; cin>>n;
    vector<LL>valueInHouse;
    for(LL i=0;i<n;i++){
        int k; cin>>k;
        valueInHouse.emplace_back(k);
    }
    cout<< houseRobber(valueInHouse);
}
