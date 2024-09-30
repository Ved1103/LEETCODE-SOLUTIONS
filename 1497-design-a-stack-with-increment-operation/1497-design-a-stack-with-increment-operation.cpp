class CustomStack {
private:
    int maxSize;
    int top;
    vector<int> stackvec;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stackvec.resize(maxSize);
        top = 0;
    }

    void push(int x) {
        if (top < maxSize) {
            stackvec[top++] = x;
        }
    }

    int pop() {
        if (top == 0) {
            return -1;
        }
        return stackvec[--top];
    }

    void increment(int k, int val) {
        int limit = min(k, top);
        for (int i = 0; i < limit; ++i) {
            stackvec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */