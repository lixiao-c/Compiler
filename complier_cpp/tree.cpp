#include"tree.h"
#include"symboltable.h"
using namespace std;
extern sort table;
tree parse_tree;
int tree::node_seq = 0;
int tree::temp_var_seq = 0;
int tree::temp_var_num = 0;
int tree::label_seq = 0;

//输出一个节点的信息
void treenode::output(){
	cout.setf(ios_base::left);
	cout<<seq<<":\t";
	cout << "line" << lineno << "\t";
	switch(nodekind)
	{
	case STMT_KIND:{//语句节点
		string name[] = { "if", "for", "while","io", "compound" };
		cout.width(30);
		cout << name[kind] + " statement";
		cout.width(10);
		cout<<" ";
	    break;}
	case EXPR_KIND:{//表达式节点
		string name[] = {"Type Specifier","Expr","Const Declaration","ID Declaration","Array use"};
		string type[] = {"integer","char","float","boolean","void","output","input"};
		string opname[] = {"+","-","*","/","%","<<",">>","|","&","~","^","++","++","--","--","=",">",">=","<","<=","!=","==","||","&&","!",""};
		cout.width(30);
		cout << name[kind];
		switch(kind)
		{
		case TYPE_EXPR:{//数据类型
			cout.width(10);
			cout << type[exprtype];
			break;}
		case OP_EXPR:{//运算符
			cout.width(10);
			cout<<"op:"+opname[attr.op];
			break;}
		case CONST_EXPR:{//常数表达式
			if(exprtype == Integer){
				cout.width(7);
				cout<<"value:";
				cout.width(3);
				cout<<attr.vali;
			    break;}
			if(exprtype == Char){
				cout.width(7);
				cout<<"value:";
				cout.width(3);
				cout<<attr.valc;
			    break;}
			if (exprtype == Float) {
				cout.width(7);
				cout << "value:";
				cout.width(3);
				cout << attr.vali2;
				break;
			}
			if(exprtype==Helpchar){
				cout.width(7);
				cout << "value:";
				cout.width(3);
				cout << attr.valc;
				break;
			}
						}
		case ID_EXPR:{//id表达式
			cout.width(7);
			cout << "symbol:";
			cout.width(3);
			cout << table.table[attr.index].attribute;//symbol table 
			break;}
		case ARR_EXPR: {//id表达式
			cout.width(7);
			cout << "symbol:";
			cout.width(3);
			cout << table.table[attr.index].attribute;
			break; }
		}
		break;}
	case DECL_KIND:{//声明节点
		cout.width(40);
		cout<<"Var Declaration";
		cout.width(10);
		//cout<<"    ";
		break;}
	}
	//cout << "\t";
	cout << "Children: ";
	//输出孩子节点的行号
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (children[i]==NULL)
			break;
		else if (children[i]->nodekind != NO_KIND)
		{	
		cout << children[i]->seq << " ";
		for (treenode* sp = children[i]->sibling; sp; sp = sp->sibling)
			cout << sp->seq << " ";
		}
	}
	cout << endl;
}

treenode* tree::NewRoot(int lineno,Node_Kind nk,int kind,NodeAttr attr,Expr_Type et,treenode*c1,treenode*c2,treenode*c3,treenode*c4){
	treenode* m_root=new treenode;
	m_root->lineno = lineno;
	m_root->nodekind=nk;
	m_root->kind=kind;
	m_root->attr=attr;
	m_root->exprtype=et;
	m_root->children[0]=c1;
	m_root->children[1]=c2;
	m_root->children[2]=c3;
	m_root->children[3]=c4;
	m_root->sibling=NULL;
	//m_root->seq=nodeseq++;
	m_root->seq = tree::node_seq++;

	m_root->label.begin_label = "";
	m_root->label.next_label = "";
	m_root->label.true_label = "";
	m_root->label.false_label = "";
	root = m_root;
	type_check(m_root);
	get_temp_var(m_root);
	m_root->output();
	return m_root;
}

