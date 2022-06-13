#pragma once
#pragma warning(disable: 4018)

#include <string>

#define OFFSET 4
#define CHARACTERS 26
#define NUMBERS 10

namespace Cipher
{
	std::string encode(std::string str)
	{
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = (str[i] - 'a' + OFFSET) % CHARACTERS + 'a';
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = (str[i] - 'A' + OFFSET) % CHARACTERS + 'A';
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				str[i] = (str[i] - '0' + OFFSET) % NUMBERS + '0';
			}
			else
			{
				str[i] = str[i];
			}
		}
		return str;
	}

	std::string decode(std::string encodedStr)
	{
		for (int i = 0; i < encodedStr.size(); i++)
		{

			if (encodedStr[i] >= 'a' && encodedStr[i] <= 'z')
			{
				encodedStr[i] = (encodedStr[i] - 'a' - OFFSET + CHARACTERS) % CHARACTERS + 'a';
			}
			else if (encodedStr[i] >= 'A' && encodedStr[i] <= 'Z')
			{
				encodedStr[i] = (encodedStr[i] - 'A' - OFFSET + CHARACTERS) % CHARACTERS + 'A';
			}
			else if (encodedStr[i] >= '0' && encodedStr[i] <= '9')
			{
				encodedStr[i] = (encodedStr[i] - '0' - OFFSET + NUMBERS) % NUMBERS + '0';
			}
			else
			{
				encodedStr[i] = encodedStr[i];
			}
		}
		return encodedStr;
	}
}