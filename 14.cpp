#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	char alphabet[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_" };
	char pasword[8] = { };
	bool upperC = false;
	bool lowerC = false;
	bool digit = false;
	do
	{
		for (size_t i = 0; i < sizeof(pasword); i++)
		{
			pasword[i] = alphabet[rand() % sizeof(alphabet)];
			if (isupper(pasword[i]))
			{
				upperC = true;
			}
			else if (islower(pasword[i]))
			{
				lowerC = true;
			}
			else if (isdigit(pasword[i]))
			{
				digit = true;
			}
		}
	} while (upperC != true && lowerC != true && digit != true);

	for (size_t i = 0; i < sizeof(pasword); i++)
	{
		cout << pasword[i];
	}

	return 0;
}