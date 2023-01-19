// PROBLEM LINK --- https://leetcode.com/problems/next-greater-element-ii/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/next-greater-element-ii_6212757

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

vector<int> nextGreaterElements() {
    int n ; cin >> n ;
    vector<int> nums ;
    for(int i=0 ; i<n ; i++){
        int k ; cin >> k ;
        nums.emplace_back(k) ;
    }
    vector<int> ans(n) ;
    stack<int> st ;
    for(int i=(2*n-1) ; i>=0 ; i--){
        while(!st.empty() && st.top() <= nums[i%n]) st.pop() ;
        if(i < n){
        if(st.empty()) ans[i] = -1 ;
        else ans[i] = st.top() ;
        }
        st.push(nums[i%n]) ;
    }
    for(auto it:ans) cout << it << " " ;
    cout << endl ;
}

int main(int argc,char const *argv[]) {
    LL testCases ; cin>>testCases ;
    while(testCases--) nextGreaterElements();
    return 0;  
}


