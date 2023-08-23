class MinStack {
    int size;
    int* arr;
    int tops; 
public:
    MinStack() {
        size = 100001;
        arr = new int[size];
        tops = -1;
    }
    
    void push(int val) {
        if (tops == size - 1) {
            cout << "stack Full";   
        } else {
            tops++;
            arr[tops] = val;
        }
    }
    
    void pop() {
        tops--;
    }
    
    int top() {
        return arr[tops];
    }
    
    int getMin() {
        int min = arr[0];
        for (int i = 1; i <= tops; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};
