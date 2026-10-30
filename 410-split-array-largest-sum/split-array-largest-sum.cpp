
class Solution {
public:

    bool isPossible(vector<int>& nums, int k, long long mid) {
        int subarrays = 1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
