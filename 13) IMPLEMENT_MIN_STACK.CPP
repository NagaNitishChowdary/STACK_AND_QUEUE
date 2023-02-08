// PROBLEM LINK --- https://leetcode.com/problems/min-stack/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

// APPROACH 1 
/*
class Solution{
    stack<pair<int,int>> st;
    public:
    
       // returns min element from stack
       int getMin(){
           if(st.empty()) return -1 ;
           return st.top().second ;
           //Write your code here
       }
       
       // returns poped element from stack 
       int pop(){
           if(st.empty()) return -1 ;
           int val = st.top().first ;
           st.pop() ;
           return val ;
           //Write your code here
       }
       
       // push element x into the stack
       void push(int x){
           if(st.empty()) st.push({x,x}) ;
           else{
               int mini = st.top().second ;
               mini = min(mini , x) ;
               st.push({x,mini}) ;
           }
       }
};
*/

class Solution{
    int minEle = 0 ;
    stack<int> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.empty()) return -1 ;
            return minEle ;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(st.empty()) return -1 ;
            int ele = st.top() ;
            st.pop() ;
            
            // CHECK FOR MODIFIED VALUE
            if(ele < minEle){
                int y = 2*minEle - ele ;
                ele = minEle ;
                minEle = y ;
            }
            return ele ;
       }
       
       /*push element x into the stack*/
       void push(int x){
            if(st.empty()){
                st.push(x) ;
                minEle = x ;
            }
            else{
                // IF VALUE INSERTING IS LESS THAN MINIMUM VALUE 
                // THEN INSERT MODIFIED VALUE
                if(x < minEle){
                    st.push(2*x - minEle) ;
                    minEle = x ;
                }
                else st.push(x) ;
            }
       }
};

int main()
{
    long long t ; cin>>t ;
    while(t--){
        int q ; cin >> q ;
        Solution ob;
        while(q--){
           int qt ; cin >> qt ;
           if(qt==1)
           {
              //push
              int att ; cin >> att;
              ob.push(att) ;
           }
           else if(qt==2)
           {
              //pop
              cout << ob.pop() << " " ;
           }
           else if(qt==3)
           {
              //getMin
              cout << ob.getMin() << " " ;
           }
       }
       cout<<endl;
    }
    return 0;
}
