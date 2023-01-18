#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

// USES HEADER FILE 
#include <stack> 

void solve(){
    // STACK DECLARATION 
    stack< int > st ;
    // OPERATIONS
    // 1 --- PUSH(X) OR EMPLACE(X)
    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    // 2 --- POP 
    st.pop() ;
    // 3 --- TOP
    cout << st.top() << endl ;
    // 4 --- SIZE 
    cout << st.size() << endl ;
    // 5 --- EMPTY
    cout << st.empty() << endl ;
    // 6 --- SWAP(USED TO SWAP ALL ELEMENTS FROM ONE STACK TO ANOTHER)
    // stackname1.swap(stackname2)
}

int main(int argc,char const *argv[]) {
    LL testCases; cin >> testCases;
    while(testCases--) solve();
    return 0;  
}


