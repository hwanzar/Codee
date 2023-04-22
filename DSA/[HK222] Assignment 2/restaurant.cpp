#include "main.h"
/*==== ADD-ON ====*/
#include "demoCode/demoAVL.cpp"
#include "demoCode/demo_huffmanCode.cpp"
#include "demoCode/demo_hashTable.cpp"

/*----------DEFINE DATA STRUCTURE-------------*/
unordered_map<string, table> restaurant;
queue<table> fifo;
vector<table> lrco;
HashTable area1;
AVL area2; // area2 AVL

/*=== REG Command ===*/
// helper function
string getCommand(string input)
{
	int pos = input.find(" ");
	string command = input.substr(0, pos);
	return command;
}

int BinToDec(string binary)
{
	long long decimal = 0;
	for (int i = 0; i < binary.length(); i++)
	{
		if (binary[i] == '1')
		{
			decimal += (int)pow(2, binary.length() - 1 - i);
		}
	}
	return decimal;
}
string getName(string input)
{
	string lastWord;
	size_t pos = input.find_last_of(' ');
	if (pos != string::npos)
	{
		lastWord = input.substr(pos + 1);
	}
	else
	{
		lastWord = input;
	}
	return lastWord;
}

// 3. Chọn bàn
int getID(int res)
{
	int ID = res % MAXSIZE + 1;
	return ID;
	// return ID;
}

int getOPT(int res)
{
	return res % 3;
}

int SelectArea(int res)
{
	if (res % 2 != 0)
	{
		if (!area1.isFull())
		{
			return 1;
			// insert hash table
		}
		else
			return (area2.size() < MAXSIZE / 2) ? 2 : 3;
	}

	if (res % 2 == 0)
	{
		if (area2.size() < MAXSIZE / 2)
		{
			return 2;
			// insert AVL
		}
		else
			return (!area1.isFull()) ? 1 : 3;
	}
	return 3; // the restaurant is full.
}

void regFull()
{
	// FIFO

	// LRCO

	// LFCO
	return;
}
bool checkName(unordered_map<string, table> restaurant, string name)
{
	for (auto pair : restaurant)
	{
		if (pair.second.name == name)
			return true;
	}
	return false;
}

void reg(string input)
{
	HuffmanCoding *huffman = new HuffmanCoding();
	string name = getName(input);
	string modifiedName = huffman->HuffmanTree(name);
	string newName = modifiedName.substr(modifiedName.length() - 15);
	cout << "== Debug HUFFMAN ==\n"
		 << newName << endl;

	int Result = BinToDec(newName);
	cout << Result << endl;

	// get full information:
	int ID = getID(Result);
	while (true)
	{
		if (ID > MAXSIZE)
			ID = 1;
		if (!area2.containsID(ID) && !area1.containsID(ID))
			break;
		else
			ID++;
	}

	int select_area = SelectArea(Result);
	if (select_area == 3)
		regFull();

	else if (!checkName(restaurant, name))
	{
		while (true)
		{
			if (ID > MAXSIZE)
				ID = 1;
			if (!area2.containsID(ID) && !area1.containsID(ID))
				break;
			else
				ID++;
		}
		table tb = table(ID, name, Result, 1);
		restaurant[name] = tb;
		fifo.push(tb);
		lrco.push_back(tb);
		if (select_area == 1)
		{
			area1.insert(tb.result, tb);
		}
		if (select_area == 2)
		{
			area2.addAVLTree(tb.result, tb);
		}
	}
	else
	{
		restaurant[name].dish++;
		table tmpTable;
		for (int i = 0; i < lrco.size(); i++)
		{
			if (lrco[i].name == name)
			{
				table tmpTable = lrco[i];
				lrco.erase(lrco.begin() + i);
			}
		}
		lrco.push_back(tmpTable);
	}

	// function: checkName in the restaurant. if has name, no FIFO, add dish to LRCO.
	// function:
	// Deque FIFO. checkName in list.
	// Deque LRCO. update the dish in list.
	return;
}
/*=== END REG Command ===*/

/*=== START CLE Command ===*/
// helper function

// main function
void cle(string inp)
{
	cout << "Command CLE written" << endl;
}

/*=== END CLE Command ===*/

/*=== START printHT Command ===*/
// helper function

// main function
void printHT(string inp)
{
	area1.display();
	return;
}

/*=== END printHT Command ===*/

/*=== START printAVL Command ===*/
// helper function

// main function
void printAVL(string inp)
{
	cout << area2.printBFT();
	return;
}

/*=== END printAVL Command ===*/

/*=== START printMH Command ===*/
// helper function

// main function
void printMH(string inp)
{
	cout << "Command Print Min Heap written\n"
		 << endl;
	return;
}

/*=== END printMH Command ===*/
void simulate(string filename)
{

	ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			string command = getCommand(line);
			if (command == "REG")
			{
				reg(line);
			}
			if (command == "CLE")
			{
				cle(line);
			}
			if (command == "PrintHT")
			{
				printHT(line);
			}
			if (command == "PrintAVL")
			{
				printAVL(line);
			}
			if (command == "PrintMH")
			{
				printMH(line);
			}
		}

		file.close();
	}
	else
		cout << "Not found FILE" << endl;
	return;
}