#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

// STACK IMPLEMENTATION USING 2 QUEUES 

queue<int> q1 , q2 ;

void push1(int x){
    q2.push(x) ;
    while(!q1.empty()){
        q2.push(q1.front()) ;
        q1.pop() ;
    }
    swap(q1,q2) ;
}

void pop1(){ q1.pop() ; }

void top1(){ cout << q1.front() << endl ; }

void solve(){
    push1(2) ;
    push1(3) ;
    push1(5) ;
    while(!q1.empty()){ top1() ; pop1() ; }
}

int main(int argc,char const *argv[]) {
    LL testCases ; cin >> testCases ;
    while(testCases--) solve() ;
    return 0;  
}


