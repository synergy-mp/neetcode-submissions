// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> res;
//         for(auto& s : strs){
//             string sortedS = s;
//             sort(sortedS.begin(),sortedS.end());
//             res[sortedS].push_back(s);
//         }
//         vector<vector<string>> result;
//         for(auto& pair:res){//using const is a practise doesn't affecxt much
//             result.push_back(pair.second);//grouping part--crazyy

//         }
//         return result;
//     }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);//to_string is a function used to convet number to string
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};