 
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            char prev=s[i];
            char next=s[i+1];
            if(prev=='I' && next=='V' || prev=='I' && next=='X' ){
                ans=ans-1;
            }
            else if(prev=='X' && next=='L' || prev=='X' && next=='C'){
                ans=ans-10;
            }
            else if(prev=='C' && next=='D' || prev=='C' && next=='M'){
                ans=ans-100;
            }
            else{
                if(prev=='I'){ans=ans+1;}
                else if(prev=='V'){ans=ans+5;}
                else if(prev=='X'){ans=ans+10;}
                else if(prev=='L'){ans=ans+50;}
                else if(prev=='C'){ans=ans+100;}
                else if(prev=='D'){ans=ans+500;}
                else {ans=ans+1000;}
                
            }
        }
        return ans;
    }
};