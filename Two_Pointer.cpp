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