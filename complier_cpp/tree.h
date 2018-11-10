#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/****************tree**************/
#define MAXSIZE 4
#define NULL 0


enum Node_Kind{//�ڵ�����
	EXPR_KIND,
	STMT_KIND,
	DECL_KIND,
	NO_KIND
};
enum Stmt_Kind{//���ڵ�������
	IF_STMT=0,
	FOR_STMT,
	WHILE_STMT,
	IO_STMT,
	COMP_STMT
};
enum Expr_Kind{//���ʽ�ڵ�������
	TYPE_EXPR = 0,
	OP_EXPR,
	CONST_EXPR,
	ID_EXPR,
	ARR_EXPR
};
enum Decl_Kind{//�����ڵ�������
    VAR_DECL=0,
};
enum Expr_Type {
	Integer,
	Char,
	Float,
	Boolean,
	Void,
	Output,
	Input,
	Helpchar,
	Array,
	Notype
};
enum OP_Kind{
	OP_PLUS = 0,
	OP_MINUS,
	OP_MUL,
	OP_DIV,
	OP_MOD,//�������������
	OP_LS,OP_RS,OP_LOR, OP_LAND, OP_LNOT, OP_LXOR,// λ����
	OP_BPPLUS, OP_APPLUS, OP_BMMINUS, OP_AMMINUS,//++--
	OP_ASSIGN,
	GTR,GEQ,LSS,LEQ,NEQ,EQU,//�Ƚ������
    LOG_OR,LOG_AND,LOG_NOT, //�߼������
	NOTYPE
};

struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

//�ڵ�����   �ս����
struct NodeAttr 
{
	int  op;//���ʽ�������
	int  vali;//INT��ֵ
	float vali2; //float��ֵ
	int index;//���ű��е��±�
	char valc;  //�ַ�����
	//int  symtbl_seq;
	NodeAttr(void) { op = 23; }
	NodeAttr(int i)	{ op = i; }
	NodeAttr(char c) { valc = c; }
};

class treenode{
public:
	treenode* children[MAXSIZE];//���ӽڵ�
    treenode *sibling;//�ֵܽڵ�
	Node_Kind nodekind;//�ڵ�����
    int kind;//�ڵ�������
	NodeAttr attr;
	Expr_Type exprtype; //���ʽ����������
	int seq;//�ڼ����ڵ�
	int lineno;//line num

	//add for finalwork
	int temp_var;
	Label label;
public:
	treenode::treenode(){};
	treenode::treenode(int a)
	{
		nodekind == NO_KIND;
		exprtype = Notype;
		attr.op = NOTYPE;
	}
	void output();
	
};

class tree{
public:
	treenode* root;	
	
	static int node_seq;
	static int temp_var_seq;
	static int temp_var_num;//��ʱ����ջ�����ֵ
	static int temp_char_var_seq;//char�ͱ�������ʱ����
	static int label_seq;

	tree::tree(){ 
		root=NULL;
		//nodeseq=0;
	}
	tree::~tree(){delete root;}
	  //����һ�����
	treenode* NewRoot(int,Node_Kind,int,NodeAttr attr,Expr_Type,
		treenode*child1=NULL,treenode*child2=NULL,treenode*child3=NULL,treenode*child4=NULL);  

	//add for final work

	void type_check(treenode *t);
	void get_temp_var(treenode *t);
	string new_label();
	
	void recursive_get_label(treenode *t);
	void stmt_label(treenode* t);
	void expr_label(treenode* t);
	void decl_label(treenode* t);

	void gen_header(ofstream &out);
	void table_gendecl(ofstream &out, treenode* t);

	void stmt_code(ofstream &out, treenode *t);
	void expr_code(ofstream &out, treenode *t);
	void decl_assign_code(ofstream &out, treenode *t);
	void arr_code(ofstream &out, treenode* t);
	void recursive_gen_code(ofstream &out, treenode *t);
	void start_compiler(ofstream &out);
};

