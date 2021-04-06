#include "header.h"
/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 *
 * https://leetcode-cn.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (83.81%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 15.9K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl
 * 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.
 * 
 * 要求：设计一个 TinyURL 的加密 encode 和解密 decode
 * 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。
 * 
 */

// @lc code=start
class Solution {
      public:
	using ull = unsigned long long;

	unordered_map<string, pair<ull, string> > urls;
	const int base = 11;
	const string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	const ull len = code.size();

	ull hashcode(const string &s) {
		ull hash = 0;
		for (auto c : s) {
			hash *= base;
			hash += (c % base);
		}
		return hash;
	}

	string hash2string(ull n) {
		string s;
		while (n != 0) {
			s += code[n % len];
			n /= len;
		}
		return s;
	}

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string shortUrl = hash2string(hashcode(longUrl));
		urls[shortUrl] = make_pair(hashcode(longUrl), longUrl);
		return "https://tinyurl.com/" + shortUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {

		return urls[shortUrl.replace(0, 20, "")].second;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

int main() {
	Solution s;
	vector<string> raw = {
	    "https://billc.io/2020/04/latex-relati2nal-algebra/latex-relational-algebra/",
	    "https://billc.io/2020/04/latex-relati2nal-algebra/",
	    "https://billc.io/2019/04/pandas-append-excel/",
	    "https://billc.io/",
	    "https://billc.io/2019/03/airport-simulation/"};
	for (auto &str : raw) {
		s.encode(str);
	}
	return 0;
}
