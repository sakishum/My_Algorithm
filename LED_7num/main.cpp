#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

//这些数是表示0-9的LED显示 
char ptr[] = {
	119, 36, 93, 109, 46, 107, 123, 37, 127, 111
};

bool getBit(char c, int i) {
	return c&(1<<i);
}

int main(void) {
	std::string num = "1234890";
	int n = 3;
	int len = 0;
	len = num.length();
	
	std::vector<char> v;
	int i = 0;
	for (i = 0; i < len; ++i) {
		v.push_back(ptr[num[i] - '0']);
	}
	//是否为横向 
	bool isH = false;
	int j = 0, k = 0, l = 0;
	for(i = 0; i < 7; i++){
		//横向
		for(j = 0; j < len; j++){
			for(k = 0; k < n + 2; k++){
				if(i == 0 || i == 3 || i == 6){
					isH = true;
				}else{
					isH = false;
				}
				
				if(isH && (k == 0 || k == n + 1)){
					std::cout << "  ";
				}else if((i == 0 || i == 3 || i == 6) && getBit(v[j], i)){
					std::cout << "-";
				}else if((i == 0 || i == 3 || i == 6) && !getBit(v[j], i)){
					std::cout << " ";
				}
			}
			
		}
		
		//竖向 
		for(k = 0; k < n; k++){
			for(j = 0; j < len; j++){
				if((i == 1 || i == 4) && getBit(v[j], i)){
					std::cout << " |";
					for(l = 0; l < n; l++){
						std::cout << " ";
					}
				}else if((i == 1 || i == 4)&& !getBit(v[j], i)){
					std::cout << "  ";
					for(l = 0; l < n; l++){
						std::cout << " ";
					}
				}
				if(((i + 1) == 2 || (i + 1) == 5) && getBit(v[j], i + 1)){
					std::cout << " |";
				}else if(((i + 1) == 2 || (i + 1) == 5) && !getBit(v[j], i + 1)){
					std::cout << "  ";
				}
				
			}
			if(!isH){
				std::cout << std::endl;
			}
			
		}
		//已经输出了，所以需要跳掉 
		if(i == 1 || i == 4){
			i++;
		}else{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
} 
