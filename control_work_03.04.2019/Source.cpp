//дана строка нужно в этом тексте закодировать все слова заданной длины по правилу буква соотв цифре в перевернутом англ алфавите знаки препинани€ не кодируем
//если вы сможете изменить правила шифровани€ будет +
#define _CRT_SECURE_NO_WARNINGS;
#include<iostream>

const int N = 256;

using namespace std;

typedef char*(cod)(char*, int);

int enterNumber();
char* encodeWords(char*, int);
char* changeWord(char*, int, int, cod);

int main()
{
	
	char string[N] = "I said, СIt  is serious doctor/0";
	int length = strlen(string) + 1;
	cout << string;

	cout << "Enter lenght of word" << endl;
	int number = enterNumber();

	char* changedString = changeWord(string, length, number, encodeWords(string, length));
	cout << changedString << endl;

	system("pause");
	return 0;
}

int enterNumber()
{
	int n;
	while (true)
	{
		cin >> n;

		if (n > 0)
		{
			return n;
		}
	}
}

char* changeWord(char* source, int lenstring, int lengthWords, cod cod)
{
	const char* symbols = "ZYXVWUTSRPOMNLKJIHGFEDCBAzywvwutsrqpomnlkjihgfedcba";
	char* pword = strpbrk(source, symbols);

	while (pword)
	{
		while (pword)
		{
			int length = strspn(pword, symbols);

			if (lengthWords == length)
			{
				char* cordWord = cod(pword, length);
				char* end = new char[lenstring];
				strcpy(end, pword + length);
				strcpy(pword, cordWord);
				strcpy(pword + strlen(cordWord), end);

				pword += lengthWords;
				pword = strpbrk(pword, symbols);
			}
			else
			{
				length = strspn(pword, symbols);
				pword += length;
				pword = strpbrk(pword, symbols);
			}
		}

		return pword;
	}
}

char* encodeWords(char* word, int len)
{
	const char* symbols = "zyxvwutsrqpomnlkjihgfedcba";
	char* result = new char[len];
	int i = 0;

	while (word[i])
	{
		for (int j = 0; j < len; j++)
		{
			if (word[i] == symbols[j] || word[i] == symbols[j] + 32)
			{
				result[i] = (char)j;
			}
		}

		i++;
	}

	return result;
}