#include "header.h"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.30%)
 * Likes:    1351
 * Dislikes: 0
 * Total Accepted:    163K
 * Total Submissions: 311.7K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 * 
 * 
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value)
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * 最多调用 3 * 10^4 次 get 和 put
 * 
 * 
 */

// @lc code=start
struct CacheItem {
	int value;
	time_t timestamp;
	CacheItem(int v, time_t t) : value(v), timestamp(t) {}
};

struct Node {
	int value;
	Node *prev;
	Node *next;
    Node() : value(-1), prev(NULL), next(NULL) {}
	Node(int v) : value(v), prev(NULL), next(NULL) {}
	Node(int v, Node *p, Node *n) : value(v), prev(p), next(n) {}
};

class LRULinkedList {
      private:
	Node *head;
	Node *tail;
	int count;

      public:
	LRULinkedList() {
		head = NULL;
        tail = NULL;
		count = 0;
	}

	Node *moveElementToTail(int v) {
		Node *p = head;
		while (p->value != v) {
			p = p->next;
		}
		if (p->prev) {
			p->prev->next = p->next;
		}
		if (p->next) {
			p->next->prev = p->prev;
		}
		tail->next = p;
		p->prev = tail;
		return p;
	}

	void addToTail(int v) {
		Node *p = new Node(v);
		if (head) {
			tail->next = p;
			p->prev = tail;
		} else {
			head = p;
		}
		tail = p;
		count++;
	}

	Node *getHead() {
		return head;
	}

	/**
     * @brief Returns the value of the head;
     */
	int removeHead() {
		if (!head) {
			return -1;
		}
		Node *p = head;
		int res = p->value;
		head = head->next;
		count--;
		delete p;
		return res;
	}
};

class LRUCache {
      public:
	unordered_map<int, CacheItem *> cache;
	LRULinkedList list;
	int max_size;

	LRUCache(int capacity) {
		max_size = capacity;
	}

	bool exists(int v) {
		return cache.find(v) != cache.end();
	}

	int get(int key) {
		if (!exists(key)) {
			return -1;
		}
		auto item = cache[key];
		cache[key]->timestamp = time(NULL);
		list.moveElementToTail(key);
		return item->value;
	}

	void put(int key, int value) {
		if (exists(key)) {
			cache[key]->value = value;
			cache[key]->timestamp = time(NULL);
			list.moveElementToTail(key);
		} else {
			if (cache.size() >= max_size) {
				auto to_remove = list.getHead()->value;
                cout << "Remove" << to_remove << endl;
				list.removeHead();
				cache.erase(key);
			}
			cache[key] = new CacheItem(value, time(NULL));
			list.addToTail(key);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache l(2);
    l.put(1,1);
    l.put(2,2);
    l.get(1);
    l.put(3,3);
    l.get(2);
    l.put(4,4);
    l.get(1);
    l.get(3);
    l.get(4);
}
