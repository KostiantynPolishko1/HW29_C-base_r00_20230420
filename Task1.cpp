#include <iostream>
#include <string>
#include<fstream>

using namespace std;

//Task1
//A text file is given. Necessary create new file and remove from it all unacceptable words. 
//The list unacceptable words can be found in another file.

int main()
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
	cout << str << endl;

	return 0;
}