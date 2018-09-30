#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> output;

		int table[4] = { 0, 1, 1, 0 };

		for (int i = 0; i < pow(2, n); ++i) {
			int input = 0;
			int base = 4;
			int expand = 1;

			for (int j = 0; j < n; ++j) {
				input += table[i % base / expand] * pow(2, j);
				expand *= 2;
				base *= 2;
			}

			output.push_back(input);
		}

		return output;
	}

	vector<int> grayCode2(int n) {
		if (n == 0)
			return vector<int>(1, 0);

		if (n == 1)
			return vector<int>{0, 1};

		vector<int> res = grayCode(n - 1);
		int len = res.size();
		for (int i = len - 1; i >= 0; i--)
		{
			res.push_back(res[i] + int(pow(2, n - 1)));
		}

		return res;
	}

	vector<int> grayCode3(int n) {
		vector<int> res(1 << n);
		for (int i = 0; i < 1 << n; i++)
			res[i] = i ^ (i >> 1);
		return res;
	}

	vector<int> grayCode4(int n) {
		vector<int> res{ 0 };
		for (int i = 0; i < n; ++i) {
			int size = res.size();
			for (int j = size - 1; j >= 0; --j) {
				res.push_back(res[j] | (1 << i));
			}
		}
		return res;
	}

	void myMain() {
		int n = 2;
		vector<int> ret = grayCode4(n);
		for (int i = 0; i < ret.size(); ++i) {
			cout << ret[i] << "\n";
		}
	}
};
