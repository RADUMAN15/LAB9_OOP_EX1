#include <iostream>
#include <string>
#include <sstream>     
#include <map>
#include <queue>

using namespace std;
class Compare{
public:
	Compare(){};
	bool operator() (const pair<string,int> &a, const pair<string, int> &b) 
	{
			if (a.second == b.second)
				return a.first > b.first;

			return a.second < b.second;
	}
};

int main()
{
	string text("I bought an apple. Then I eat an apple. Apple is my favorite.");
	for (int i = 0; text[i] != '\0'; i++)
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = text[i] - 'A' + 'a';

	map<string, int> perechi;
	map<string, int>::iterator it;

	stringstream ss(text);
	string wrd;
	while (getline(ss, wrd, ' ')) { 	//" ,.?!"
		for (int i = 0; i < wrd.length(); i++)
			if (wrd[i] == ',' || wrd[i] == '!' || wrd[i] == '?' || wrd[i] == '.')
			{
				int j = i + 1;
				for (; j < wrd.length(); j++)
					wrd[j - 1] = wrd[j];
				wrd.resize(j - 1);
			}
		perechi[wrd]++;
	}
	priority_queue<pair<string,int>, vector<pair<string, int>>, Compare> out;
	for (it = perechi.begin(); it != perechi.end(); it++)
	{
		pair<string, int> aux;
		aux.first = it->first;
		aux.second = it->second;
		out.push(aux); // DC NU POT SA FAC ASTA ? si pot ce e mai jos ? */ -> pot da eu prost...
	}
	//for (const auto& pair : perechi)	//dc imi trebuie adresa acolo ? 
	//	out.push(pair);

	while (!out.empty()){
		cout << out.top().first << ' ' << out.top().second << endl;
		out.pop();
	}
	return 0;
}
