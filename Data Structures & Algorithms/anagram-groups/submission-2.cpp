class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(auto& s : strs){
            string sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair:res){//using const is a practise doesn't affecxt much
            result.push_back(pair.second);//grouping part--crazyy

        }
        return result;
    }
};
