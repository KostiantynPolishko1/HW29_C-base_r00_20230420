#include <iostream>
#include <string>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<cstdint>
#include<Windows.h>

using namespace std;

//Task2
//Write a transliteration program from Russian into English
//and vice versa.The data for transliteration is taken from 
//a file and written to another file. The translation direction 
//is determined by the user menu.

int checkV()
{
	int a;
	while (true) // the cycle continues until the user enters the correct value
	{
		cin >> a;
		if (cin.fail()) // if the previous extraction was unsuccessful,
		{
			cout << "\n\tIncorrect input, no int value: ";
			cout << "\n\tEnter -> ";
			cin.clear(); // then return the cin to 'normal' mode of operation
			cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
		}
		else // if all is well, return a
		{
			cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
			return abs(a);
		}
	}

	return 0;
}

bool TryCatch(string file)
{
	bool tf = false;

	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		fin.open(file);
		tf = true;
	}
	catch (const ifstream::failure& ex)
	{
		cout
			<< endl
			<< "\t" << ex.what() << endl
			<< "\t" << ex.code() << endl
			<< "\tERROR of the opening file: \"" << file << "\"" << endl;
	}

	return tf;
}

bool confirmAct()
{
	cout << "\n Confirm: Y - YES / N - NO";
restart2:
	cout << "\n   Press: \"Y\" / \"N\": ";

	char ch{};
	cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		return true;
	}

	if (ch == 'N' || ch == 'n')
	{
		cout << "\n !TRANLITERATION CANCELLED!\n";
		return false;
	}

	cout << "\n !INCORRECT INPUT!";
	goto restart2;
}

string translitRU_EN(string &str_ru)
{
	setlocale(LC_ALL, "ru");

	string
		ru = "àáâãäåçèéêëìíîïðñòóôûýÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÑÒÓÔÛÝ",
		ru2 = "æõö÷øþÿÆÕÖ×ØÞß",
		ru3 = "ùÙ";
	string
		en = "abvgdeziyklmnoprstufyeABVGDEZIYKLMNOPRSTUFYE",
		en2 = "zhkhtschshyuyaZhKhTsChShYuYa",
		en3 = "shchShch";
	string en_txt{};

	int n = 0;
	while (str_ru[n])
	{
		int pos = 0;
		string s = {};
		if (ru.find(str_ru[n]) != -1)
		{
			pos = ru.find(str_ru[n]);
			s = en[pos];
		}
		else
			if (ru2.find(str_ru[n]) != -1)
			{
				int i = 0;
				pos = ru2.find(str_ru[n]);
				i = pos * 2;
				s += en2[i];
				i++;
				s += en2[i];
			}
			else
				if (ru3.find(str_ru[n]) != -1)
				{
					int j = 0, count = 0;
					pos = ru3.find(str_ru[n]);
					j = pos * 4;
					while (count < 4)
					{
						s += en3[j];
						j++;
						count++;
					}
				}
				else
				{
					s = str_ru[n];
				}
		n++;
		en_txt += s;
	}

	return en_txt;
}

string translitEN_RU(string &str_en)
{
	string
		en = "abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZ",
		en2 = "qQ";

	string
		ru = "àáöäåôãõèéêëìíîïðñòóââõûçÀÁÖÄÅÔÃÕÈÉÊËÌÍÎÏÐÑÒÓÂÂÕÛÇ",
		ru2 = "êüþÊüþ";

	string ru_txt{};

	int i = 0;
	while (str_en[i])
	{
		int pos = 0;
		string s = {};
		if (en.find(str_en[i]) != -1)
		{
			pos = en.find(str_en[i]);
			s = ru[pos];
		}
		else
			if (en2.find(str_en[i]) != -1)
			{
				int j = 0, count = 0;
				pos = en2.find(str_en[i]);
				j = pos * 3;
				while (count < 3)
				{
					s += ru2[j];
					j++;
					count++;
				}
			}
			else
			{
				s = str_en[i];
			}
		i++;
		ru_txt += s;
	}

	return ru_txt;
}

void Operation(int n)
{
	string fru = "file_ru.txt", fru_en = "file_ru-en.txt";
	string fen = "file_en.txt", fen_ru = "file_en-ru.txt";

	string filein{}, fileout;

	switch (n)
	{
	case 1:
	{
		filein = fru;
		fileout = fru_en;

		cout << "\n TRANSLITERATION RU -> EN";
		cout << "\n File \"" << filein << "\"\n";
	}
		break;
	case 2:
	{
		filein = fen;
		fileout = fen_ru;

		cout << "\n TRANSLITERATION EN -> RU";
		cout << "\n File \"" << filein << "\"\n";
	}
		break;
	default:
		cout << "\n !NO OPERATION SELECTED. THE END!\n";
		exit (0);
	}

	if (TryCatch(filein))
	{
		fstream fin, fout;
		fin.open(filein, ios::in);
		fout.open(fileout, ios::out);
		
		SetConsoleCP(1251);

		if (confirmAct())
		{
			while (!fin.eof())
			{
				string str{};
				getline(fin, str);
				if (n == 1)
					fout << translitRU_EN(str) << endl;
				if (n == 2)
					fout << translitEN_RU(str) << endl;
			}
		}
		else
			exit(0);

		SetConsoleCP(1252);
		fout.close();
		fin.close();
	}
	else
	{
		exit(0);
	}

	cout << "\n TRANSLITERATION IS DONE";
	cout << "\n Check file \"" << fileout << "\"\n";
}

int main()
{
	int num = 0;

	cout
		<< "\n Menu transliteration"
		<< "\n\tPress 1: ru -> en"
		<< "\n\tPress 2: en -> ru"
		<< "\n\tPress 0: !EXIT!"
		<< "\n\n\tEnter -> ";

restart1:
	num = checkV();
	if (num > 2)
	{
		cout << "\n\t!ATTENTION. INCORRECT INPUT!";
		cout << "\n\tEnter -> ";
		goto restart1;
	}
	Operation(num);

	return 0;
}