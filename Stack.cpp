/*Leetcode 20.Valid Parentheses*/
//!Method
// bool isValid(string s) {
//        stack<char>st;
//        for(char ch : s)
//        {
//           if(ch=='('){st.push(')');}
//           else if(ch=='['){st.push(']');}
//           else if(ch=='{'){st.push('}');}
//           else{
//              if(st.empty() || st.top()!=ch)
//              {
//                 return false;
//              }
//              st.pop();
//           }
//        }
//        return st.empty(); 
//     }

/*Leetcode 155.MinStack*/
//? Brute Force Approach
//  MinStack() {
//     }
//     stack<int>st;
//     void push(int value) {
//         st.push(value);
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//       return st.top();
//     }
//     int getMin() {
//         stack<int>temp=st;
//         int minValue=INT_MAX;
//         while(!temp.empty())
//         {
//             minValue=min(minValue,temp.top());
//             temp.pop();
//         }
//         return minValue;
//     }

//todo : Optimal Approach
// MinStack() {
//     }
//     stack<int>st;
//     stack<int>minst;
//     void push(int value) {
//         st.push(value);
//         if(minst.empty()){
//             minst.push(value);
//         }
//         else{
//             minst.push(min(minst.top(),value));
//         }
//     }
    
//     void pop() {
//         st.pop();
//         minst.pop();
//     }
    
//     int top() {
//       return st.top();
//     }
//     int getMin() {
//         return minst.top();
//     }