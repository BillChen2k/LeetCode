#include "header.h"
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (44.72%)
 * Likes:    874
 * Dislikes: 0
 * Total Accepted:    164.7K
 * Total Submissions: 368.4K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start

struct direction {
    int x, y;
    direction(int x, int y) : x(x), y(y) {}
};

vector<direction> d = {direction(1, 0), direction(-1, 0), direction(0, 1), direction(0, -1)};

class Solution {
public:

    bool dfs(vector<vector<char>>& board, vector<vector<bool>> & used, int i, int j, string &current, string &word) {
        if (current == word) {
            return true;
        }
        if (current.size() >= word.size()) return false;
        used[i][j] = true;
        for (auto &dir : d) {
            if (i < board.size() - dir.x && j < board[0].size() - dir.y 
                && i + dir.x >= 0 && j + dir.y >= 0 && !used[i + dir.x][j + dir.y] 
                && word[current.size()] == board[i + dir.x][j + dir.y]) {
                current += board[i + dir.x][j + dir.y];
                used[i + dir.x][j + dir.y] = true;
                if(dfs(board, used, i + dir.x, j + dir.y, current, word)) {
                    return true;
                }
                used[i + dir.x][j + dir.y] = false;
                current.erase(current.end() - 1);
            }
	    }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		        string init = string(1, board[i][j]); 
                bool result = dfs(board, used, i, j, init, word);
		        if (result)
                    return true;
                }
        }
        return false;

    }
};
// @lc code=end

int main() {

}
