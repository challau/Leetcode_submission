
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        int lo = 0, hi = 100000;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long need = 0;

            for (int x : diff) {
                need += max(0, x - mid);
            }

            if (need <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long ans = 0, need = 0;

        for (int x : diff) {
            int y = min(x, lo);
            ans += 1LL * y * y;
            need += max(0, x - lo);
        }

        long long left = k - need;
        ans -= left * (2LL * lo - 1);

        return ans;
    }
};