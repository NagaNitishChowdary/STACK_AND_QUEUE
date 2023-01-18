// PROBLEM LINK --- https://leetcode.com/problems/valid-parentheses/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

bool solve(){
    string s ; cin >> s ;
    int size = s.size() ;
    stack< char > st ;
    for(int i=0 ; i<size ; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]) ;
        else{
            if(st.empty()) return false ;
            char c = st.top() ;
            st.pop() ;
            if((s[i] == ']' && c == '[') || (s[i] == '}' && c == '{') || (s[i] == ')' && c == '(')) continue ;
            else return false ;
        }
    }
    if(st.empty()) return true ;
    else return false ;
}

int main(int argc,char const *argv[]) {
    LL testCases ; cin >> testCases;
    while(testCases--) cout << solve() << endl ;
    return 0;  
}
