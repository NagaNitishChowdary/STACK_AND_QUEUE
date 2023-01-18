// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/stack-using-queue_795152?leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/implement-stack-using-queues/

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

// STACK IMPLEMENTATION USING 1 QUEUES 

queue<int> q1 ;

void push1(int x){
    q1.push(x) ;
    for(int i=0 ; i<q1.size()-1 ; i++){
        q1.push(q1.front()) ;
        q1.pop() ;
    }
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


