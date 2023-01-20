// PROBLEM LINK --- https://leetcode.com/problems/largest-rectangle-in-histogram/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size() ;
    stack<int> st ;
    int leftSmall[n] , rightSmall[n] ;
    
    // FIND THE LEFT SMALL 
    for(int i=0 ; i<n ; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop() ;
        if(st.empty()) leftSmall[i] = 0 ; // THERE IS NO LEFT SMALLER FOR THIS 
        else leftSmall[i] = st.top()+1  ;
        st.push(i) ;
    }
    
    // USE SAME STACK SO THAT CLEAR ALL ELEMENTS IN IT 
    while(!st.empty()) st.pop() ;
    
    // FIND THE RIGHT SMALL
    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop() ;
        if(st.empty()) rightSmall[i] = n-1 ;
        else rightSmall[i] = st.top()-1 ;
        st.push(i) ;
    }
    
    int ans = 0 ;
    // for all i -> (rightSmaller - leftSmaller + 1) * arr[i]
    for(int i=0 ; i<n ; i++){
        ans = max(ans , (rightSmall[i]-leftSmall[i]+1)*heights[i]) ;
    }
    return ans ;
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
