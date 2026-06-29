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