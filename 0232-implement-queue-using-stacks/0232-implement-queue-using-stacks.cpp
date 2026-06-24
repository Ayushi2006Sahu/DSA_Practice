class MyQueue {
public:
    stack<int> inp, oup;

    MyQueue() {}

    void push(int x) { inp.push(x); }

    int pop() {
        if (oup.empty()) {
            while (inp.size()) {
                oup.push(inp.top());
                inp.pop();
            }
        } 
            int x = oup.top();
            oup.pop();
            return x;
        
    }

    int peek() {
        if (oup.empty()) {
            while (inp.size()) {
                oup.push(inp.top());
               inp.pop();
            }
        }
        return oup.top();
    }

    bool empty() {
      return inp.empty() && oup.empty();
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