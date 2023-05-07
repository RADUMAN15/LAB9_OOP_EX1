#include <iostream>
#include "Map.h"
int main() 
{
	Map<int, const char*> m;    
	m[10] = "C++";    
	m[20] = "test";   
	m[30] = "Poo";
	m[40] = "Foo";
	m[90] = "HTML";
	m[60] = "CSS";
	m[70] = "Js";
	m[800] = "Poo";
	for (auto [key, value, index] : m) 
	{ 
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value); 
	}  

	//.print();

	m[20] = "result";
	for (auto [key, value, index] : m) 
	{ 
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value); 
	} 	   
	return 0;
}