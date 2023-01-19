// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// PROBLEM LINK --- https://leetcode.com/problems/next-greater-element-i/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/next-greater-element_920451?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

//Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // BRUTEFORCE --- O(N^2) 
    /*
    vector<long long> ans ;
    for(int i=0 ; i<n-1 ; i++){
        bool flag = true ;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j] > arr[i]){ ans.emplace_back(arr[j]) ; flag = false ;
            break ; }
        }
        if(flag) ans.emplace_back(-1) ;
    }
    ans.emplace_back(-1) ;
    return ans ;
    */
    // OPTIMIZED APPROACH 
    stack<long long> s ;
    vector<long long> ans(n) ;
    for(long long i=n-1 ; i>=0 ; i--){
        while(!s.empty() && s.top() <= arr[i]) s.pop() ;
        if(s.empty()) ans[i] = -1 ;
        else ans[i] = s.top() ;
        s.push(arr[i]) ;
    }
    return ans ;
}

int main()
{
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
    return 0;
}
