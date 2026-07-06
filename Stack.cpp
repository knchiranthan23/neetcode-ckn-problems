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

/*Leetcode 150. Evaluate Reverse Polish Notation*/
//!Solution
// int evalRPN(vector<string>& tokens) {
//         stack<int>st;
//         for(string str : tokens)
//         {
//             if(str == "+")
//             {
//                 int a=st.top();
//                 st.pop();
//                 int b=st.top();
//                 st.pop();
//                 st.push(b+a);
//             }
//             else if(str == "-")
//             {
//                 int a=st.top();
//                 st.pop();
//                 int b=st.top();
//                 st.pop();
//                 st.push(b-a);
//             }
//             else if(str == "*")
//             {
//                 int a=st.top();
//                 st.pop();
//                 int b=st.top();
//                 st.pop();
//                 st.push(b*a);
//             }
//             else if(str == "/")
//             {
//                 int a=st.top();
//                 st.pop();
//                 int b=st.top();
//                 st.pop();
//                 st.push(b/a);
//             }
//             else{
//                 int num=stoi(str);
//                 st.push(num);
//             }
//         }
//         return st.top();
//     }

/*496. Next Greater Element I*/
//!Brute Force Approach
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>answer(nums1.size(),-1);
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                if(nums1[i]==nums2[j])
//                {
//                  for(int k=j+1;k<nums2.size();k++)
//                  {
//                     if(nums2[k]>nums2[j])
//                     {
//                         answer[i]=nums2[k];
//                         break;
//                     }
//                  }
//                }
//                else{
//                   continue;
//                }
//             }
//         }
//         return answer;
//     }

//todo : Optimal Approach
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        int n1=nums1.size();
//        int n2=nums2.size();
//        unordered_map<int,int>mpp;
//        stack<int>st;
//        for(int i=n2-1;i>=0;i--)
//        {
//          while(!st.empty() && st.top()<=nums2[i])
//          {
//             st.pop();
//          }
//          if(st.empty())
//          {
//             mpp[nums2[i]]=-1;
//          }
//          else{
//             mpp[nums2[i]]=st.top();
//          }
//          st.push(nums2[i]);
//        }
//        vector<int>answer;
//        for(int i=0;i<n1;i++)
//        {
//         answer.push_back(mpp[nums1[i]]);
//        }
//        return answer;
//     }

/*Leetcode 739. Daily Temperatures*/
//! Brute Force Approach
// vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int>ans(n,0);
//         for(int i=0;i<n;i++)
//         {
//             int count=1;
//             for(int j=i+1;j<n;j++){
//                 if(temperatures[i]<temperatures[j])
//                 {
//                     ans[i]=count;
//                     break;
//                 }
//                 count++;
//             }
//         }
//         return ans;
//     }

//todo : Optimal Approach
// vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int>ans(n);
//         stack<int>st;
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!st.empty() && temperatures[st.top()]<=temperatures[i])
//             {
//                 st.pop();
//             }
//             if(st.empty())
//             {
//                 ans[i]=0;
//             }
//             else{
//                 ans[i]=st.top()-i;
//             }
//             st.push(i);
//         }
//         return ans;
//     }

/*853. Car Fleet*/
//! Optimal Approach with stack
// int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         int n=position.size();
//         vector<pair<int,int>>cars;
//         for(int i=0;i<n;i++)
//         {
//             cars.push_back({position[i],speed[i]});
//         }
//         sort(cars.begin(),cars.end());
//         stack<double>st;
//         for(int i=n-1;i>=0;i--)
//         {
//             double time = (double)(target-cars[i].first)/cars[i].second;
//             if(st.empty() || time>st.top())
//             {
//                 st.push(time);
//             }
//         }
//         return st.size();
//     }