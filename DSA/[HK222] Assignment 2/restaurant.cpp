#include "main.h"
/*==== ADD-ON ====*/
#include "demoCode/demoAVL.cpp"
#include "demoCode/demo_huffmanCode.cpp"
#include "demoCode/demo_hashTable.cpp"
#include "demoCode/demoHEAP.cpp"

/*----------DEFINE DATA STRUCTURE-------------*/
unordered_map<string, table> listName;
vector<table> fifo;
vector<table> lrco;
MinHeap lfco = MinHeap(MAXSIZE);
HashTable area1;
AVL area2; // area2 AVL
int RecOrder = 0;
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
	string binaryName = huffman->HuffmanTree(name);
	int binNameLen = binaryName.length();
	string newName = (binNameLen > 15) ? binaryName.substr(binNameLen - 15) : binaryName;

	// cout << "== Debug HUFFMAN ==\n"
	//  << newName << endl;

	int Result = BinToDec(newName);
	// cout << Result << endl;

	// get full information:
	int ID = getID(Result);
	// while (true)
	// {
	// 	if (ID > MAXSIZE)
	// 		ID = 1;
	// 	if (!area2.containsID(ID) && !area1.containsID(ID))
	// 		break;
	// 	else
	// 		ID++;
	// }

	int select_area = SelectArea(Result);

	if (!checkName(listName, name))
	{
		if (select_area != 3)
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
			table tb = table(ID, name, Result, 1, RecOrder, select_area);
			listName[name] = tb;
			fifo.push_back(tb);
			lrco.push_back(tb);
			lfco.insert(tb);
			RecOrder++;
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
			int opt = Result % 3;
			if (opt == 0)
			{
				// delete
				table prevTable = fifo[0];
				for (int i = 0; i < lrco.size(); i++)
				{
					if (lrco[i].name == prevTable.name)
					{
						lrco.erase(lrco.begin() + i);
						break;
					}
				}
				fifo.erase(fifo.begin());
				lfco.remove(lfco.findIndex(prevTable.name));
				listName.erase(prevTable.name);

				// create neww table, new name
				table newTable = table(prevTable.id, name, Result, 1, RecOrder, 0);

				// insert back new table
				fifo.push_back(newTable);
				lrco.push_back(newTable);
				lfco.insert(newTable);
				listName.insert({name, newTable});
				RecOrder++;
				// avl and hash
				if (area1.containsID(newTable.id))
				{
					area1.changeInfo(prevTable, newTable);
				}
				else if (area2.containsID(newTable.id))
				{
					area2.changeInfo(prevTable, newTable);
				}
			}
			else if (opt == 1)
			{
				table prevTable = lrco[0];
				for (int i = 0; i < fifo.size(); i++)
				{
					if (fifo[i].name == prevTable.name)
					{
						fifo.erase(fifo.begin() + i);
						break;
					}
				}
				lrco.erase(lrco.begin());
				lfco.remove(lfco.findIndex(prevTable.name));
				listName.erase(prevTable.name);

				table newTable = table(prevTable.id, name, Result, 1, RecOrder, prevTable.typeArea);

				fifo.push_back(newTable);
				lrco.push_back(newTable);
				lfco.insert(newTable);
				listName.insert({name, newTable});
				RecOrder++;

				if (area1.containsID(newTable.id))
				{
					area1.changeInfo(prevTable, newTable);
				}
				else if (area2.containsID(newTable.id))
				{
					area2.changeInfo(prevTable, newTable);
				}
			}
			else if (opt == 2)
			{
				table prevTable = lfco.heapArray[0];
				lfco.remove(lfco.findIndex(prevTable.name));

				for (int i = 0; i < fifo.size(); i++)
				{
					if (fifo[i].name == prevTable.name)
					{
						fifo.erase(fifo.begin() + i);
						break;
					}
				}
				for (int i = 0; i < lrco.size(); i++)
				{
					if (lrco[i].name == prevTable.name)
					{
						lrco.erase(lrco.begin() + i);
						break;
					}
				}

				listName.erase(prevTable.name);

				table newTable = table(prevTable.id, name, Result, 1, RecOrder, 0);

				fifo.push_back(newTable);
				lrco.push_back(newTable);
				lfco.insert(newTable);
				listName.insert({name, newTable});
				RecOrder++;
				if (area1.containsID(newTable.id))
				{
					area1.changeInfo(prevTable, newTable);
				}
				else if (area2.containsID(newTable.id))
				{
					area2.changeInfo(prevTable, newTable);
				}
			}
		}
	}
	else
	{
		// update LRCO
		listName[name].dish++;
		table tmpTable;
		for (int i = 0; i < lrco.size(); i++)
		{
			if (lrco[i].name == name)
			{
				tmpTable = lrco[i];
				lrco.erase(lrco.begin() + i);
				break;
			}
		}
		// cout << "HELLO: " << lfco.findIndex(name)<< endl;
		lfco.remove(lfco.findIndex(name));
		tmpTable.dish++;

		lrco.push_back(tmpTable);

		lfco.insert(tmpTable);

		if (area2.containsID(listName[name].id))
		{
			area2.AddDish(Result, name);
		}
		else if (area1.containsID(listName[name].id))
		{
			area1.AddDish(name);
		}
	}

	return;
}
/*=== END REG Command ===*/

