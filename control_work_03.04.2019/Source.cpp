#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 256;

typedef char*(*code)(char*);

char* inputString();
void task(char*, int, code);
void replaceString(char*, char*, char*);
int substringPosition(char*, char*, int);
char* Encode(char*);

int main()
{
	char* string = inputString();

	int length;
	cout << "Word length count ";
	cin >> length;

	task(string, length, Encode);

	cout << string << endl;

	system("pause");
	return 0;
}

char* inputString()
{
	char* string = new char[N];

	cout << "Enter the string (<= 256 symbols): ";
	cin.getline(string, N);

	return string;
}

void task(char* string, int count, code code)
{
	char* copy = new char[N];
	strcpy(copy, string);
	char* newString = strtok(copy, " ,.");

	while (newString)
	{
		if (strlen(newString) == count)
		{
			replaceString(string, newString, code(newString));
		}

		newString = strtok(NULL, " ,.-");
	}

	delete[] newString;
	delete[] copy;
}

void replaceString(char* string, char* substing, char* replace)
{
	char* newString = new char[N];

	int newLength = strlen(replace),
		oldLength = strlen(substing),
		sLength = strlen(string),
		start = 0,
		oldStart = 0,
		count = 0,
		difference = newLength - oldLength;

	int index = substringPosition(string, substing, start);

	for (int i = 0; i < index; i++)
	{
		newString[i] = string[i];
	}

	while (index != -1)
	{
		for (int j = index + count * (difference), i = 0; j < index + newLength + count * (difference); j++, i++)
		{
			newString[j] = replace[i];
		}
		start = index + newLength;

		int newIndex = substringPosition(string, substing, start);

		while (newIndex != -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < newIndex; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}

		while (newIndex == -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < sLength; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}

		index = substringPosition(string, substing, start);
		count++;
	}

	newString[strlen(string) + difference] = '\0';
	strcpy(string, newString);
}

int substringPosition(char* string, char* substring, int start)
{
	int n = strlen(string),
		m = strlen(substring);

	if (m > n)
	{
		return -1;
	}

	int count = 0,
		index = -1;

	for (int i = start; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (substring[j] == string[i + count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
			}
			else
			{
				index = -1;
				count = 0;
				break;
			}
		}
	}
	return index;
}

char* Encode(char* word)
{
	char* codedWord = new char[N];
	const char* symbolsUp = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	const char* symbolsDown = "zyxwvutsrqponmlkjihgfedcba";

	int length = 0;
	bool isEncode = false;

	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = 0; j < strlen(symbolsUp), isEncode == false; j++)
		{
			if (word[i] == symbolsUp[j] || word[i] == symbolsDown[j])
			{
				codedWord[length] = '(';
				length++;

				if (j > 9)
				{
					codedWord[length] = 48 + (j + 1) / 10;
					length++;
				}

				codedWord[length] = 48 + (j + 1) % 10;
				length++;

				codedWord[length] = ')';
				length++;
				isEncode = true;
			}
		}
		isEncode = false;
	}

	codedWord[length] = '\0';

	return codedWord;
}