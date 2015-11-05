#include <iostream>
#include <string>
#include <vector>
#include <cassert>

void add_fibo(std::vector <int> &fiboreeks)
{
	
	const int fibo_size = fiboreeks.size();
	
	assert(fibo_size > 1);
	
	fiboreeks.push_back(fiboreeks[fibo_size - 2] + fiboreeks[fibo_size - 1]);
	
	assert(fibo_size < fiboreeks.size());
	
}

void show_fibo(const std::vector <int> &fiboreeks)
{
	
	const int fibo_size = fiboreeks.size();
	
	assert(fibo_size > 1);
	
	int pos = 0;
	
	while (pos < fibo_size)
	{
		
		std::cout << pos + 1 << ":" << fiboreeks[pos] << "\n";
		
		++pos;
		
	}
		
}

int main()
{
	
	std::vector <int> fiboreeks = {1, 1};
	
	const int count = 20;
	
	int place = 0;
	
	while(place < count)
	{
		
		add_fibo(fiboreeks);
		
		++place;
		
	}
	
	show_fibo(fiboreeks);
	
	return 0;	
	
}
