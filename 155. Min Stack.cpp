class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    int mIndex;
    MinStack() {
       mIndex = 0;
    }

    void push(int x) {
        st.push_back(x);
        if (st.back() < st[mIndex]) {
            mIndex = st.size() - 1;
        }
    }

    void pop() {
        st.pop_back();
        if (mIndex >= st.size()) {
            mIndex = 0;
            for (int i = 1; i < st.size(); i ++) {
                if (st[i] < st[mIndex]) {
                    mIndex = i;
                }
            }
        }
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return st[mIndex];
    }
};

// O(1) solution
public class MinStack {
    long min;
    Stack<Long> stack;

    public MinStack(){
        stack=new Stack<>();
    }

    public void push(int x) {
        if (stack.isEmpty()){
            stack.push(0L);
            min=x;
        }else{
            stack.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    public void pop() {
        if (stack.isEmpty()) return;

        long pop=stack.pop();

        if (pop<0)  min=min-pop;//If negative, increase the min value

    }

    public int top() {
        long top=stack.peek();
        if (top>0){
            return (int)(top+min);
        }else{
           return (int)(min);
        }
    }

    public int getMin() {
        return (int)min;
    }
}
