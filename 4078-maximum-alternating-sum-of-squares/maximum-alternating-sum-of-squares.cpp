class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> v;

        for(int i = 0; i < nums.size(); i++) {
            int long long x = nums[i];
            v.push_back(x * x);
        }

        long long sum = 0;
        sort(v.begin(),v.end());
        int n = v.size();

        for(int i = 0; i < n/2; i++) {
            sum -= v[i];
        }

        for(int i = n/2; i < n; i++) {
            sum += v[i];
        }
        return sum;
    }
};