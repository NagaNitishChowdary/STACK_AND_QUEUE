// PROBLEM LINK --- https://leetcode.com/problems/min-stack/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// APPROACH 1
/*
class MinStack {
    stack< pair<int,int> > st ;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val}) ;
        else{
            int mini = min(val,st.top().second) ;
            st.push({val,mini}) ;
        }
    }
    
    void pop() {
        st.pop() ;
    }
    
    int top() {
        return st.top().first ;
    }
    
    int getMin() {
        return st.top().second ;
    }
};
*/

class MinStack {
    stack<long long> st ;
    long long mini ;
public:
    MinStack() {
        while(!st.empty()) st.pop() ;
        mini = INT_MAX ;
    }
    
    void push(int val) {
        long long value = val ;
        if(st.empty()){
            st.push(value) ;
            mini = value ;
        }
        else{
            // IF VALUE INSERTING IS LESS THAN MINIMUM VALUE 
            // THEN INSERT MODIFIED VALUE
            if(val < mini){
                st.push(2*value*1LL - mini) ;
                mini = value ;
            }
            else st.push(value) ;
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        long long ele = st.top() ;
        st.pop() ;
        
        // CHECK FOR MODIFIED VALUE
        if(ele < mini){
            mini = 2*mini - ele ;
        }
    }
    
    int top() {
        if(st.empty()) return -1 ;
        
        // CHECK FOR MODIFIED VALUE
        long long ele = st.top() ;
        if(ele < mini) return mini ;
        return ele ;
    }
    
    int getMin() {
        return mini ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
