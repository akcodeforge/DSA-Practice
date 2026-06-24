class MyQueue {
public:
    stack<int>ans;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
       ans.push(x); 
    }
    
    int pop() {
        // if(ans.size()==0){
        //     return -1;
        // }
        while(ans.size()>0){
            helper.push(ans.top());
            ans.pop();
        }
        int x= helper.top();
        helper.pop();
        while(helper.size()>0){
            ans.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {
        while(ans.size()>0){
            helper.push(ans.top());
            ans.pop();
        }
        int x= helper.top();
        while(helper.size()>0){
            ans.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(ans.size()==0) return true;
        else return false;
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