#include <iostream>
#include <string>
#include<fstream>
#include<stdio.h>
#include <cstdlib>

using namespace std;

//Task1
//A text file is given. Necessary create new file and remove from it all unacceptable words. 
//The list unacceptable words can be found in another file.

string* arrWord(int& i)
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

string Erase(string str)
{
	int size = 0;
	string* arrstr = arrWord(size);

	string sym_str = " ,:;.!?_s";
	char xsym_str{};

	for (int i = 0; i < size; i++)
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

int main()
{
	string file = "file_old.txt";
	string filex = "file_new.txt";

	//============Before erased=================

	ifstream fin_f;
	fin_f.open(file);

	ofstream fout_x;
	fout_x.open(filex);

	if (!fin_f.is_open() || !fout_x.is_open())
	{
		cout << "\n\tCannot open the file";
	}
	else
	{
		while (!fin_f.eof())
		{
			string txt{};
			getline(fin_f, txt);
			fout_x << Erase(txt) << "\n";
		}
	}
	fin_f.close();
	fout_x.close();

	return 0;
}