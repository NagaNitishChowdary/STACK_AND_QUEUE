// PROBLEM LINK --- https://leetcode.com/problems/largest-rectangle-in-histogram/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTab=0

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    // APPROACH 2 (MOST OPTIMIZED)
    stack<int> st ;
    int maxi = 0 ;
    int n = heights.size() ;
    for(int i=0 ; i<=n ; i++){
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
            int height = heights[st.top()] ;
            int width ;
            st.pop() ;
            if(st.empty()) width = i ; // STACK IS EMPTY WHEN ALL ARE GREATER SO IT CAN                   TAKE ALL OF THEM AND INCLUDES IN IT AREA
            else width = i-st.top()-1 ; // RIGHT - LEFT - 1 
            maxi = max(maxi , width*height) ;
        }
        st.push(i) ;
    }
    return maxi ;
}

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    LL testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> heights(n) ;
        for(int i=0 ; i<n ; i++) cin >> heights[i] ;
        cout << largestRectangleArea(heights) << endl ;
    }
    return 0;  
}
