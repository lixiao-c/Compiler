#include"symboltable.h"
using namespace std;
sort table;
void printnode(node temp)
{
	cout << temp.attribute << "\t" << temp.idname;
	if (temp.type != -1)
	{
		cout << "\t";
		switch (temp.type)
		{
		case 0:
		{
			cout << "int";
			if (temp.value.exist)
				cout << "\t" << temp.value.va1;
		    break; 
		}
		case 1:
		{
			cout << "char";
			if (temp.value.exist)
				cout << "\t" << temp.value.va2;
			break;
		}
		case 2:
			cout << "float";
			break;
		case 3:
			cout << "array";
			break;
		default:
			cout << "other";
		}
	}
	else
		cout << "\t";
	//if (temp.deleteflag)
		cout << "\t" << temp.areacount;
	/*else
		cout << "\t";*/
	if (temp.status != -1)
		cout << "\t\t" << temp.status;
	cout << endl;
}
int  sort::insert(char* text,int area)//id
{
	if (search(text) < 0)
	{
		node temp;
		temp.idname = "ID";
		temp.attribute = (string)text;
		temp.status = table.size();
		temp.areacount = area;
		table.push_back(temp);
		return table.size()-1;
	}
	else
		return search(text);
}
void sort::insert(char* id, char* text)//others
{
	node temp;
	temp.idname = (string)id;
	temp.attribute = (string)text;
	temp.status = -1;
	table.push_back(temp);
	//printnode(temp);
}
void sort::findprint(int i)//
{
	printnode(table[i]);
}
void sort::findtext(char* text)//
{
	int x = search(text);
	if (x<0)
		cout << "don't exist" << endl;
	else
		printnode(table[x]);
}
int sort::search(char* text)
{
	string str = (string)text;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].attribute == str)
			return i;
	}
	return -1;
}
int sort::search(char* text,int area)
{
	string str = (string)text;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].attribute == str&&table[i].areacount<=area&&table[i].type<3&& table[i].type>=0)
			return i;
	}
	return -1;
}
void sort::printall()
{
	for (int i = 0; i < table.size(); i++)
		printnode(table[i]);
}
void sort::deleteele(char* text)//delete eg.variety
{
	int x = search(text);
	if (x<0)
	{
		cout << "error! don't exist" << endl;
		return;
	}
	vector<node>::iterator iter = table.begin();
	table.erase(table.begin() + x);
	//cout << table.size();
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].status > x)
			table[i].status--;
	}
	cout << "have deleted" << endl;
}
void sort::deleteele(int area)//delete area
{
	/*if (area != 0)
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i].areacount == area)
			{
				vector<node>::iterator iter = table.begin();
				table.erase(table.begin() + i);
				//cout << table.size();
				for (int j = 0; j < table.size(); j++)
				{
					if (table[j].status > i)
						table[j].status--;
				}
			}
		}
	}*/
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].areacount == area)
		{
			table[i].deleteflag = true;
		}
	}
	//cout << "have deleted" << endl;
}