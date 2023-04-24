#pragma once
#define MAXSIZE 100
template <typename T1, typename T2>
struct pair {
	T1 key=0;
	T2 value=0;
	int ind = 0;
};
template <typename T1,typename T2>
class Map {
private:
	//pair<T1,T2> *array;
	pair<T1,T2> array[100];
	const int size = 100;
	int index = 0;
public:
	Map() {
		//array = new pair<T1,T2>[5];
	};
	//~Map() {
	//	delete[]array;// = new pair<T1, T2>[size];
	//};

	/*Map(T2 value) {
		if (index == size) {
			printf("MAXSIZE has been reached");
			return;
		}
		array[index++] = 0;

	}*/
	T2& operator[](T1 key) {

		bool exista = false;
		int i = 0;
		for (i; i < size && !exista; i++)
			if (array[i].key == key)
				exista = true;
		
		if (exista)
		{
			array[i - 1].key = key;
			return array[i - 1].value;
		}
		else
		{
			array[index].key = key;
			if (index > 0)
				array[index].ind = array[index - 1].ind + 1;
			else
				array[index].ind = 0;
			return array[index++].value;
		}
	}
	pair<T1,T2> *begin() {
		return &array[0];
	}
	pair<T1,T2> *end() {
		return &array[index];
	}
	bool Get(const T1& key, T2& value) {

		for (int i = 0; i < size; i++)
			if (array[i].key == key)
			{
				array[i] = value;
				return true;
			}

		return false;
	}
	void Set(T1 key, T2 value){
		
		for (int i = 0; i < size; i++)
			if (array[i].key == key)
				array[i] = value;
		
	}
	void print()
	{
		for(int i = 0 ; i < index; i++)
			printf("Index:%d, Key=%d, Value=%s\n", i, array[i].key, array[i].value);
	}
	int Count()
	{
		return index;
	}
	void Clear() {
		for (int i = 0; i < index; i++){
			array[i].key = 0;
			array[i].value = NULL;
		}
		index = 0;
	}
	bool Delete(const T1& key) {
		
		for (int i = 0; i < size; i++)
			if (array[i].key == key) {
				for (int j = i; i < index - 1; j++)
				{
					array[j].key = array[j + 1].key;
					array[j].value = array[j + 1].value;
				}
				array[index].value = NULL;
				array[index].key = NULL;
				index--;
			}
	}
	/*pair<T1, T2> operator auto(T1 key, T2 value, int index) {

	}*/
};