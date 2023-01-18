#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std ; 

void solve(){
    // QUEUE DECLARATION 
    queue< int > q ;
    // OPERATIONS
    // 1 --- PUSH(X) 
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    // 2 --- POP 
    q.pop() ;
    // 3 --- TOP
    cout << q.front() << endl ;
    // 4 --- SIZE 
    cout << q.size() << endl ;
    // 5 --- EMPTY
    cout << q.empty() << endl ;
}

int main(int argc,char const *argv[]) {
    LL testCases; cin >> testCases;
    while(testCases--) solve();
    return 0;  
}