void tree::type_check(treenode *t)
{
	if ((t->exprtype != Notype)&&(t->exprtype!=Array))
	{
		return;
	}
	if (t->nodekind == STMT_KIND)
	{
		if (t->kind == IF_STMT || t->kind == WHILE_STMT)
			if (t->children[0]->exprtype != Boolean)
			{
				cerr << "Bad boolean type at line: " << t->lineno << endl;
				//exit(1);
			}
			else
				return;
		if (t->kind == FOR_STMT)//因为未实现break，所以必须有判断条件boolean，且不允许缺省
			if (t->children[1]->exprtype != Boolean)
			{
				cerr << "Bad boolean type at line: " << t->lineno << endl;
				//exit(1);
			}
			else
				return;
	}
	if (t->nodekind != EXPR_KIND)
		return;
	if (t->kind == ID_EXPR)
	{
		if (table.table[t->attr.index].type == 0)
			t->exprtype = Integer;
		else if (table.table[t->attr.index].type == 1)
			t->exprtype = Char;
		return;
	}
	if (t->kind == ARR_EXPR)
	{
		treenode* p = t->children[0];
		while (p)
		{
			if(p->exprtype!=Integer)
				cerr << "Bad boolean type at line: " << t->lineno << endl;
			p = p->sibling;
		}
			return;
	}
	if (t->kind != OP_EXPR)
		return;
	treenode *arg1 = t->children[0];
	treenode *arg2 = t->children[1];
	if (t->attr.op == LOG_NOT)
	{
		if (arg1->exprtype != Boolean)
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			//exit(1);
		}
		t->exprtype = Boolean;
	}
	else if (t->attr.op >= LOG_OR && t->attr.op <= LOG_AND)
	{
		if ((arg1->exprtype != Boolean) || (arg2->exprtype != Boolean))
		{
			cerr << "Bad type at line: " << t->lineno << endl;
			//exit(1);
		}
		t->exprtype = Boolean;
	}
	else if (t->attr.op >= GTR && t->attr.op <= EQU)
	{

		if (((arg1->exprtype != Integer)&&(arg1->exprtype!=Array)) || ((arg2->exprtype != Integer)&&(arg2->exprtype!=Array)))
		{
			cerr << "Bad type at line: " << t->lineno << endl;
		}
		if (arg1->exprtype == Array&&table.table[arg1->attr.index].arraytype != 0)
			cerr << "Bad type at line: " << t->lineno << endl;
		if (arg2->exprtype == Array&&table.table[arg2->attr.index].arraytype != 0)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype = Boolean;
	}
	else if (t->attr.op >=OP_PLUS && t->attr.op <= OP_MOD)//这里只针对整形和数组
	{
		if (((arg1->exprtype != Integer) && (arg1->exprtype != Array)) || ((arg2->exprtype != Integer) && (arg2->exprtype != Array)))
		{
			cerr << "Bad type at line: " << t->lineno << endl;
		}
		if (arg1->exprtype == Array&&table.table[arg1->attr.index].arraytype!=0)
			cerr << "Bad type at line: " << t->lineno << endl;
		if (arg2->exprtype == Array&&table.table[arg2->attr.index].arraytype != 0)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype == Integer;
	}
	else if(t->attr.op>=OP_BPPLUS&&t->attr.op<=OP_AMMINUS)
	{
		if ((arg1->exprtype != Integer) && (arg1->exprtype != Array))
		{
			cerr << "Bad type at line: " << t->lineno << endl;
		}
		if (arg1->exprtype == Array&&table.table[arg1->attr.index].arraytype != 0)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype == Integer;
	}
	else if (t->attr.op >= OP_LOR&&t->attr.op <= OP_LXOR)
	{//暂时只允许两个相同变量，翻译时只能处理整形
		if (arg1->exprtype != arg2->exprtype)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype = arg1->exprtype;
	}
	else if (t->exprtype >= OP_LS&&t->exprtype <= OP_RS)
	{
		if(arg2->exprtype!=Integer)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype = arg1->exprtype;
	}
	else if (t->exprtype == OP_ASSIGN)
	{
		if(arg1->exprtype!=arg2->exprtype)
			cerr << "Bad type at line: " << t->lineno << endl;
		t->exprtype = arg1->exprtype;
	}
	return;
}

void tree::get_temp_var(treenode* t)
{
	bool flag = false;
	if (t->nodekind != EXPR_KIND)
		return;
	if (t->kind == ARR_EXPR)
	{
		t->temp_var = tree::temp_var_seq;
		tree::temp_var_seq++;
		tree::temp_var_num++;
		return;
	}
	if (t->attr.op < OP_PLUS || t->attr.op > OP_AMMINUS)
		return;
	treenode *arg1 = t->children[0];
	treenode *arg2 = t->children[1];
	if (t->attr.op >= OP_BPPLUS&&t->attr.op <= OP_AMMINUS)
	{
		t->temp_var = tree::temp_var_seq;
		tree::temp_var_seq++;
		tree::temp_var_num++;
		return;
	}
	if (arg1 && (arg1->kind == OP_EXPR))
	{
		tree::temp_var_seq--;
		flag = true;
	}
	if (arg2 && (arg2->kind == OP_EXPR))
	{
		tree::temp_var_seq--;
		flag = true;
	}
	t->temp_var = tree::temp_var_seq;
	tree::temp_var_seq++;
	if(!flag)
		tree::temp_var_num++;
}
string tree::new_label(void)
{
	char tmp[20];
	sprintf(tmp, "L%d", tree::label_seq);
	tree::label_seq++;
	return string(tmp);
}

