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

string Erase(string &str)
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

void Operation(string *file, string *filex)
{
	//============Function erased=================

	ifstream fin_f;
	fin_f.open(*file);

	ofstream fout_x;
	fout_x.open(*filex);

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
}

void Menu(string *file, string *filex)
{
	int size = 0;
	string* arrw = arrWord(size);

	cout << "\n Operations find & erase unaccaptable words";
	cout << "\n List of accaptable words:\n";
	for (int i = 0, n = 1; i < size; i++)
	{
		cout << "\t";
		cout << n << ". " << arrw[i] << " & " << arrw[i++] << "\n";
		n++;
	}

	cout << "\n Confirm to modify file: \"" << *file << "\"";
	cout << "\n\tY -  YES : N - NO";
	char ch{};
	cout << "\n\tENTER: ";
	cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		Operation(file, filex);
		cout << "\n\t!CHANGES DONE!";
		cout << "\n\tCheck file: \"" << *filex << "\"";
	}
	else
	{
		cout << "\n\t!CHANGES CANCELLED!";
	}
}

int main()
{
	string f1 = "file_old.txt";
	string f2 = "file_new.txt";

	string* pf1 = &f1;
	string* pf2 = &f2;

	Menu(pf1, pf2);
	cout << endl;

	return 0;
}