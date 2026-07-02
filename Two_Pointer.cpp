/*Leetcode-125 Valid Palindrome*/

//! Brute Force Method
//  bool isPalindrome(string s) {
//         int n = s.size();
//         string org = "";
//         for(auto ch : s)
//         {
//             if(isalnum(ch)){
//                 org+=tolower(ch);
//             }
//         }
//         string rev = "";
//         for(auto val : org)
//         {
//             rev=val+rev;
//         }
//         return org==rev;
//     }

//? Optimal Solution
// bool isPalindrome(string s) {
//         int n = s.size();
//         int left=0,right=n-1;
//         while(left<=right)
//         {
//             while(left<right && !isalnum(s[left]))
//             {
//                 left++;
//             }
//             while(left<right && !isalnum(s[right]))
//             {
//                 right--;
//             }
//             if(tolower(s[left]) != tolower(s[right]))
//             {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }

/*167. Two Sum II - Input Array Is Sorted*/
// vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size();
//         int l=0,r=n-1;
//         vector<int>answer;
//         while(l<=r)
//         {
//             int sum=numbers[l]+numbers[r];
//             if(sum == target)
//             {
//                answer.push_back(l+1);
//                answer.push_back(r+1);
//                break;
//             }
//             else if(sum>target)
//             {
//                 sum=sum-numbers[r];
//                 r--;
//             }
//             else{
//                 sum=sum-numbers[l];
//                 l++;
//             }
            
//         }
//         return answer;
//     }

/*11. Container With Most Water*/
//!Brute Force Approach
// int maxArea(vector<int>& height) {
//         int maxarea=0;
//         int n = height.size();
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//               int width = j-i;
//               int hght = min(height[i],height[j]);
//               int area = width*hght;
//               maxarea = max(maxarea,area);
//             }
//         }
//         return maxarea;
//     }