#pragma once

const int N = 256;

using namespace std;

int getLength(char*);
int compare(char*, char*, bool caseSensitive = false);
bool IsEqual(char*, char*, bool = true);
char ToUpper(char);
int SubstringPosition(char*, char*, int);
void displayArray(char*);

void displayArray(char* string)
{
	for (int i = 0; i < getLength(string); i++)
	{
		cout << string[i];
	}
	cout << endl;
}

int getLength(char* source)
{
	int lenght = 0;

	while (source[lenght]) //source[lenght] != '\0' == source[lenght] (\ - escape sequence)
	{
		lenght++;
	}

	return lenght;
}

int compare(char* lhs, char* rhs, bool caseSensitive)
{
	int i = 0;
	int lhsLenght = getLength(lhs);
	int rhsLenght = getLength(rhs);
	int minLenght = (lhsLenght >= rhsLenght) ? lhsLenght : rhsLenght;

	while (i < minLenght)
	{
		char chl = !caseSensitive ? lhs[i] : ToUpper(lhs[i]);
		char chr = !caseSensitive ? rhs[i] : ToUpper(rhs[i]);

		if (chl != chr)
		{
			return (chl > chr) ? 1 : -1;
		}
		i++;
	}

	return 0;
}

bool IsEqual(char* lhs, char* rhs, bool caseSensitive) //left handside, right handside
{
	int n = getLength(lhs),
		m = getLength(rhs);
	int i = 0;

	if (n != m)
	{
		return false;
	}

	while (lhs[i])
	{
		char chl = caseSensitive ? lhs[i] : ToUpper(lhs[i]);
		char chr = caseSensitive ? rhs[i] : ToUpper(rhs[i]);

		if (chl != chr)
		{
			return false;
		}

		i++;
	}

	return true;
}

char ToUpper(char symbol)
{
	int const difference = 'a' - 'A';

	if ('a' <= symbol && 'z' >= symbol)
	{
		symbol -= difference;
	}

	return symbol;
}

int SubstringPosition(char* string, char* substring, int start)
{
	int n = getLength(string),
		m = getLength(substring);
	
	if (m > n)
	{
		return -1;
	}
	
	int count = 0, index = -1;
	
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
				else
				{
					continue;
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