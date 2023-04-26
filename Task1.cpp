#include <iostream>
#include <string>
#include<fstream>
#include<stdio.h>

using namespace std;

//Task1
//A text file is given. Necessary create new file and remove from it all unacceptable words. 
//The list unacceptable words can be found in another file.

string Erase()
{
	string sym_str = " ,:;.!?-";
	char xsym_str{};

	string str = "A text file: is given. And word fileshould be remove from it file!";
	string arrstr[3] = { "file", "remove", "word" };


	for (int i = 0; i < 3; i++)
	{
		int pos = 0, l = 0;
		l = arrstr[i].length();

		while (str.find(arrstr[i], pos) != -1)
		{
			pos = str.find(arrstr[i], pos);
			str.erase(pos, l);

			bool tf = true;
			do
			{
				int posend = pos + 1;
				xsym_str = str[pos];
				if (sym_str.find(xsym_str, 0) != -1 && str[posend] != '\0')
					str.erase(pos, 1);
				else
				{
					tf = false;
					break;
				}

			} while (tf);
		}
	}
	
	return str;
}

string* arrWord(int &i)
{
	int count = 0;
	string fname = "words.txt";
	string* arrw = nullptr;
	ifstream fin_w;
	fin_w.open(fname);

	if (!fin_w.is_open())
	{
		cout << "\n\tCannot open the file";
	}
	else
	{
		while (!fin_w.eof())
		{
			string str{};
			fin_w >> str;
			count++;
		}
		i = count;
		arrw = new string[count];
		count--;
		fin_w.seekg(0, ios::beg);

		while (!fin_w.eof())
		{
			string str{};
			fin_w >> arrw[count];
			count--;
		}
	}
	fin_w.close();

	return arrw;
}

int main()
{
	int size = 0;
	string *resFname = arrWord(size);
	for (int i = 0; i < size; i++)
		cout << *resFname++ << endl;

	return 0;
}