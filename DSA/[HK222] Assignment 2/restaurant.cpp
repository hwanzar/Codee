#include "main.h"
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

string getCommand(string input)
{
	int pos = input.find(" ");
	string command = input.substr(0, pos);
	return command;
}

void reg(string input)
{
	cout << getCommand(input) << endl;
	return;
}

void simulate(string filename)
{
	_io;
	outtext; // this line for output in another file
	ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			if (getCommand(line) == "REG")
			{
				reg(line);
			}
		}

		file.close();
	}
	else
		cout << "Not found FILE" << endl;

	return;
}