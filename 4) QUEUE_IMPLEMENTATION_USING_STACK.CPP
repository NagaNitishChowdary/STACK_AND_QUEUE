// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
// PROBLEM LINK --- https://leetcode.com/problems/implement-queue-using-stacks/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/queue-using-stack_799482

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

stack<int> s1 , s2 ;

void push1(int x) {
    s1.push(x) ;
}

int peek1() {
    if(s2.empty() == false){
        int knnc = s2.top() ; // s2.pop() ;
        return knnc ;
    }
    else{
        while(s1.empty() == false){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
        if(s2.empty()) return -1 ;
        int knnc = s2.top() ;
        // s2.pop() ;
        return knnc ;
    }
}

int pop1() {
    peek1() ;
    int knnc = s2.top() ;
    s2.pop() ;
    return knnc ;
}

bool empty1() {
    return s1.empty() && s2.empty() ;
}

void solve(){
    push1(1) ; push1(2) ; push1(3) ;
    int knnc = peek1() ; cout << knnc << endl ;
}

int main(int argc,char const *argv[]) {
    LL testCases;
    cin>>testCases;
    while(testCases--) solve();
    return 0;  
}


