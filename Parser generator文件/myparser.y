%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2017年12月2日
****************************************************************************/
#include<iostream>
#include<fstream>
#include "mylexer.h"
#include "tree.h"
#include "symboltable.h"
extern int lineno;
extern tree parse_tree;
extern sort table;
ofstream out1("out.asm");

arrayattr temparr;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE treenode*
#endif
}

%token INT CHAR FLOAT IF ELSE WHILE INPUT OUTPUT FOR BOOL TRUE FALSE
%token ID NUM CONSTCHAR MAIN INTNUM FLOATNUM HELPCHAR
%token AND OR NOT ASSIGN EQ LT LE GT GE NE PLUS MINUS MUL DIV MOD LPAREN RPAREN SEMICOLON COMMA LBRACE RBRACE PPLUS MMINUS 
LOR LXOR LAND LSB RSB LS RS //LNOT 
%token ERROR
%nonassoc PPLUS
%nonassoc MMINUS
%nonassoc UMINUS
%nonassoc ELSE
// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
        
        
program             : MAIN LPAREN RPAREN compound_stmt{$$=$4;}
                     ;
compound_stmt       :LBRACE statement_list RBRACE{$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),COMP_STMT,NodeAttr(), Expr_Type(Notype),$2);};
                 

statement_list      : statement_list statement 
                      { 
                            treenode*  t = $1;
                            if (t != NULL)
                            { 
                                   while (t->sibling != NULL)
                                       t = t->sibling;
                                   t->sibling = $2;
                                   $$ = $1; 
                            }
                            else 
                                 $$ = $2;
                      }
                    | statement{$$=$1;}
                    ;
statement           : expression_stmt{$$=$1;}

                    | var_declaration{$$=$1;}
                 
                    | compound_stmt{$$=$1;}

                    | selection_stmt{$$=$1;}
                      
                    | while_stmt{$$=$1;}
                    
                    | for_stmt{$$=$1;}
                     
                    | io_stmt {$$=$1;}
                    ;

expression_stmt     : expression SEMICOLON {$$=$1;} 

                    | SEMICOLON{$$=NULL;}
                    ;

selection_stmt     
                    : IF LPAREN expression RPAREN statement %prec UMINUS              
                    {$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IF_STMT,NodeAttr(), Expr_Type(Notype),$3,$5);}
                    | IF LPAREN expression RPAREN statement ELSE statement 
                    {$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IF_STMT,NodeAttr(), Expr_Type(Notype),$3,$5,$7);}
                    ;
                    
var_declaration     : type_specifier varlist SEMICOLON{$$=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),$1,$2);
                                 for (treenode* p = $2;p;p=p->sibling)
								{  
									p->exprtype = $1->exprtype;
									if(table.table[p->attr.index].type>=0&&table.table[p->attr.index].type<3)
								   {
								   cout<<"line"<<lineno<<"重定义错误"<<endl;;
								   return;
								   }
								   if(table.table[p->attr.index].type!=3)
									table.table[p->attr.index].type=$1->exprtype;
								   else  table.table[p->attr.index].arraytype=$1->exprtype;
								}}
					|type_specifier var ASSIGN expression SEMICOLON{$$=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),$1,$2,$4);
					    treenode* p = $2;
					    	if(table.table[p->attr.index].type>=0&&table.table[p->attr.index].type<4)
								   {
								   cout<<"line"<<lineno<<"重定义错误"<<endl;;
								   return;
								   }
						table.table[p->attr.index].type=$1->exprtype;
					}
					;

varlist				: varlist COMMA var{treenode *t=$1;
                                            if (t!= NULL){
											while (t->sibling != NULL)
										           t = t->sibling;
											t->sibling = $3;
											$$ = $1; 
									        }
									       else 
										   $$ = $1;}
				    |var{$$=$1;}
				    ;
										
type_specifier      : INT {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(0));}
                    | CHAR{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(1));}
                    | FLOAT{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(2));}
                    //| BOOL{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(), Expr_Type(Boolean));}
                    ;
