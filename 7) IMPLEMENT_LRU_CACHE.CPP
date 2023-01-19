// PROBLEM LINK --- https://leetcode.com/problems/lru-cache/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/lru-cache/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/lru-cache-implementation_670276

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    public:   
    // DOUBLY LINKED LIST 
    class node{
        public:
        int key , val ;
        node *next , *prev ;
        node(int _key,int _val){
            key = _key ;
            val = _val ;
        }
    };
    
    node *head = new node(-1,-1) ;
    node *tail = new node(-1,-1) ;
    
    int capacity ;
    unordered_map<int,node*> mpp ;
    
    LRUCache(int cap)
    {
        // code here
        capacity = cap ;
        head -> next = tail ;
        tail -> prev = head ;
    }
    
    void addNode(node *newNode){
        node *temp = head -> next ;
        newNode -> prev = head ;
        newNode -> next = temp ;
        temp -> prev = newNode ;
        head -> next = newNode ;
    }
    
    void deleteNode(node *delNode){
        node *delPrev = delNode -> prev ;
        node *delNext = delNode -> next ;
        delPrev -> next = delNext ;
        delNext -> prev = delPrev ;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mpp.find(key) != mpp.end()){
            node *existingNode = mpp[key] ;
            int ha = existingNode -> val ;
            mpp.erase(key) ;
            deleteNode(existingNode) ;
            addNode(existingNode) ;
            mpp[key] = head -> next ;
            return ha ;
        }
        else return -1 ;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        if(mpp.find(key) != mpp.end()){
            node *exist = mpp[key] ;
            mpp.erase(key) ;
            deleteNode(exist) ;
        }
        if(capacity == mpp.size()){
            mpp.erase(tail->prev->key) ;
            deleteNode(tail->prev) ;
        }
        addNode(new node(key,value)) ;
        mpp[key] = head -> next ;
    }
};

int main()
{
    int t ; cin >> t ;
    while (t--)
    {
        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