/*=== START CLE Command ===*/
// helper function
// string getNum(string inp)
// {
// 	string tempInp = inp;
// 	int checkSpace = 0;
// 	int pos = -1;
// 	while (pos = inp.find(' ', pos + 1) != string::npos)
// 	{
// 		checkSpace++;
// 	}
// 	if (checkSpace > 1 || checkSpace == 0)
// 		return "Invalid input";

// 	return inp.substr(pos, inp.length() - pos);
// }
// int checkNum(string inp, bool &check)
// {
// 	// inp.find(" ");
// 	bool flag = false;
// 	for (char c : inp)
// 	{
// 		if (isdigit(c) == false)
// 		{
// 			if (flag == true)
// 			{
// 				check = false;
// 				return -1;
// 			}
// 			if (c == '-' || c == '+')
// 			{
// 				flag = true;
// 			}
// 			else
// 			{
// 				check = false;
// 				return -1;
// 			}
// 		}
// 	}
// 	return stoi(inp);
// }
int getNum(string inp)
{
	string tempInp = inp;
	int pos = tempInp.find_last_of(" ");
	if (pos != string::npos)
	{
		tempInp = tempInp.substr(pos + 1);
	}
	return stoi(tempInp);
}

// main function
void cle(string inp)
{
	// cout << "Command CLE written" << endl;
	// string num = getNum(inp);
	// bool check = true;
	// int NUM = checkNum(num, check);

	// if (!check)
	// 	return;
	int NUM = getNum(inp);
	if (NUM < 1)
	{
		queue<table> toBeDelete;
		for (int i = 0; i < fifo.size(); i++)
		{
			if (area1.containsID(fifo[i].id))
			{
				toBeDelete.push(fifo[i]);
				lfco.remove(lfco.findIndex(fifo[i].name));
				listName.erase(fifo[i].name);
				// area1.remove(fifo[i].id);
				for (int j = 0; j < lrco.size(); j++)
				{
					if (fifo[i].name == lrco[j].name)
					{
						lrco.erase(lrco.begin() + j);
						break;
					}
				}
				area1.remove(fifo[i].id);
			}
		}
		for (int i = fifo.size(); i >= 0; i--)
		{
			if (fifo[i].name == toBeDelete.front().name)
			{
				fifo.erase(fifo.begin() + i);
				toBeDelete.pop();
			}
		}
	}
	else if (NUM > MAXSIZE)
	{
		// xoa ban
		queue<table> toBeDelete;
		for (table x : fifo)
		{
			// cout << x.name << endl;
			if (area2.containsID(x.id))
			{

				// cout << "have to delete: " << x.result << endl;s
				// cout << area2.containsID(27) << endl;

				int lrcoIndex = 0;
				for (table tmp : lrco)
				{
					if (x.name == tmp.name)
					{
						lrco.erase(lrco.begin() + lrcoIndex);
						break;
					}
					lrcoIndex++;
				}
				lfco.remove(lfco.findIndex(x.name));
				listName.erase(x.name);
				area2.deleteAVLTree(x.result, x.name);
				toBeDelete.push(x);
			}
		}
		for (int i = fifo.size(); i >= 0; i--)
		{
			if (fifo[i].name == toBeDelete.front().name)
			{
				fifo.erase(fifo.begin() + i);
				toBeDelete.pop();
			}
		}
	}
	else
	{
		// xoa ban co ID = NUM
		table toBeDelete;
		for (auto pair : listName)
		{
			if (pair.second.id == NUM)
			{
				toBeDelete = pair.second;
			}
		}
		listName.erase(toBeDelete.name);
		for (int i = 0; i < fifo.size(); i++)
		{
			if (toBeDelete.name == fifo[i].name)
			{
				fifo.erase(fifo.begin() + i);
				break;
			}
		}
		for (int i = 0; i < lrco.size(); i++)
		{
			if (toBeDelete.name == lrco[i].name)
			{
				lrco.erase(lrco.begin() + i);
				break;
			}
		}
		lfco.remove(lfco.findIndex(toBeDelete.name));
		if (area1.containsID(NUM))
		{
			area1.remove(NUM);
		}
		if (area2.containsID(NUM))
		{
			area2.deleteAVLTree(toBeDelete.result, toBeDelete.name);
		}
	}
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
	if (area2.size() <= 0)
		return;
	area2.printBFT();
	return;
}

/*=== END printAVL Command ===*/

/*=== START printMH Command ===*/
// helper function

// main function
void printMH(string inp)
{
	lfco.printPreOrder();
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