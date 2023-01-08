#include "easyfind.hpp"

int main(void) {
	srand(time(NULL));
	int soughtNumber;
	std::cout << "---------------Test vector---------------\n";
	std::vector<int> vectorArray;
	for (int i = 0; i < 10; ++i) {
		vectorArray.push_back(i);
	}
	std::vector<int>::iterator vectorIt;
	for (int i = 0; i < 10; ++i) {
		soughtNumber = rand() % 21;
		try {
	 		vectorIt = easyfind(vectorArray, soughtNumber);
			std::cout << "Sought number " << soughtNumber << " found in vectorArray\n";
		} catch (std::exception &e) {
			std::cout << "Sought number " << soughtNumber << " not found in vectorArray" << std::endl;
		}
	}
 	std::cout << "-----------------Test set----------------\n";
	std::set<int> arraySet;
	std::set<int>::iterator setIt;
	for (int i = 0; i < 10; ++i) {
		arraySet.insert(i);
	}
	for (int i = 0; i < 10; ++i) {
		soughtNumber = rand() % 21;
		try {
	 		setIt = easyfind(arraySet, soughtNumber);
			std::cout << "Sought number " << soughtNumber << " found in arraySet\n";
		} catch (std::exception &e) {
			std::cout << "Sought number " << soughtNumber << " not found in arraySet\n";
		}
	}
 	std::cout << "-----------------Test list----------------\n";
	std::list<int> listArray;
	std::list<int>::iterator listIt;
	for (int i = 0; i < 10; ++i) {
		listArray.push_front(i);
	}
	for (int i = 0; i < 10; ++i) {
		soughtNumber = rand() % 21;
		try {
	 		listIt = easyfind(listArray, soughtNumber);
			std::cout << "Sought number " << soughtNumber << " found in listArray\n";
		} catch (std::exception &e) {
			std::cout << "Sought number " << soughtNumber << " not found in listArray\n";
		}
	}
	return (0);
}