
struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
