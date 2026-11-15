class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_number = *max_element(nums.begin(),nums.end());

        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += abs(nums[i] - max_number);
        }

        return sum;
    }
};