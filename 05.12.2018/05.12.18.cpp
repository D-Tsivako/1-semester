#include <iostream>
#include "strings.h"

using namespace std;

void getWords(char*);
void stringDelete(char*, char*);
void replaceString(char*, char*, char*, char*);

int main()
{
	char string[N] = "Hello hello hello world !";
	char substring[N] = "lo";
	char replacedSubstring[N] = "p";
	char newString[N] = "";

	cout << string << endl;

	stringDelete(string, substring);
	displayArray(string);

	replaceString(string, substring, replacedSubstring, newString);
	displayArray(newString);

	system("pause");

	return 0;
}

void getWords(char* string)
{
	int length = getLength(string);
	int k = 0;

	for (int i = 0; i < length; i++)
	{
		if (string[i] == ' ' || i == length - 1)
		{
			int j;
			for (j = k; j <= i; j++)
			{
				cout << string[j];
			}

			k = j;
			cout << endl;
		}

	}
}

void stringDelete(char* string, char* substring)
{
	int stringLength = getLength(string),
		substringLength = getLength(substring);
	int index = SubstringPosition(string, substring, 0);

	while (index != -1)
	{
		for (int i = index, j = index + substringLength; i < stringLength; i++, j++)
		{
			string[i] = string[j];
		}

		index = SubstringPosition(string, substring, 0);
	}
}

void replaceString(char* string, char* substring, char* replacedSubstring, char* newString)
{

	int replacedLength = getLength(replacedSubstring), 
		substringLength = getLength(substring),
		stringLength = getLength(string),
		start = 0,
		count = 0, 
		difference = replacedLength - substringLength;
	int index = SubstringPosition(string, substring, start);
	
	for (int i = 0; i < index; i++)
	{
		newString[i] = string[i];
	}
	
	while (index != -1)
	{
		for (int j = index + count * (difference), i = 0; j < index + replacedLength + count * (difference); j++, i++)
		{
			newString[j] = replacedSubstring[i];
		}
	
		start = index + replacedLength;
		
		int newIndex = SubstringPosition(string, substring, start);
		
		while (newIndex != -1)
		{
			for (int i = index + replacedLength + count * (difference), j = index + substringLength; j < newIndex; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}
		
		while (newIndex == -1)
		{
			for (int i = index + replacedLength + count * (difference), j = index + substringLength; j < stringLength; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}

		index = SubstringPosition(string, substring, start);
		count++;
	}
}