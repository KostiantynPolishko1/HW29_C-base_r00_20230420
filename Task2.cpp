#include <iostream>
#include <string>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<Windows.h>

using namespace std;

//Task2
//Write a transliteration program from Russian into English
//and vice versa.The data for transliteration is taken from 
//a file and written to another file. The translation direction 
//is determined by the user menu.

string translitRU_EN(string &str_ru)
{
	setlocale(LC_ALL, "ru");

	string
		ru = "àáâãäåçèéêëìíîïğñòóôûıÀÁÂÃÄÅÇÈÉÊËÌÍÎÏĞÑÒÓÔÛİ",
		ru2 = "æõö÷øşÿÆÕÖ×ØŞß",
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
	
	//cout << str_ru << endl;
	//cout << en_txt << endl;
	return en_txt;
}

string translitEN_RU(string &str_en)
{
	//setlocale(LC_ALL, "ru");

	string
		en = "abcdefghijklmnoprstuvwxyz",
		en2 = "qQ";

	string
		ru = "àáöäåôãõèéêëìíîïğñòóââõûç",
		ru2 = "êüşÊüş";

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

	fstream fin, fout;
	fin.open(filein, ios::in);

	if (!fin.is_open())
	{
		cout << "\n\tCannot open the file\n";
		exit;
	}
	else
	{
		fout.open(fileout, ios::out);
		SetConsoleCP(1251);
		while (!fin.eof())
		{
			string str{};
			getline(fin, str);
			if (n == 1)
				fout << translitRU_EN(str) << endl;
			if (n == 2)
				fout << translitEN_RU(str) << endl;
		}
		SetConsoleCP(1252);
		fout.close();
	}
	fin.close();

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
		<< "\n\n\tEnter -> ";
	cin >> num;

	Operation(num);

	return 0;
}