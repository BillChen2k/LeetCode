//给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。 
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。 
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
// 
//
// 示例 1： 
//
// 
//输入：x = 123
//输出：321
// 
//
// 示例 2： 
//
// 
//输入：x = -123
//输出：-321
// 
//
// 示例 3： 
//
// 
//输入：x = 120
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：x = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// -231 <= x <= 231 - 1 
// 
// Related Topics 数学 
// 👍 2537 👎 0


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int _reverse(int x) {
        bool minus = false;
        if (x < 0) {
            x = -x;
            minus = true;
        }
        int out = 0;
        do {
            out *= 10;
            out += x % 10;
            x = x / 10;
        } while(x > 0);
        if (!minus) {
            return max(out, 0);
        }
        else {
            return min(0, -out);
        }
    }

    int reverse(int x) {
        int upper = 1 << 31 - 1;
        int lower = - 1<<32;
        if (x > _reverse(upper) || x < _reverse(lower)) {
            return 0;
        }
        else {
            return _reverse(x)
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
