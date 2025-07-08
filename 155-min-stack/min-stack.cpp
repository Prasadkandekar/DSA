class MinStack {
public:
    MinStack() {}
    stack<long long>st;
    long long mini ;
    //1. push operation
    void push(int val) {
       if(st.empty()){
            mini = val;
            st.push(val);
       }
        else
        {
            if(val > mini)
            {
                st.push(val);
            }
            else
            {
                st.push(2*(long long)val-mini);
                mini = val;
            }
        }
    }

    //2. pop operation
    void pop() {
       if(st.empty()) return;
       long long x = st.top();
       st.pop();
       if(x < mini)
            mini = 2*mini-x;
    }
    
    //2. get top operation
    int top() {
        long long x = st.top();
        if(mini < x)
            return (int) x;
        else
            return(int) mini;

        
    }
    
    int getMin() {
        return (int)mini; 
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

//Brute force approach:

//  class MinStack {
// public:
//     MinStack() {}
//     stack<pair<int,int>>st;
//     //1. push operation
//     void push(int val) {
//       if(st.empty())
//         st.push({val,val});
//       else
//         st.push({val,min(val,st.top().second)});
//     }

//     //2. pop operation
//     void pop() {
//         st.pop();
//     }
    
//     //2. get top operation
//     int top() {
//         int ele = st.top().first;
//         return ele;
        
//     }
    
//     int getMin() {
    
//        int ele =  st.top().second;
//        return ele;
//     }

// };
