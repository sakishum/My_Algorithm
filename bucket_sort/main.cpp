#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#define LOG(x)  do { std::cout << "LOG: " << (x) << std::endl; } while(0);

template <typename C>
void bucket_sort(C& ca) {
	int n = ca.size();
	int k = 0, i = 0;
	LOG(n);
	std::vector<std::list<int> > vld(n);

	for (int i = 0; i != n; ++i) {
		k = n*ca[i];
		LOG(ca[i])
		vld[k].push_back(ca[i]);
	}

	std::list<int> caTemp;
	for (int i = 0; i != n; ++i) {
		if (vld.empty()) {
			vld[i].sort();
			caTemp.merge(vld[i]);
		}
	}
	 
	i = 0;
	for (auto x: caTemp) {
		ca[i] = x;
		++i;
	}
}

template <typename T> 
class Print {
public:
	Print(void) { }
	void inline operator()(const T& x) const { std::cout << x << " "; }
};

int main(void) {
	int arr[] = {897, 565, 656, 1234, 665, 3434};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::vector<int> ld(arr, arr + n);
	for (int i = 0; i != n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	bucket_sort(ld);
	for (int i = 0; i != n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return EXIT_SUCCESS;
}
