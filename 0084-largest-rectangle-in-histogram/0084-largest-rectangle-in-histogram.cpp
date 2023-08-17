class Solution {
private:
    vector<int> nextSmallerEvent(vector<int>& arr,int size){
        vector<int> ans(size);
        stack<int> temp;
        temp.push(-1);
        for(int i=size-1;i>=0;i--){
            while(temp.top()!= -1 && arr[i]<=arr[temp.top()]){
                temp.pop();
            }
            ans[i]=temp.top();
            temp.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerEvent(vector<int>& arr,int size){
        vector<int> ans(size);
        stack<int> temp;
        temp.push(-1);
        for(int i=0;i<size;i++){
            while(temp.top()!= -1 && arr[i]<=arr[temp.top()]){
                temp.pop();
            }
            ans[i]=temp.top();
            temp.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextSmallerEvent(heights,n);
        
        vector<int> prev(n);
        prev=prevSmallerEvent(heights,n);
        int area=(-1000);
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);  
        }
        return area;
    }
};