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

//? Optimal Approach
//  int maxArea(vector<int>& height) {
//         int maxarea=0;
//         int n = height.size();
//         int l=0,r=n-1;
//         while(l<r)
//         {
//             int area = (r-l) * min(height[l],height[r]);
//             maxarea = max(maxarea,area);
//             if(height[l]<=height[r])
//             {
//                 l++;
//             }
//             else{
//                 r--;
//             }
//         }
//         return maxarea;
//     }

/*Leetcode 42. Trapping Rain Water*/
//! BF Approach
// int trap(vector<int>& height) {
//         int n=height.size();
//         int answer=0;
//         for(int i=1;i<n-1;i++)
//         {
//             int leftmax=0;
//             for(int j=0;j<=i;j++)
//             {
//                 leftmax = max(leftmax,height[j]);
//             }
//             int rightmax=0;
//             for(int k=i;k<n;k++)
//             {
//                 rightmax = max(rightmax,height[k]);
//             }
//             answer+=min(leftmax,rightmax)-height[i];
//         }
//         return answer;
//     }

//? Better Approach
// int trap(vector<int>& height) {
//         int n=height.size();

//         vector<int>leftmax(n);
//         leftmax[0]=height[0];
//         for(int i=1;i<n;i++)
//         {
//             leftmax[i]=max(leftmax[i-1],height[i]);
//         }
//         vector<int>rightmax(n);

//         rightmax[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--)
//         {
//             rightmax[i]=max(rightmax[i+1],height[i]);
//         }

//         int answer=0;
//         for(int i=0;i<n;i++)
//         {
//             answer+=min(leftmax[i],rightmax[i])-height[i];
//         }
//         return answer;
//     }


/*Optimal Approach*/
// int trap(vector<int>& height) {
//         int n=height.size();
//         int leftmax=0,rightmax=0;
//         int l=0,r=n-1;
//         int answer=0;
//         while(l<r)
//         {
//             leftmax=max(leftmax,height[l]);
//             rightmax=max(rightmax,height[r]);
//             if(leftmax>rightmax){
//                 answer+=min(leftmax,rightmax)-height[r];
//                 r--;
//             }
//             else{
//                 answer+=min(leftmax,rightmax)-height[l];
//                 l++;
//             }
//         }
//         return answer;
//     }