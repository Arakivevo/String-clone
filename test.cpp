#include "String.hpp"

void* operator new(size_t size) {
	std::cout << " Allocating " << size << " bytes \n";
	return malloc(size);
}

void string_clone(String text) {
	text.Print();

	int i = 0;

	while (true)
	{
		printf("%c", text.get(i));
		i++;
	}
}

int main() {
	String text = "Araki";
	String dst;

	dst = std::move(text);

	text.Print();
	dst.Print();
}
