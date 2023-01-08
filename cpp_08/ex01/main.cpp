#include "span.hpp"

int main()
{
	std::cout << "---------- TEST 1 ----------" << std::endl;

	Span sp = Span(5);
	sp.addNumber(4);
	sp.addNumber(2);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Biggest number is " << sp.maxElement() << std::endl;
	std::cout << "Shortest number is " << sp.minElement() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(123);
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Caught error while trying to add element: " << e.what() << std::endl;
	}

	Span empty(0);

	try
	{
		empty.shortestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Caught error while trying to get shortest span cause " << e.what() << std::endl;
	}

	try
	{
		empty.longestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Caught error while trying to get longest span cause " <<
				  e.what() << std::endl;
	}

	std::cout << std::endl << "---------- TEST 2 ----------" << std::endl;

	Span mid(10000);

	std::srand(std::time(NULL));
	try
	{
		for (int i = 0; i < 10001; i++)
			mid.addNumber(std::rand());
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Array was filled caught the error: " << e.what() << std::endl;
	}

	int shortSpan = mid.shortestSpan();
	int longSpan = mid.longestSpan();
	std::cout << "Biggest number is " << mid.maxElement() << std::endl;
	std::cout << "Shortest number is " << mid.minElement() << std::endl;
	std::cout << "Shortest span: " << shortSpan << std::endl;
	std::cout << "Longest span: " << longSpan << std::endl;

	std::cout << std::endl << "---------- TEST 3 ----------" << std::endl;
	Span big(20000);

	try
	{
		for (int i = 0; i < 20001; i++)
			big.addNumber(std::rand());
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Array was filled caught the error: " << e.what() << std::endl;
	}

	shortSpan = big.shortestSpan();
	longSpan = big.longestSpan();
	std::cout << "Biggest number is " << big.maxElement() << std::endl;
	std::cout << "Shortest number is " << big.minElement() << std::endl;
	std::cout << "Shortest span: " << shortSpan << std::endl;
	std::cout << "Longest span: " << longSpan << std::endl;
}