var					:ID arraylist{
                    treenode* p=$1;
                    //table.table[p->attr.index].arraynum=$2->attr.vali;
                    table.table[p->attr.index].type=3;
                    table.table[p->attr.index].arrayattr=temparr;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,$1->attr,Expr_Type(Array),$2);
                    temparr.area=0;
                    temparr.areanum=0;
                    temparr.next=NULL;
                    }
                    |ID{
                    $$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,$1->attr,Expr_Type(Notype));}
                    ;
arraylist           :arraylist arrayele
                     {
                     treenode *t=$1;
                     if (t!= NULL){
				     while (t->sibling != NULL)
		                t = t->sibling;
						t->sibling = $2;
						$$ = $1; 
					  }
				     else 
					  $$ = $1;
                     }
                     |arrayele
                     {
                     $$=$1;
                     }
                    ;
arrayele            :LSB INTNUM RSB
                     {
                     if(temparr.areanum==0)
                     {
                     temparr.areanum=$2->attr.vali;
                     }
                     else
                     {
                     arrayattr* p=&temparr;
                     arrayattr* temp=&temparr;
                     int t=0;
                     while(p!=NULL)
                     {
                     t=p->area;
                     p=p->next;
                     }
                     p=new arrayattr;
                     p->area=t+1;
                     p->areanum=$2->attr.vali;
                     while(temp->next!=NULL)
                     temp=temp->next;
                     temp->next=p;
                     }
                     $$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,$2->attr,Expr_Type());}
                    ;
                    
id                  :ID{
                    $$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,$1->attr,Expr_Type(Notype));}
                    |id arrayoplist
                    {
                    $$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ARR_EXPR,$1->attr,Expr_Type(Array),$2);
                    }
                    ;
arrayoplist         :arrayoplist arrayopele
                    {
                     treenode *t=$1;
                     if (t!= NULL){
				     while (t->sibling != NULL)
		                t = t->sibling;
						t->sibling = $2;
						$$ = $1; 
					  }
				     else 
					  $$ = $1;
                    }
                    |arrayopele
                    {
                    $$=$1;
                    }
                    ;
arrayopele          :LSB expression RSB
                    {
                    $$ = $2;
                    }
                    ;


while_stmt          : WHILE LPAREN expression RPAREN statement{$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),WHILE_STMT,NodeAttr(), Expr_Type(Notype),$3,$5);}
                    ;

for_stmt            :FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement
                    {$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),$3,$5,$7,$9);}
                    
                    |FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement
                    {treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp,$4,$6,$8);}
                    
                    |FOR LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN statement
                    {treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),$3,temp,$6,$8);}
                    
                    |FOR LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN statement
                    {treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),$3,$5,temp,$8);}
                    
                    |FOR LPAREN  SEMICOLON  SEMICOLON expression RPAREN statement
                    {treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,temp2,$5,$7);}
                    
                    |FOR LPAREN  SEMICOLON expression SEMICOLON RPAREN statement
                    {treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,$4,temp2,$7);}
                    
                    |FOR LPAREN firstexpr SEMICOLON SEMICOLON RPAREN statement
                    {treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),$3,temp1,temp2,$7);}
                
                    
                    |FOR LPAREN SEMICOLON SEMICOLON RPAREN statement
                    {treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    treenode* temp3=new treenode();temp3->nodekind=NO_KIND;
                    $$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,temp2,temp3,$6);}
                    ;
firstexpr        :expression{$$=$1;}

                 |type_specifier id ASSIGN expression{$$=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),$1,$2,$4);
					    treenode* p = $2;
						table.table[p->attr.index].type=$1->exprtype;
					}
				;
io_stmt          : io_type LPAREN expression RPAREN SEMICOLON{$$=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IO_STMT,NodeAttr(), Expr_Type(Notype),$1,$3);}
                 ;
                    
io_type          : INPUT {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(Input));}
                 | OUTPUT {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(Output));}
                 ;
expression          : id ASSIGN expression{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_ASSIGN), Expr_Type(Notype),$1,$3);
                    }

                    | or_expression{$$=$1;}
                    ;
                    
or_expression       : or_expression OR and_expression  {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_OR), Expr_Type(Notype),$1,$3);}

                    | and_expression{$$=$1;}
                    ;

