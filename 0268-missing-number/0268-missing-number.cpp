class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0;i<nums.size();i++){
            xor1 ^= nums[i];
        }
        for(int i = 1;i<=n;i++){
            xor2 ^= i;
        }
        return xor1 ^ xor2;
    }
};