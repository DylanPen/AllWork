#include "recursion.hpp"

int no_zero_strings(int n) {
	// TODO Complete this function
	if (n == 0){
		return 1;
	}
	if(n == 1){
		return 2;
	}
	// here returns a dummy value. You need to modify this!
	return no_zero_strings(n - 1) + no_zero_strings(n - 2);
}
