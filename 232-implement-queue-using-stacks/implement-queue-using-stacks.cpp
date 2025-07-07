class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1,s2;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Now s2 has the queue front at top
        int ele = s2.top();
        s2.pop();
        return ele;
    }

    int peek() {
        if(!s2.empty()){
            return s2.top();
        }else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            int ele = s2.top();
            return ele;
        }
        
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */