// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int ans=0;
        for(auto num : tokens){
            if(num=="+" or num == "-" or num== "*" or num=="/"){
                int b=stk.top();
                stk.pop();
                int a=stk.top();
                stk.pop();                
                if(num=="+"){
                    stk.push(a+b);
                }else if(num=="-"){
                    stk.push(a-b);
                }else if(num=="*"){
                    stk.push(a*b);
                }else{
                    stk.push(a/b);
                }
            }else{
                stk.push(stoi(num));
            }
        }
        return stk.top();
    }
};