void tree::recursive_get_label(treenode *t)
{
	if (t->nodekind == STMT_KIND)
		stmt_label(t);
	else if (t->nodekind == EXPR_KIND)
		expr_label(t);
	else if (t->nodekind == DECL_KIND)
		decl_label(t);
}
void tree::decl_label(treenode* t)
{
	if ((!t->children[2])&&(t->sibling))
	{
		t->sibling->label.begin_label = t->label.begin_label;
		t->label.begin_label = "";
	}
}
void tree::stmt_label(treenode *t)
{
	switch (t->kind)
	{
	case COMP_STMT:
	{
		treenode *last = NULL;
		treenode *p = t->children[0];
		for (p = t->children[0]; p->nodekind == DECL_KIND; p = p->sibling);

		if(p->label.begin_label=="")
			p->label.begin_label = t->label.begin_label;

		for (; p; p = p->sibling)
		{
			last = p;

			//editor in 12.27 为了嵌套
			if (!p->sibling)
				p->label.next_label = t->label.next_label;

			recursive_get_label(p);
		}

		t->label.next_label = last->label.next_label;

		/*treenode* temp = t->sibling;
		while (temp)
		{
			if (temp->nodekind != DECL_KIND)
			{
				temp->label.begin_label = t->label.next_label;
				break;
			}
			temp = temp->sibling;
		}*/
		if (t->sibling)
			t->sibling->label.begin_label = t->label.next_label;
	}
	break;

	case IF_STMT:
	{
		treenode *e = t->children[0];
		treenode *s1 = t->children[1];
		treenode *s2 = t->children[2];

		e->label.true_label = new_label();

		if (t->label.next_label == "")
			t->label.next_label = new_label();
		s1->label.next_label = t->label.next_label;
		if (t->sibling)
			t->sibling->label.begin_label = t->label.next_label;

		if (s2)
		{
			e->label.false_label = new_label();
			s2->label.next_label = t->label.next_label;
		}
		else
		{
			e->label.false_label = t->label.next_label;
		}
		recursive_get_label(e);
		recursive_get_label(s1);
		if (s2)
			recursive_get_label(s2);
	}
	break;
	case WHILE_STMT:
	{
		treenode *v1 = t->children[0];
		treenode *v2 = t->children[1];
		if(t->label.begin_label==""|| t->label.begin_label=="_start")
			t->label.begin_label = new_label();
		v1->label.true_label = new_label();
		if (t->label.next_label == "")
			t->label.next_label = new_label();
		v2->label.next_label = t->label.next_label;
		if (t->sibling)
			t->sibling->label.begin_label = t->label.next_label;
		v1->label.false_label = t->label.next_label;
		recursive_get_label(v1);
		recursive_get_label(v2);
	}
	break;
	case FOR_STMT:
	{
		treenode *v1 = t->children[0];
		treenode *v2 = t->children[1];
		treenode *v3 = t->children[2];
		treenode *v4 = t->children[3];
		if((t->label.begin_label=="")||(t->label.begin_label=="_start"))//嵌套
			t->label.begin_label = new_label();
		if (t->label.next_label == "")
		{
			t->label.next_label = new_label();
		}

		if(v2->label.false_label=="")
			v2->label.false_label = t->label.next_label;

		/*treenode* temp = t->sibling;
		while (temp)
		{
			if (temp->nodekind != DECL_KIND)
			{
				temp->label.begin_label = t->label.next_label;
				break;
			}
			temp = temp->sibling;
		}*/
		if (t->sibling)
			t->sibling->label.begin_label = t->label.next_label;

		v1->label.next_label = new_label();
		//v2->label.true_label=v3->label.begin_label = v1->label.next_label;
		v2->label.begin_label = v1->label.next_label;

		if(v3->label.begin_label=="")
			v3->label.begin_label = new_label();
       
		v4->label.begin_label = new_label();
		v2->label.true_label = v4->label.begin_label;
		v4->label.next_label = v3->label.begin_label;

		recursive_get_label(v1);
		recursive_get_label(v2);
		recursive_get_label(v3);
		recursive_get_label(v4);
	}
	break;
}
#ifdef PARSE_DEBUG
	cout << "node " << t->seq << ":" << t->label.begin_label << ", " << t->label.next_label << endl;
#endif
}
void tree::expr_label(treenode *t)
{
	if (t->exprtype != Boolean)
		return;
#ifdef PARSE_DEBUG
	cout << "node " << t->seq << ": " << t->label.true_label << ", " << t->label.false_label << endl;
#endif
	treenode *e1 = t->children[0];
	treenode *e2 = t->children[1];
	switch (t->attr.op)
	{
	case LOG_AND:
	{
		e1->label.true_label = new_label();
	    e2->label.true_label = t->label.true_label;
	    e1->label.false_label = e2->label.false_label = t->label.false_label;
	break;
	}
	case LOG_OR:
	{
		e1->label.false_label = new_label();
		e1->label.true_label =e2->label.true_label= t->label.true_label;
		e2->label.false_label = t->label.false_label;
		break;
	}
	case LOG_NOT:
	{
		e1->label.true_label = t->label.false_label;
		e1->label.false_label = t->label.true_label;
		break;
	}
	}
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}

