/*Leetcode-49 Group Anagrams*/

//! Brute Force Approach
// bool checkAnagram(string a,string b)
//     {
//        sort(a.begin(),a.end());
//        sort(b.begin(),b.end());
//        return a==b;
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n = strs.size();
//         vector<bool>visited(n,false);
//         vector<vector<string>>answer;
//         for(int i=0;i<n;i++)
//         {
//             if(visited[i]==true)
//             {
//                 continue;
//             }
//             vector<string>group;
//             group.push_back(strs[i]);
//             visited[i]=true;
//             for(int j=i+1;j<n;j++)
//             {
//                 if(visited[j]==false && checkAnagram(strs[i],
//                 strs[j])){
//                     group.push_back(strs[j]);
//                     visited[j]=true;
//                 }
//             }
//             answer.push_back(group);
//         }
//         return answer;
//     }

//? Optimal or Better Approach
// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n = strs.size();
//         unordered_map<string,vector<string>>mpp;
//         for(string str : strs)
//         {
//            string key = str;
//            sort(key.begin(),key.end());
//            mpp[key].push_back(str); 
//         }
//         vector<vector<string>>answer;
//         for(auto it : mpp)
//         {
//           answer.push_back(it.second);
//         }
//         return answer;
//     }

/*Leecode-347 Top K Frequent Elements*/

//! Brute Force Approach
//  vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int,int>mpp;
//         for(auto it : nums){
//             mpp[it]++;
//         }
//         vector<pair<int,int>>freq(mpp.begin(),mpp.end());
//         sort(freq.begin(),freq.end(),[](pair<int,int>a,
//         pair<int,int>b){
//             return a.second>b.second;
//         });
//         vector<int>answer;
//         for(int i=0;i<k;i++)
//         {
//           answer.push_back(freq[i].first);
//         }
//         return answer;
//     }

//? Optimal or Better Approach
// vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int,int>mpp;
//         for(auto it : nums){
//             mpp[it]++;
//         }
//         vector<vector<int>>bucket(n+1);
//         for(auto it : mpp)
//         {
//             bucket[it.second].push_back(it.first);
//         }
//         vector<int>answer;
//         for(int i=bucket.size()-1;i>=0;i--)
//         {
//             for(auto it : bucket[i])
//             {
//                 answer.push_back(it);
//                 if(answer.size()==k) return answer;
//             }
//         }
//         return answer;
//     }

/*Leetcode-238. Product of Array Except Self*/
//! O(n) tc and sc solution

// vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>prefix(n);
//         prefix[0]=1;
//         for(int i=1;i<n;i++)
//         {
//            prefix[i] = prefix[i-1]*nums[i-1];
//         }
//         vector<int>suffix(n);
//         suffix[n-1]=1;
//         for(int i=n-2;i>=0;i--)
//         {
//             suffix[i] = suffix[i+1]*nums[i+1];
//         }
//         vector<int>answer(n);
//         for(int i=0;i<n;i++)
//         {
//             answer[i] = prefix[i]*suffix[i];
//         }
//         return answer;
//     }

//? TC-O(n) sc-O(1)
// vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>answer(n);
//         int prefixprod=1;
//         for(int i=0;i<n;i++)
//         {
//             answer[i]=prefixprod;
//             prefixprod*=nums[i];
//         }
//         int suffixprod=1;
//         for(int i=n-1;i>=0;i--)
//         {
//             answer[i]*=suffixprod;
//             suffixprod*=nums[i];
//         }
//         return answer;
//     }

/*Leetcode-36 Valid Sudoku*/
// bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i=0;i<9;i++)
//         {
//             unordered_set<char>st;
//             for(int j=0;j<9;j++)
//             {
//                if(board[i][j]== '.') continue;
//                if(st.count(board[i][j]))
//                {
//                  return false;
//                }
//                st.insert(board[i][j]);
//             }
//         }
//         for(int i=0;i<9;i++)
//         {
//             unordered_set<char>st;
//             for(int j=0;j<9;j++)
//             {
//                if(board[j][i]== '.') continue;
//                if(st.count(board[j][i]))
//                {
//                  return false;
//                }
//                st.insert(board[j][i]);
//             }
//         }
//         for(int i=0;i<9;i+=3)
//         {
//             for(int j=0;j<9;j+=3)
//             {
//                 unordered_set<char>st;
//                 for(int k=i;k<i+3;k++)
//                 {
//                   for(int l=j;l<j+3;l++)
//                   {
//                      if(board[k][l]=='.') continue;
//                      if(st.count(board[k][l]))
//                       {
//                         return false;
//                       }
//                       st.insert(board[k][l]);
//                    }
//                  }
//              }
//          }
//          return true;
//     }