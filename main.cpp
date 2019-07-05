#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isLeaf(TreeNode *r) {
        return r && !r->left && !r->right;
    }

    void DFS(TreeNode *r, int val, int &sum) {
        if (!r) return;
        val <<= 1;
        if (r->val == 1) val |= 1;
        if (isLeaf(r)) {
            sum += val;
            return;
        }
        DFS(r->left, val, sum);
        DFS(r->right, val, sum);
    }

    int sumRootToLeaf(TreeNode *root) {
        int sum = 0;
        int val = 0;
        DFS(root, val, sum);
        return sum;
    }
};

void test1() {
    auto t1 = new TreeNode("1,0,1,0,1,0,1");
    cout << "22 ? " << Solution().sumRootToLeaf(t1) << endl;
}

void test2() {

}

void test3() {

}