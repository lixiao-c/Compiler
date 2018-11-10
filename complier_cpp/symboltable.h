#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct arrayattr {
	int area=0;
	int areanum=0;
	arrayattr* next = NULL;
};
struct symvalue{
	bool exist = false;
	int va1;
	char va2;
};
class node {
public:
	string idname;
	string attribute;
	int type=-1;//-1 nothing 0 int 1 char 2 float
	symvalue value;//目前不能实现

	int areacount = 0;
	bool deleteflag=false;

	int status;
	int count = 0;//reserved table;

	//for array
	int arraytype = -1;//0 int 1 char
	int arraynum = 0;
	arrayattr arrayattr;

	node()
	{
		status = -1;
	}
};
class sort {
public:
	vector<node> table;
	sort() {}//default create
	int insert(char* text,int area);//id
	//void insert(char* text, int i);//num
	void insert(char* id, char* text);//others

	void findprint(int i);//

	void findtext(char* text);//

	int search(char* text);
	int search(char* text,int area);

	void printall();
	void deleteele(char* text);//delete eg.variety
	void deleteele(int area);
}; 