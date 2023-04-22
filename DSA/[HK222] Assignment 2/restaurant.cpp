#include "main.h"
/*==== ADD-ON ====*/
#include "demoCode/demoAVL.cpp"
#include "demoCode/demo_huffmanCode.cpp"
#include "demoCode/demo_hashTable.cpp"

/*----------DEFINE DATA STRUCTURE-------------*/

AVL area2; // area2 AVL
HashTable area1;
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
	while (true)
	{
		if (ID > MAXSIZE)
			return 1;
		if (area2.containsID(ID))
			ID++;
		return ID;
	}
	return ID;
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
	return;
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

	int select_area = SelectArea(Result);

	table *tb = new table(ID, name, Result, 1);
	if (select_area == 3)
		return regFull();
	if (select_area == 1)
	{
		area1.insert(tb->result, tb);
	}
	if (select_area == 2)
	{
		area2.addAVLTree(tb->result, tb);
	}

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
	cout << "Command Print AVL tree written" << endl;
	cout << area2.printBFT();
	return;
}

/*=== END printAVL Command ===*/
//
//
//
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