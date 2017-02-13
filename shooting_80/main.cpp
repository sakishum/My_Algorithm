/**
 * @file main.cpp
 * @Synopsis  一个射击运动员打靶，靶一共有10环，连开10枪打中90环的可能性有多少种？
 *		靶上一共有10种可能——1环到10环，还有可能脱靶，那就是0环，加在一起公有11种可能。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-05-25
 */
#include <cstdlib>
#include <iostream>
#include <vector>

// 递归
std::vector<std::vector<int> > res;

void cumput(int score, int n, std::vector<int> &tmp) {
	// 如果出现这种情况，即使后面每枪都打 10 环也无法打够总环数 score，这种情况下就不用再打了，则退出递归。
	if (score < 0 || score > n*10) {
		return;
	}
	// 如果满足条件且打到最后一次（因为必须打 n 次）
	if (0 == n && 0 == score) {
		res.push_back(tmp);
		return;
	}
	//如果没有出现以上两种情况则执行递归
	for (int i = 0; i < 11; ++i) {
		// 这里实际上为了方便把顺序倒了过来，store[num] 是最后一次打的出现的环数
		// 每一次打都 11 种环数可以选择
		tmp.push_back(i);
		cumput(score - i, n - 1, tmp);
		tmp.pop_back();
	}
}

int main(void) {
	std::vector<int> tmp;
	cumput(20, 3, tmp);
	std::cout << res.size() << std::endl;
	for (auto &iter :res) {
		for (auto &it : iter) {
			std::cout << "score: " << it << ",\t";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