void tree::gen_header(ofstream &out)
{
	out << "\t.586" << endl;
	out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap :none" << endl;
	out << endl;
	out << "\tinclude D:\\masm32\\include\\msvcrt.inc" << endl;
	out << "\tinclude D:\\masm32\\include\\kernel32.inc" << endl;
	out << "\tinclude D:\\masm32\\include\\masm32.inc" << endl;
	out << endl;
	out << "\tincludelib D:\\masm32\\lib\\msvcrt.lib" << endl;
	out << "\tincludelib D:\\masm32\\lib\\kernel32.lib" << endl;
	out << "\tincludelib D:\\masm32\\lib\\masm32.lib" << endl;
}
void tree::table_gendecl(ofstream &out, treenode *t)
{
	out << endl << endl << "\t.data" << endl;

	for (int j = 0; j < table.table.size(); j++)
	{
		if(table.table[j].type==0)//0 int
			out << "\t\t_" << table.table[j].attribute << " DWORD 0" << endl;
		else if (table.table[j].type == 1)//1 char
			out << "\t\t_" << table.table[j].attribute << " BYTE 0" << endl;
		else if (table.table[j].type == 3)//array
		{
			int num = 1;
			arrayattr *p = &table.table[j].arrayattr;
			while (p != NULL)
			{
				num *= p->areanum;
				p = p->next;
			}
			table.table[j].arraynum = num;
			if(table.table[j].arraytype == 0)
			    out << "\t\t_" << table.table[j].attribute << " DWORD " << num<< " DUP(0)" << endl;
			if (table.table[j].arraytype == 1)
				out << "\t\t_" << table.table[j].attribute << " BYTE " << num << " DUP(0)" << endl;
		}
	}
	for (int i = 0; i < temp_var_num; i++)
	{
		out << "\t\tt" << i << " DWORD 0" << endl;
	}
	out << "\t\t ctemp BYTE 0" << endl;//测试char型临时变量
	out << "\t\t type0 db '%d', 0" << endl;
	out << "\t\t type1 db '%c', 0" << endl;
	out << "\t\t type2 db '%s', 0" << endl;
	out << "\t\t typen db 0dh,0ah, 0" << endl;
	out << "\t\t typet db 09h, 0" << endl;
}

