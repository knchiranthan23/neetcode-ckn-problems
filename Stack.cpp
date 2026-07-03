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

