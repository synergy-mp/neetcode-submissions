// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unordered_set<string> n;
//         for(string num1 : s){
//             n.insert(num1);
//         }
//         unordered_set<string> m;
//         for(string num2 : t){
//             m.insert(num2);
//         }
//         if(m=n){
//             return true;
//         }
//         else{
//         return false;}

        
//     }
// };
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};