class Solution {
public:
    int countSeniors(vector<string>& details) {
        int counter=0;
        for(int i=0;i<details.size();i++){
            if(details[i].substr(11,2)>"60"){
                counter++;
            }
        }
        return counter;
    }
};