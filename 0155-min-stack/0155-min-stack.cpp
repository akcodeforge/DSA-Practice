class MinStack {
public:
    stack<long long>st;
    long long minm;
    MinStack() {   ///constructor
        minm=LLONG_MAX;
    }
    
    void push(int value) {
        long long x= (long long) value;
        if(st.size()==0){
            st.push(x);
            minm=x;
        }
        else if(x>=minm) st.push(x);
        else{
            st.push(2*x-minm);
            minm=x;
        }
    }
    
    void pop() {
        if(st.top()<minm){    //st.top()<min  : a fake element present
            /// before poping retrive the old min to min
            long long oldmin=2*minm-st.top();
            minm=oldmin;
        }
            st.pop();
    }
    
    int top() {
        if(st.top()<minm) return (int)minm;
        else return (int)(st.top()); 
    }
    
    int getMin() {
        return (int)minm;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */