
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;

        long long d = tree[node].lazy;
        long long len = r - l + 1;
        int left = node * 2;
        int right = left + 1;

        for (int child : {left, right}) {
            long long oldSum = tree[child].sum;
            long long childLen = child == left
                ? (l + r) / 2 - l + 1
                : r - (l + r) / 2;

            tree[child].sq =
                (tree[child].sq + 2 * d * oldSum
                 + d * d * childLen) % MOD;

            tree[child].sum =
                (oldSum + d * childLen) % MOD;

            tree[child].lazy =
                (tree[child].lazy + d) % MOD;
        }

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            long long d = 1;
            long long len = r - l + 1;
            long long oldSum = tree[node].sum;

            tree[node].sq =
                (tree[node].sq + 2 * d * oldSum
                 + d * d * len) % MOD;

            tree[node].sum = (oldSum + len) % MOD;
            tree[node].lazy = (tree[node].lazy + d) % MOD;
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr) return tree[node].sq;

        push(node, l, r);

        int mid = l + (r - l) / 2;

        return (query(node * 2, l, mid, ql, qr)
              + query(node * 2 + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};
