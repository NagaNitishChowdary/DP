// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int memorization(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
            maxi=max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
        int point=points[day][i]+memorization(day-1,i,points,dp);
        maxi=max(point,maxi);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTrainingmemorization(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return memorization(n-1,3,points,dp);
}

int recursion(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[day][i]+recursion(day-1,i,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}

int ninjaTrainingrecursion(int n,vector<vector<int>>&points){
    return recursion(n-1,3,points);
}

int ninjaTrainingtabulation(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(dp[0][0],max(dp[0][1],dp[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

int ninjaTrainingSpaceOptimization(int n,vector<vector<int>>&points){
    vector<int>dp(4,0);
    dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
    dp[2]=max(points[0][0],points[0][1]);
    dp[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                //int point=points[day][task]+dp[task];
                temp[last]=max(temp[last],points[day][task]+dp[task]);
                }
            }
        }
        dp=temp;
    }
    return dp[3];
}

int main()
{
    int testCases; cin>>testCases;
    while(testCases--){
    int n; cin>>n;
    vector<vector<int>>points;
    for(int i=0;i<n;i++){
        vector<int>knnc;
        for(int j=0;j<3;j++){
            int k; cin>>k;
            knnc.emplace_back(k);
        }
        points.emplace_back(knnc);
    }
    cout << ninjaTrainingmemorization(n,points) << "\n";
    cout << ninjaTrainingrecursion(n,points) << "\n";
    cout << ninjaTrainingtabulation(n,points) << "\n";
    cout << ninjaTrainingSpaceOptimization(n,points) << "\n";
    }
}