void tree::recursive_gen_code(ofstream &out, treenode *t)
{
	if (t->nodekind == STMT_KIND)
	{
		stmt_code(out, t);
	}
	else if (t->nodekind == EXPR_KIND && t->kind == OP_EXPR)
	{
		expr_code(out, t);
	}
	else if (t->nodekind == EXPR_KIND && t->kind == ARR_EXPR)
	{
		arr_code(out, t);
	}
	else if (t->nodekind == DECL_KIND)
	{
		decl_assign_code(out,t);
	}
}
void tree::arr_code(ofstream &out, treenode* t)
{
	treenode *e = t->children[0];
	arrayattr* arrattr = &table.table[t->attr.index].arrayattr;
	int num = table.table[t->attr.index].arraynum;
	out << "\tMOV t" << t->temp_var << ",0" << endl;
	while (e)
	{
		if (e->kind == OP_EXPR)
		{
			recursive_gen_code(out, e);
			num = num / arrattr->areanum;
			out << "\tMOV eax," << num << endl;
			out << "\tMUL t" << e->temp_var << endl;

			//out << "\tMOV t" << e->temp_var << ",eax" << endl;//应该可以省略
			//out << "\tMOV eax,t" << e->temp_var << endl;

			out << "\tADD eax,t" << t->temp_var << endl;
			out << "\tMOV t" << t->temp_var << ",eax" << endl;
		}
		else if (e->kind == CONST_EXPR)
		{
			num = num / arrattr->areanum;
			out << "\tMOV eax," << num << endl;
			out << "\tMOV ebx," << e->attr.vali << endl;
			out << "\tMUL ebx"<< endl;

			out << "\tADD eax,t" << t->temp_var << endl;
			out << "\tMOV t" << t->temp_var << ",eax" << endl;
		}
		else if (e->kind == ID_EXPR)
		{
			num = num / arrattr->areanum;
			out << "\tMOV eax," << num << endl;
			out << "\tMUL _" <<table.table[e->attr.index].attribute<< endl;
			out << "\tADD eax,t" << t->temp_var << endl;
			out << "\tMOV t" << t->temp_var << ",eax" << endl;
		}
		e = e->sibling;
		arrattr = arrattr->next;
	}
}
void tree::stmt_code(ofstream &out, treenode *t)
{
	if (t->kind == COMP_STMT)
	{
		for (int i = 0; t->children[i]; i++)
		{
			recursive_gen_code(out, t->children[i]);
			for (treenode *p = t->children[i]->sibling; p; p = p->sibling)
			{
				//out << t->label.begin_label << ":" << endl;
				recursive_gen_code(out, p);
			}
		}
	}
	else if (t->kind == WHILE_STMT)
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->children[0]);
		out << t->children[0]->label.true_label << ":" << endl;
		recursive_gen_code(out, t->children[1]);
		out << "\tjmp " << t->label.begin_label << endl;
		//out << t->label.next_label<<":" << endl;
	}
	else if (t->kind == IO_STMT)
	{
		if((t->label.begin_label != "") && (t->label.begin_label != "_start"))
		out << t->label.begin_label << ":";
		treenode *v = t->children[0];
		if (v->exprtype == Input)
		{
			treenode *v2 = t->children[1];
			if (v2->kind == ARR_EXPR)
			{
				recursive_gen_code(out, v2);
				out << "\tMOV eax,t" << v2->temp_var << endl;
			}
			out << "\tinvoke crt_scanf,";
			if (v2->exprtype == Integer)
			{
				out << "addr type0,";
				out << "addr " << "_" << table.table[v2->attr.index].attribute << endl;
			}
			else if (v2->exprtype == Char)
			{
				out << "addr type1,";
				out << "addr " << "_" << table.table[v2->attr.index].attribute << endl;
			}
			else if (v2->kind == ARR_EXPR)
			{
				if (table.table[v2->attr.index].arraytype == 0)
					out << "addr type0,";
				else if (table.table[v2->attr.index].arraytype == 1)
					out << "addr type1,";
				out << "addr " << "_" << table.table[v2->attr.index].attribute <<"[eax]"<< endl;
			}
		}
		else if (v->exprtype == Output)
		{
			treenode *v2 = t->children[1];
			if (v2->kind == ID_EXPR)
			{
				out << "\tinvoke crt_printf,";
				if(table.table[v2->attr.index].type==0)
					out << "addr type0," << "_" << table.table[v2->attr.index].attribute << endl;
				else if(table.table[v2->attr.index].type == 1)
					out << "addr type1," << "_" << table.table[v2->attr.index].attribute << endl;
				else if (table.table[v2->attr.index].type == 2)
					out << "addr type1," << "_" << table.table[v2->attr.index].attribute << endl;
				return;
			}
			if (v2->kind == ARR_EXPR)
			{
				recursive_gen_code(out, v2);
				out << "\tMOV eax,t" << v2->temp_var << endl;
			}
			out << "\tinvoke crt_printf,";
			if (v2->exprtype == Integer)
			{
				out << "addr type0,";
				if (v2->kind == ID_EXPR)//没用了
					out << "_" << table.table[v2->attr.index].attribute<<endl;
				else if (v2->kind == CONST_EXPR)
					out << v2->attr.vali<<endl;
			}
			else if (v2->exprtype == Char)
			{ 
				out << "addr type1,";
				if (v2->kind == ID_EXPR)//没用了
					out << "_" << table.table[v2->attr.index].attribute<<endl;
				else if (v2->kind == CONST_EXPR)
					out <<"'"<< v2->attr.valc<<"'"<<endl;
			}
			else if (v2->exprtype == Float)
			{
				//add…
			}
			else if (v2->exprtype == Helpchar)
			{
				out << "addr type"<< v2->attr.valc <<endl;
			}
			else if (v2->kind == ARR_EXPR)
			{
				if (table.table[v2->attr.index].arraytype == 0)
					out << "addr type0,";
				else if (table.table[v2->attr.index].arraytype == 1)
					out << "addr type1,";
				out << "_" << table.table[v2->attr.index].attribute << "[eax]" << endl;
			}
		}
	}
	else if (t->kind == IF_STMT)
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, t->children[0]);
		out <<t->children[0]->label.true_label<<":" << endl;
		recursive_gen_code(out, t->children[1]);

		if (t->children[2])
		{
			out << "\tjmp " << t->label.next_label << endl;//for else 
			out << t->children[0]->label.false_label << ":" << endl;
			recursive_gen_code(out, t->children[2]);
		}
	}
	else if (t->kind == FOR_STMT)
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;

			recursive_gen_code(out, t->children[0]);
			out << "\tjmp " << t->children[1]->label.begin_label << endl;

			recursive_gen_code(out, t->children[2]);
			if (t->children[2]->nodekind == NO_KIND)//缺省时使用
				out << t->children[2]->label.begin_label<<":"<<endl;
			out << t->children[1]->label.begin_label << ":";
			recursive_gen_code(out, t->children[1]);
			//out << t->children[3]->label.begin_label << ":";
			recursive_gen_code(out, t->children[3]);
			out << "\tjmp " << t->children[3]->label.next_label << endl;
	}
}
void tree::decl_assign_code(ofstream &out, treenode *t)
{
		if (t->children[2] != NULL)
		{
			if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
				out << t->label.begin_label << ":" << endl;
			treenode *e = t->children[2];
			recursive_gen_code(out, e);
			if (e->exprtype == Char)
			{
				out << "\tMOV ";
				out << "_" << table.table[t->children[1]->attr.index].attribute;
				out << ",";
				out << "'" << e->attr.valc << "'" << endl;
			}
			else {
				out << "\tMOV eax,";
				if (e->kind == ID_EXPR)
					out << "_" << table.table[e->attr.index].attribute;
				else if (e->kind == CONST_EXPR)
					out << e->attr.vali;
				else out << "t" << e->temp_var;

				out << endl;
				out << "\tMOV ";
				out << "_" << table.table[t->children[1]->attr.index].attribute;
				out << ", eax" << endl;
			}
		}
		else if (!(t->sibling))//可能出现最后声明的情况
			if((t->label.begin_label!="")&&(t->label.begin_label!="_start"))
			out << t->label.begin_label << ":";
}
void tree::expr_code(ofstream &out, treenode *t)
{
	treenode *e1 = t->children[0];
	treenode *e2 = t->children[1];
	switch (t->attr.op)
	{
	case OP_ASSIGN:
	{
		if ((t->label.begin_label != "")&&(t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->exprtype == Char)
		{
			if (e1->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e1->temp_var << endl;
			out << "\tMOV ";
			if (e1->kind == ID_EXPR)
				out << "_" << table.table[e1->attr.index].attribute;
			else if (e1->kind == ARR_EXPR)
				out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
			else out << "t"<<t->temp_var;
			out << ",";
			if (e2->kind == CONST_EXPR)
				out << "'" << e2->attr.valc << "'" << endl;
			else
				out << "ctemp" << endl;
		}
		else {
			if (e2->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e2->temp_var << endl;
			out << "\tMOV eax, ";
			if (e2->kind == ID_EXPR)
				out << "_" << table.table[e2->attr.index].attribute;
			else if (e2->kind == CONST_EXPR)
				out << e2->attr.vali;
			else if (e2->kind == ARR_EXPR)
				out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
			else out << "t" << e2->temp_var;
			out << endl;

			if(e1->kind==ARR_EXPR)
				out << "\tMOV ebx,t" << e1->temp_var << endl;
			out << "\tMOV ";
			if (e1->kind == ID_EXPR)
				out << "_" << table.table[e1->attr.index].attribute;
			else if(e1->kind==ARR_EXPR)
				out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
			else out << "t" << e1->temp_var;
			out << ", eax" << endl;
		}
		break;
	}
	case OP_BPPLUS:
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, e1);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax,1" << endl;
		out << "\tADD eax,";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tMOV ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << ",eax" << endl;

		out << "\tMOV t" << t->temp_var << ",eax"<<endl;

		break;
	}
	case  OP_BMMINUS:
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, e1);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax,";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tSUB eax,1"<<endl;
		out << "\tMOV ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << ",eax" << endl;

		out << "\tMOV t" << t->temp_var << ",eax" << endl;
		break;
	}
	case OP_APPLUS:
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, e1);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax,1" << endl;

		out << "\tMOV ecx,";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ",ecx"<<endl;
		

		out << "\tADD eax,";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tMOV ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << ",eax" << endl;

		break;
	}
	case OP_AMMINUS:
	{
		if ((t->label.begin_label != "") && (t->label.begin_label != "_start"))
			out << t->label.begin_label << ":" << endl;
		recursive_gen_code(out, e1);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax,";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;

		out << "\tMOV t" << t->temp_var << ",eax" << endl;

		out << "\tSUB eax,1" << endl;
		out << "\tMOV ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << ",eax" << endl;
		break;
	}
	case OP_PLUS:
	{
		/*if (t->label.begin_label != "")
			out << t->label.begin_label << ":" << endl;*///可有可无
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tADD eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	}
	case OP_MINUS:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		out << "\tSUB eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	}
	case OP_MUL:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ecx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
	bool flag1 = false;
	if (e1->kind == CONST_EXPR)
		out << e1->attr.vali;
	else if (e2->kind == CONST_EXPR)
		out << e2->attr.vali;
	else if (e1->kind == ID_EXPR)
		out << "_" << table.table[e1->attr.index].attribute;
	else if (e1->kind == ARR_EXPR)
		out << "_" << table.table[e1->attr.index].attribute << "[ecx]";
	else {
		out << "t" << e1->temp_var;
		flag1 = true;
	}
	out << endl;
	if (e1->kind == CONST_EXPR&&e2->kind == CONST_EXPR)
		out << "\tMOV ebx, " << e2->attr.vali<<endl;

	if (e2->kind == ARR_EXPR)
		out << "\tMOV ecx,t" << e2->temp_var << endl;

	out << "\tMUL ";
	if (e2->kind == ID_EXPR)
		out << "_" << table.table[e2->attr.index].attribute;
	else if (e2->kind == ARR_EXPR)
		out << "_" << table.table[e2->attr.index].attribute << "[ecx]";
	else if ((e1->kind == ID_EXPR) && (e2->kind == CONST_EXPR))
		out << "_" << table.table[e1->attr.index].attribute;
	else if ((e1->kind == ARR_EXPR) && (e2->kind == CONST_EXPR))
		out << "_" << table.table[e1->attr.index].attribute<<"[ecx]";
	else if (e1->kind == CONST_EXPR&&e2->kind == CONST_EXPR)
		out << "ebx";
	else out << "t" << e2->temp_var;
	out << endl;
	out << "\tMOV t" << t->temp_var << ", eax" << endl;
	break;
	}
	case OP_DIV:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ecx,t" << e1->temp_var << endl;
		out << "\tMOV edx,0" << endl;
		out << "\tMOV eax, ";
		if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ecx]";
		else {
			out << "t" << e1->temp_var;
		}
		out << endl;
	
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ecx,t" << e2->temp_var << endl;
		if (e2->kind == CONST_EXPR)
			out << "\tMOV ebx, " << e2->attr.vali << endl;

		out << "\tDIV ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << "ebx";
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ecx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	}
	case OP_MOD:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ecx,t" << e1->temp_var << endl;
		out << "\tMOV edx,0" << endl;
		out << "\tMOV eax, ";
		if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ecx]";
		else {
			out << "t" << e1->temp_var;
		}
		out << endl;

		if (e2->kind == ARR_EXPR)
			out << "\tMOV ecx,t" << e2->temp_var << endl;
		if (e2->kind == CONST_EXPR)
			out << "\tMOV ebx, " << e2->attr.vali << endl;

		out << "\tDIV ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << "ebx";
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ecx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", edx" << endl;
		break;
	}
	case LSS:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjl " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case EQU:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tje " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case GTR:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjg " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case NEQ:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjne " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case GEQ:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjge " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case LEQ:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tCMP eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tjle " << t->label.true_label << endl;
		out << "\tjmp " << t->label.false_label << endl;
		break;
	}
	case LOG_AND:
	{
		expr_code(out, t->children[0]);
		out << t->children[0]->label.true_label<<":";
		expr_code(out, t->children[1]);
		break;
	}
	case LOG_OR:
	{
		expr_code(out, t->children[0]);
		out << t->children[0]->label.false_label << ":";
		expr_code(out, t->children[1]);
		break;
	}
	case LOG_NOT:
	{
		expr_code(out, t->children[0]);
		break;
	}
	case OP_LAND:
	{		
	recursive_gen_code(out, e1);
	recursive_gen_code(out, e2);
	if (e1->kind == ARR_EXPR)
		out << "\tMOV ebx,t" << e1->temp_var << endl;
	out << "\tMOV eax, ";
	if (e1->kind == ID_EXPR)
		out << "_" << table.table[e1->attr.index].attribute;
	else if (e1->kind == CONST_EXPR)
		out << e1->attr.vali;
	else if (e1->kind == ARR_EXPR)
		out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
	else out << "t" << e1->temp_var;
	out << endl;
	if (e2->kind == ARR_EXPR)
		out << "\tMOV ebx,t" << e2->temp_var << endl;
	out << "\tAND eax, ";
	if (e2->kind == ID_EXPR)
		out << "_" << table.table[e2->attr.index].attribute;
	else if (e2->kind == CONST_EXPR)
		out << e2->attr.vali;
	else if (e2->kind == ARR_EXPR)
		out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
	else out << "t" << e2->temp_var;
	out << endl;
	out << "\tMOV t" << t->temp_var << ", eax" << endl;
	break;
	}
	case OP_LOR:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tOR eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	}
	case OP_LXOR:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		out << "\tMOV eax, ";
		if (e1->kind == ID_EXPR)
			out << "_" << table.table[e1->attr.index].attribute;
		else if (e1->kind == CONST_EXPR)
			out << e1->attr.vali;
		else if (e1->kind == ARR_EXPR)
			out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
		else out << "t" << e1->temp_var;
		out << endl;
		if (e2->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e2->temp_var << endl;
		out << "\tXOR eax, ";
		if (e2->kind == ID_EXPR)
			out << "_" << table.table[e2->attr.index].attribute;
		else if (e2->kind == CONST_EXPR)
			out << e2->attr.vali;
		else if (e2->kind == ARR_EXPR)
			out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
		else out << "t" << e2->temp_var;
		out << endl;
		out << "\tMOV t" << t->temp_var << ", eax" << endl;
		break;
	}
	case OP_LS:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		if (e1->exprtype == Char)
		{
			if (e2->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e2->temp_var << endl;
			if (e2->kind != CONST_EXPR)
			{
				out << "\tMOV ecx,";
				if (e2->kind == ID_EXPR)
					out << "_" << table.table[e2->attr.index].attribute;
				else if (e2->kind == ARR_EXPR)
					out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
				else out << "ctemp";
				out << endl;
			}
			out << "\tSHL _" << table.table[e1->attr.index].attribute << ",";
			if (e2->kind == CONST_EXPR)
				out << e2->attr.vali;
			else
				out << "cl";
			out << endl;
			out << "\tMOV ctemp, al" << endl;
		}
		else {
			out << "\tMOV eax, ";
			if (e1->kind == ID_EXPR)
				out << "_" << table.table[e1->attr.index].attribute;
			else if (e1->kind == CONST_EXPR)
				out << e1->attr.vali;
			else if (e1->kind == ARR_EXPR)
				out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
			else out << "t" << e1->temp_var;
			out << endl;
			if (e2->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e2->temp_var << endl;
			if (e2->kind != CONST_EXPR)
			{
				out << "\tMOV ecx,";
				if (e2->kind == ID_EXPR)
					out << "_" << table.table[e2->attr.index].attribute;
				else if (e2->kind == ARR_EXPR)
					out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
				else out << "t" << e2->temp_var;
				out << endl;
			}
			out << "\tSHL eax, ";
			if (e2->kind == CONST_EXPR)
				out << e2->attr.vali;
			else
				out << "cl";
			out << endl;
			out << "\tMOV t" << t->temp_var << ", eax" << endl;
		}
		break;
	}
	case OP_RS:
	{
		recursive_gen_code(out, e1);
		recursive_gen_code(out, e2);
		if (e1->kind == ARR_EXPR)
			out << "\tMOV ebx,t" << e1->temp_var << endl;
		if (e1->exprtype == Char)
		{
			if (e2->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e2->temp_var << endl;
			if (e2->kind != CONST_EXPR)
			{
				out << "\tMOV ecx,";
				if (e2->kind == ID_EXPR)
					out << "_" << table.table[e2->attr.index].attribute;
				else if (e2->kind == ARR_EXPR)
					out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
				else out << "ctemp";
				out << endl;
			}
			out << "\tSHL _" << table.table[e1->attr.index].attribute << ",";
			if (e2->kind == CONST_EXPR)
				out << e2->attr.vali;
			else
				out << "cl";
			out << endl;
			out << "\tMOV ctemp, al" << endl;
		}
		else {
			out << "\tMOV eax, ";
			if (e1->kind == ID_EXPR)
				out << "_" << table.table[e1->attr.index].attribute;
			else if (e1->kind == CONST_EXPR)
				out << e1->attr.vali;
			else if (e1->kind == ARR_EXPR)
				out << "_" << table.table[e1->attr.index].attribute << "[ebx]";
			else out << "t" << e1->temp_var;
			out << endl;
			if (e2->kind == ARR_EXPR)
				out << "\tMOV ebx,t" << e2->temp_var << endl;
			if (e2->kind != CONST_EXPR)
			{
				out << "\tMOV ecx,";
				if (e2->kind == ID_EXPR)
					out << "_" << table.table[e2->attr.index].attribute;
				else if (e2->kind == ARR_EXPR)
					out << "_" << table.table[e2->attr.index].attribute << "[ebx]";
				else out << "t" << e2->temp_var;
				out << endl;
			}
			out << "\tSHR eax, ";
			if (e2->kind == CONST_EXPR)
				out << e2->attr.vali;
			else
				out << "cl";
			out << endl;
			out << "\tMOV t" << t->temp_var << ", eax" << endl;
		}
		break;
	}
	}
}
void tree::start_compiler(ofstream &out)
{
	treenode *p = root;
	p->label.begin_label = "_start";
	recursive_get_label(p);
	gen_header(out);
	table_gendecl(out, root);
	out << endl << "\t.code" << endl;
	out << endl << root->label.begin_label <<":"<< endl;
	recursive_gen_code(out, root);
	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\tinvoke ExitProcess, 0" << endl;
	out << "end " << root->label.begin_label << endl;
}