and_expression      : and_expression AND lor_expression  {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_AND), Expr_Type(Notype),$1,$3);}

                    | lor_expression{$$=$1;}
                    ;
        
lor_expression      : lor_expression LOR lxor_expression  {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LOR), Expr_Type(Notype),$1,$3);}

                    | lxor_expression{$$=$1;}
                    ;
lxor_expression      : lxor_expression LXOR land_expression  {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LXOR), Expr_Type(Notype),$1,$3);}

                    | land_expression{$$=$1;}
                    ;
land_expression      : land_expression LAND com_expression  {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LAND), Expr_Type(Notype),$1,$3);}

                    | com_expression{$$=$1;}
                    ;

com_expression      : com_expression EQ normal_expression{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(EQU), Expr_Type(Notype),$1,$3);}

					| com_expression LT normal_expression	{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LSS), Expr_Type(Notype),$1,$3);}

					| com_expression GT normal_expression	{ $$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(GTR), Expr_Type(Notype),$1,$3);}

					| com_expression LE normal_expression	{ $$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LEQ), Expr_Type(Notype),$1,$3);}

					| com_expression GE normal_expression	{ $$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(GEQ), Expr_Type(Notype),$1,$3);}

					| com_expression NE normal_expression	{ $$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(NEQ), Expr_Type(Notype),$1,$3);}

					| normal_expression{$$=$1;}
					;

normal_expression    :normal_expression LS plusminus_expression{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LS), Expr_Type(Notype),$1,$3);}
                     
                     |normal_expression RS plusminus_expression{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_RS), Expr_Type(Notype),$1,$3);}
                     
                     |plusminus_expression{$$=$1;}
                      
                     ;

plusminus_expression: plusminus_expression PLUS term{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_PLUS), Expr_Type(Notype),$1,$3);}
                   
                    | plusminus_expression MINUS term{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MINUS), Expr_Type(Notype),$1,$3);}
                    
                    | term{$$=$1;}
                    ;

term                : term MUL factor{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MUL), Expr_Type(Notype),$1,$3);}
                  
                    | term DIV factor{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_DIV), Expr_Type(Notype),$1,$3);}
                    
                    | term MOD factor{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MOD), Expr_Type(Notype),$1,$3);}
                    
                    | single{$$=$1;}
                    
                    ;

single             : single PPLUS {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_APPLUS), Expr_Type(Notype),$1);}
                    
                    | single MMINUS{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_AMMINUS), Expr_Type(Notype),$1);}
                    
                    | MMINUS single{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_BMMINUS), Expr_Type(Notype),$2);}
                    
                    | PPLUS single {$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_BPPLUS), Expr_Type(Notype),$2);}
                    
                    | NOT single %prec UMINUS{$$=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_NOT), Expr_Type(Notype),$2);}
                    
                    | factor{$$=$1;}
                    ;

factor              : LPAREN expression RPAREN {$$=$2;}
                   
                    | id{
                    treenode* p=$1;
                    if(table.table[p->attr.index].type<0||table.table[p->attr.index].type>=4)
								   {
								   cout<<"line"<<lineno<<"未定义标识符"<<endl;;
								   return;
								   }$$=$1;}
                    
                    | INTNUM{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,$1->attr,Expr_Type(Integer));}
                    
                    | CONSTCHAR{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,$1->attr,Expr_Type(Char));}
                    
                    | HELPCHAR{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,$1->attr,Expr_Type(Helpchar));}
                    
                    | FLOATNUM{$$ = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,$1->attr,Expr_Type(Float));}
                    
                    ;
                            
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	//ofstream out1;
	//out1.open("E:\\out.txt");
	freopen("input.txt","r",stdin); 
	//freopen("input.txt","w",stdin); 
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
			
			parse_tree.start_compiler(out1);
		}
	}
    //freopen("CON","r",stdin);
    out1.close();
	freopen("CON","r",stdin); 
	if(n==1)
	cout<<"error exist in line"<<lineno<<endl;
	cout<<"****symbol table****"<<endl;
	cout<<"标识符"<<"\t\t"<<"类型"<<"\t"<<"作用域"<<endl;
	table.printall();
	system("pause");
	return n;
}