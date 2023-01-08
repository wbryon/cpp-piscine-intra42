#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

void print(Array<int>& arr) {
	for(size_t i = 0; i < arr.size(); ++i) {
		std::cout << "arr[" << i << "]= " << arr[i] << std::endl;
	}
}
int main(int, char**)
{
    Array<int> empty;
    std::cout << "-------------test0------------" << std::endl;
    print(empty);
    std::cout << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "-------------test1------------" << std::endl;
	print(numbers);
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "-------------test2------------" << std::endl;
		print(tmp);
        std::cout << "------------test3-------------" << std::endl;
		print(test);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[0] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------test4------------" << std::endl;
		print(numbers);

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}