class MinStack {
public:
    stack<int> st, minimum;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minimum.empty()) minimum.push(val);
        else {
            minimum.push(min(val, minimum.top()));
        }
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minimum.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};


// class MinStack {
//     int size;
//     int* arr;
//     int tops; 
// public:
//     MinStack() {
//         size = 100001;
//         arr = new int[size];
//         tops = -1;
//     }
    
//     void push(int val) {
//         if (tops == size - 1) {
//             cout << "stack Full";   
//         } else {
//             tops++;
//             arr[tops] = val;
//         }
//     }
    
//     void pop() {
//         tops--;
//     }
    
//     int top() {
//         return arr[tops];
//     }
    
//     int getMin() {
//         int min = arr[0];
//         for (int i = 1; i <= tops; i++) {
//             if (arr[i] < min) {
//                 min = arr[i];
//             }
//         }
//         return min;
//     }
// };
