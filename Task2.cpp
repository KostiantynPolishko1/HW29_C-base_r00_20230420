#include <iostream>
#include <string>
#include<fstream>
#include<stdio.h>
#include<Windows.h>

using namespace std;

//Task2
//Write a transliteration program from Russian into English
//and vice versa.The data for transliteration is taken from 
//a file and written to another file. The translation direction 
//is determined by the user menu.

void translitRU_EN()
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

	const char* str_ru{};
	str_ru = "Ïîëèøêî, âàøå: èìÿ è e-mail, URL àäğåñ?";

	cout << str_ru << endl;

	while (*str_ru)
	{
		int pos = 0;
		string s = {};
		if (ru.find(*str_ru) != -1)
		{
			pos = ru.find(*str_ru);
			s = en[pos];
		}
		else
			if (ru2.find(*str_ru) != -1)
			{
				int i = 0;
				pos = ru2.find(*str_ru);
				i = pos * 2;
				s += en2[i];
				i++;
				s += en2[i];
			}
			else
				if (ru3.find(*str_ru) != -1)
				{
					int j = 0, count = 0;
					pos = ru3.find(*str_ru);
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
					s = *str_ru;
				}
		str_ru++;
		en_txt += s;
	}

	cout << en_txt << endl;
}

void translitEN_RU()
{
	setlocale(LC_ALL, "ru");

	string
		en = "abcdefghijklmnoprstuvwxyz",
		en2 = "qQ";

	string
		ru = "àáöäåôãõèéêëìíîïğñòóââõûç",
		ru2 = "êüşÊüş";

	string str_en = "The quick and Quite tool, translates the letters of the Russian language.";
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

	cout << str_en << endl;
	cout << ru_txt << endl;
}

int main()
{
	translitRU_EN();
	translitRU_EN();

	return 0;
}