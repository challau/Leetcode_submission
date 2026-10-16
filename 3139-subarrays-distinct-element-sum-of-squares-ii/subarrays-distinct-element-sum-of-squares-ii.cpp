class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    vector<ll> s, sq, lazy;
    int n;

    void push(int p, int l, int r) {
        if (!lazy[p]) return;
        ll d = lazy[p], len = r - l + 1;
        int a = p * 2, b = a + 1;
        sq[a] = (sq[a] + 2 * d * s[a] + d * d * ((len + 1) / 2)) % MOD;
        sq[b] = (sq[b] + 2 * d * s[b] + d * d * (len / 2)) % MOD;
        s[a] = (s[a] + d * ((len + 1) / 2)) % MOD;
        s[b] = (s[b] + d * (len / 2)) % MOD;
        lazy[a] += d;
        lazy[b] += d;
        lazy[p] = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            ll len = r - l + 1, d = 1;
            sq[p] = (sq[p] + 2 * s[p] + len) % MOD;
            s[p] = (s[p] + len) % MOD;
            lazy[p]++;
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(p * 2, l, m, ql, qr);
        if (qr > m) update(p * 2 + 1, m + 1, r, ql, qr);
        s[p] = (s[p * 2] + s[p * 2 + 1]) % MOD;
        sq[p] = (sq[p * 2] + sq[p * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        s.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};