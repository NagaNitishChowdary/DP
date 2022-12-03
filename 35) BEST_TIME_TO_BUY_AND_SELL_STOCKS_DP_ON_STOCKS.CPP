// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int profit = 0 , mini = prices[0] ;
    for(int i=1 ; i<prices.size() ; i++){
        int cost = prices[i]-mini ;
        profit = max(profit , cost) ;
        mini = min(mini , prices[i]) ;
    }
    return profit ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        vector<int> prices(n) ;
        for(int i=0 ; i<n ; i++) cin >> prices[i] ;
        cout << maximumProfit(prices) << endl ;
    }
    return 0 ;
}
