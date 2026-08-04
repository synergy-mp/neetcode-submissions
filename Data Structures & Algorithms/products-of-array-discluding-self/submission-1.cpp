// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n);
        
//         for(int i =0;i<n;i++){
//             int prod =1;
//             for(int j=0; j<n;j++){
//                 if(i!=j){
//                     prod*= nums[j];
//                 }
//             }
//             res[i]= prod;
            
//         }
//         return res;

//     }
// };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int prod=1, zerocount =0;
//         for(int num: nums){
//             if(num !=0){
//                 prod *= num;
//             }
//             else{
//                 zerocount++;
//             }
//         }
//         if(zerocount>1){
//             return vector<int>(nums.size(),0);
//         }
//         vector<int> res(nums.size());
//         for(size_t i=0; i< nums.size(); i++){
//             if(zerocount >0){
//                 res[i]= (nums[i]==0) ? prod : 0;

//             }
//             else{
//                 res[i]= prod / nums[i];
//             }
//         }
//         return res;

//     }
// };


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0]= 1;
        suff[n-1]= 1;
        for(int i=1;i<n;i++){
            pref[i]= nums[i-1]*pref[i-1];

        }
        for(int i= n-2; i>=0; i--){
            suff[i]= nums[i+1]*suff[i+1];

        }
        for(int i=0; i<n; i++){
            res[i] = pref[i]*suff[i];
        }
        return res;
    }

};