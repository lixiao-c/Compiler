/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 78 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 01/02/18
* Time: 16:08:14
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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

#line 58 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 33 ".\\myparser.y"

	// place any extra initialisation code here

#line 82 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 38 ".\\myparser.y"

	// place any extra cleanup code here

#line 96 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 68 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);
#line 206 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 70 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),COMP_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(2 - 3));
#line 219 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 74 ".\\myparser.y"
 
                            treenode*  t = yyattribute(1 - 2);
                            if (t != NULL)
                            { 
                                   while (t->sibling != NULL)
                                       t = t->sibling;
                                   t->sibling = yyattribute(2 - 2);
                                   (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
                            }
                            else 
                                 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
                      
#line 243 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 86 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 256 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 88 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 269 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 90 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 282 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 92 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 295 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 94 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 308 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 96 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 321 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 98 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 334 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 100 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 347 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 103 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
#line 360 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 105 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=NULL;
#line 373 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 110 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IF_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 5),yyattribute(5 - 5));
#line 386 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 112 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IF_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 7),yyattribute(5 - 7),yyattribute(7 - 7));
#line 399 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 115 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(2 - 3));
                                 for (treenode* p = yyattribute(2 - 3);p;p=p->sibling)
								{  
									p->exprtype = yyattribute(1 - 3)->exprtype;
									if(table.table[p->attr.index].type>=0&&table.table[p->attr.index].type<3)
								   {
								   cout<<"line"<<lineno<<"重定义错误"<<endl;;
								   return;
								   }
								   if(table.table[p->attr.index].type!=3)
									table.table[p->attr.index].type=yyattribute(1 - 3)->exprtype;
								   else  table.table[p->attr.index].arraytype=yyattribute(1 - 3)->exprtype;
								}
#line 424 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 128 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),yyattribute(1 - 5),yyattribute(2 - 5),yyattribute(4 - 5));
					    treenode* p = yyattribute(2 - 5);
					    	if(table.table[p->attr.index].type>=0&&table.table[p->attr.index].type<4)
								   {
								   cout<<"line"<<lineno<<"重定义错误"<<endl;;
								   return;
								   }
						table.table[p->attr.index].type=yyattribute(1 - 5)->exprtype;
					
#line 445 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 139 ".\\myparser.y"
treenode *t=yyattribute(1 - 3);
                                            if (t!= NULL){
											while (t->sibling != NULL)
										           t = t->sibling;
											t->sibling = yyattribute(3 - 3);
											(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3); 
									        }
									       else 
										   (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
#line 466 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 148 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 479 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(0));
#line 492 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 152 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(1));
#line 505 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 153 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(2));
#line 518 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 156 ".\\myparser.y"

                    treenode* p=yyattribute(1 - 2);
                    //table.table[p->attr.index].arraynum=$2->attr.vali;
                    table.table[p->attr.index].type=3;
                    table.table[p->attr.index].arrayattr=temparr;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,yyattribute(1 - 2)->attr,Expr_Type(Array),yyattribute(2 - 2));
                    temparr.area=0;
                    temparr.areanum=0;
                    temparr.next=NULL;
                    
#line 540 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 166 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Notype));
#line 554 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 170 ".\\myparser.y"

                     treenode *t=yyattribute(1 - 2);
                     if (t!= NULL){
				     while (t->sibling != NULL)
		                t = t->sibling;
						t->sibling = yyattribute(2 - 2);
						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
					  }
				     else 
					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
                     
#line 577 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 182 ".\\myparser.y"

                     (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                     
#line 592 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 187 ".\\myparser.y"

                     if(temparr.areanum==0)
                     {
                     temparr.areanum=yyattribute(2 - 3)->attr.vali;
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
                     p->areanum=yyattribute(2 - 3)->attr.vali;
                     while(temp->next!=NULL)
                     temp=temp->next;
                     temp->next=p;
                     }
                     (*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,yyattribute(2 - 3)->attr,Expr_Type());
#line 627 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 212 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ID_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Notype));
#line 641 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 215 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),ARR_EXPR,yyattribute(1 - 2)->attr,Expr_Type(Array),yyattribute(2 - 2));
                    
#line 656 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 220 ".\\myparser.y"

                     treenode *t=yyattribute(1 - 2);
                     if (t!= NULL){
				     while (t->sibling != NULL)
		                t = t->sibling;
						t->sibling = yyattribute(2 - 2);
						(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
					  }
				     else 
					  (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
                    
#line 679 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 232 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 694 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 237 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
                    
#line 709 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 243 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),WHILE_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 5),yyattribute(5 - 5));
#line 722 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 247 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 9),yyattribute(5 - 9),yyattribute(7 - 9),yyattribute(9 - 9));
#line 735 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 250 ".\\myparser.y"
treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp,yyattribute(4 - 8),yyattribute(6 - 8),yyattribute(8 - 8));
#line 749 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 254 ".\\myparser.y"
treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 8),temp,yyattribute(6 - 8),yyattribute(8 - 8));
#line 763 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 258 ".\\myparser.y"
treenode* temp=new treenode();temp->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 8),yyattribute(5 - 8),temp,yyattribute(8 - 8));
#line 777 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 262 ".\\myparser.y"
treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,temp2,yyattribute(5 - 7),yyattribute(7 - 7));
#line 792 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 267 ".\\myparser.y"
treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,yyattribute(4 - 7),temp2,yyattribute(7 - 7));
#line 807 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 272 ".\\myparser.y"
treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(3 - 7),temp1,temp2,yyattribute(7 - 7));
#line 822 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 278 ".\\myparser.y"
treenode* temp1=new treenode();temp1->nodekind=NO_KIND;
                    treenode* temp2=new treenode();temp2->nodekind=NO_KIND;
                    treenode* temp3=new treenode();temp3->nodekind=NO_KIND;
                    (*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),FOR_STMT,NodeAttr(), Expr_Type(Notype),temp1,temp2,temp3,yyattribute(6 - 6));
#line 838 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 283 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 851 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 285 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(DECL_KIND),VAR_DECL,NodeAttr(), Expr_Type(Notype),yyattribute(1 - 4),yyattribute(2 - 4),yyattribute(4 - 4));
					    treenode* p = yyattribute(2 - 4);
						table.table[p->attr.index].type=yyattribute(1 - 4)->exprtype;
					
#line 867 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 290 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(STMT_KIND),IO_STMT,NodeAttr(), Expr_Type(Notype),yyattribute(1 - 5),yyattribute(3 - 5));
#line 880 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 293 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(Input));
#line 893 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 294 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),TYPE_EXPR,NodeAttr(NOTYPE), Expr_Type(Output));
#line 906 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 296 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_ASSIGN), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 920 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 299 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 933 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 302 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_OR), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 946 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 304 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 959 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 307 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_AND), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 972 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 309 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 985 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 312 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LOR), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 998 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 314 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1011 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 316 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LXOR), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1024 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 318 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1037 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 320 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LAND), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1050 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 322 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1063 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 325 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(EQU), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1076 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 327 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LSS), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1089 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 329 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(GTR), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1102 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 331 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LEQ), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1115 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 333 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(GEQ), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1128 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 335 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(NEQ), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1141 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 337 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1154 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 340 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_LS), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1167 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 342 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_RS), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1180 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 344 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1193 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 348 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_PLUS), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1206 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 350 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MINUS), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1219 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 352 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1232 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 355 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MUL), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1245 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 357 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_DIV), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1258 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 359 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_MOD), Expr_Type(Notype),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1271 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 361 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1284 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 365 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_APPLUS), Expr_Type(Notype),yyattribute(1 - 2));
#line 1297 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 367 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_AMMINUS), Expr_Type(Notype),yyattribute(1 - 2));
#line 1310 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 369 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_BMMINUS), Expr_Type(Notype),yyattribute(2 - 2));
#line 1323 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 371 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(OP_BPPLUS), Expr_Type(Notype),yyattribute(2 - 2));
#line 1336 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 373 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),OP_EXPR,NodeAttr(LOG_NOT), Expr_Type(Notype),yyattribute(2 - 2));
#line 1349 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 375 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1362 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 378 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 1375 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 380 ".\\myparser.y"

                    treenode* p=yyattribute(1 - 1);
                    if(table.table[p->attr.index].type<0||table.table[p->attr.index].type>=4)
								   {
								   cout<<"line"<<lineno<<"未定义标识符"<<endl;;
								   return;
								   }(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1394 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 388 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Integer));
#line 1407 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 390 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Char));
#line 1420 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 392 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Helpchar));
#line 1433 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 394 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.NewRoot(lineno,Node_Kind(EXPR_KIND),CONST_EXPR,yyattribute(1 - 1)->attr,Expr_Type(Float));
#line 1446 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "CHAR", 258 },
		{ "FLOAT", 259 },
		{ "IF", 260 },
		{ "ELSE", 261 },
		{ "WHILE", 262 },
		{ "INPUT", 263 },
		{ "OUTPUT", 264 },
		{ "FOR", 265 },
		{ "ID", 269 },
		{ "CONSTCHAR", 271 },
		{ "MAIN", 272 },
		{ "INTNUM", 273 },
		{ "FLOATNUM", 274 },
		{ "HELPCHAR", 275 },
		{ "AND", 276 },
		{ "OR", 277 },
		{ "NOT", 278 },
		{ "ASSIGN", 279 },
		{ "EQ", 280 },
		{ "LT", 281 },
		{ "LE", 282 },
		{ "GT", 283 },
		{ "GE", 284 },
		{ "NE", 285 },
		{ "PLUS", 286 },
		{ "MINUS", 287 },
		{ "MUL", 288 },
		{ "DIV", 289 },
		{ "MOD", 290 },
		{ "LPAREN", 291 },
		{ "RPAREN", 292 },
		{ "SEMICOLON", 293 },
		{ "COMMA", 294 },
		{ "LBRACE", 295 },
		{ "RBRACE", 296 },
		{ "PPLUS", 297 },
		{ "MMINUS", 298 },
		{ "LOR", 299 },
		{ "LXOR", 300 },
		{ "LAND", 301 },
		{ "LSB", 302 },
		{ "RSB", 303 },
		{ "LS", 304 },
		{ "RS", 305 },
		{ "UMINUS", 307 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN LPAREN RPAREN compound_stmt",
		"compound_stmt: LBRACE statement_list RBRACE",
		"statement_list: statement_list statement",
		"statement_list: statement",
		"statement: expression_stmt",
		"statement: var_declaration",
		"statement: compound_stmt",
		"statement: selection_stmt",
		"statement: while_stmt",
		"statement: for_stmt",
		"statement: io_stmt",
		"expression_stmt: expression SEMICOLON",
		"expression_stmt: SEMICOLON",
		"selection_stmt: IF LPAREN expression RPAREN statement",
		"selection_stmt: IF LPAREN expression RPAREN statement ELSE statement",
		"var_declaration: type_specifier varlist SEMICOLON",
		"var_declaration: type_specifier var ASSIGN expression SEMICOLON",
		"varlist: varlist COMMA var",
		"varlist: var",
		"type_specifier: INT",
		"type_specifier: CHAR",
		"type_specifier: FLOAT",
		"var: ID arraylist",
		"var: ID",
		"arraylist: arraylist arrayele",
		"arraylist: arrayele",
		"arrayele: LSB INTNUM RSB",
		"id: ID",
		"id: id arrayoplist",
		"arrayoplist: arrayoplist arrayopele",
		"arrayoplist: arrayopele",
		"arrayopele: LSB expression RSB",
		"while_stmt: WHILE LPAREN expression RPAREN statement",
		"for_stmt: FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement",
		"for_stmt: FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement",
		"for_stmt: FOR LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN statement",
		"for_stmt: FOR LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN statement",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement",
		"for_stmt: FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement",
		"for_stmt: FOR LPAREN firstexpr SEMICOLON SEMICOLON RPAREN statement",
		"for_stmt: FOR LPAREN SEMICOLON SEMICOLON RPAREN statement",
		"firstexpr: expression",
		"firstexpr: type_specifier id ASSIGN expression",
		"io_stmt: io_type LPAREN expression RPAREN SEMICOLON",
		"io_type: INPUT",
		"io_type: OUTPUT",
		"expression: id ASSIGN expression",
		"expression: or_expression",
		"or_expression: or_expression OR and_expression",
		"or_expression: and_expression",
		"and_expression: and_expression AND lor_expression",
		"and_expression: lor_expression",
		"lor_expression: lor_expression LOR lxor_expression",
		"lor_expression: lxor_expression",
		"lxor_expression: lxor_expression LXOR land_expression",
		"lxor_expression: land_expression",
		"land_expression: land_expression LAND com_expression",
		"land_expression: com_expression",
		"com_expression: com_expression EQ normal_expression",
		"com_expression: com_expression LT normal_expression",
		"com_expression: com_expression GT normal_expression",
		"com_expression: com_expression LE normal_expression",
		"com_expression: com_expression GE normal_expression",
		"com_expression: com_expression NE normal_expression",
		"com_expression: normal_expression",
		"normal_expression: normal_expression LS plusminus_expression",
		"normal_expression: normal_expression RS plusminus_expression",
		"normal_expression: plusminus_expression",
		"plusminus_expression: plusminus_expression PLUS term",
		"plusminus_expression: plusminus_expression MINUS term",
		"plusminus_expression: term",
		"term: term MUL factor",
		"term: term DIV factor",
		"term: term MOD factor",
		"term: single",
		"single: single PPLUS",
		"single: single MMINUS",
		"single: MMINUS single",
		"single: PPLUS single",
		"single: NOT single",
		"single: factor",
		"factor: LPAREN expression RPAREN",
		"factor: id",
		"factor: INTNUM",
		"factor: CONSTCHAR",
		"factor: HELPCHAR",
		"factor: FLOATNUM"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 3, 2, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 5, 2, 11 },
		{ 5, 1, 12 },
		{ 6, 5, 13 },
		{ 6, 7, 14 },
		{ 7, 3, 15 },
		{ 7, 5, 16 },
		{ 8, 3, 17 },
		{ 8, 1, 18 },
		{ 9, 1, 19 },
		{ 9, 1, 20 },
		{ 9, 1, 21 },
		{ 10, 2, 22 },
		{ 10, 1, 23 },
		{ 11, 2, 24 },
		{ 11, 1, 25 },
		{ 12, 3, 26 },
		{ 13, 1, 27 },
		{ 13, 2, 28 },
		{ 14, 2, 29 },
		{ 14, 1, 30 },
		{ 15, 3, 31 },
		{ 16, 5, 32 },
		{ 17, 9, 33 },
		{ 17, 8, 34 },
		{ 17, 8, 35 },
		{ 17, 8, 36 },
		{ 17, 7, 37 },
		{ 17, 7, 38 },
		{ 17, 7, 39 },
		{ 17, 6, 40 },
		{ 18, 1, 41 },
		{ 18, 4, 42 },
		{ 19, 5, 43 },
		{ 20, 1, 44 },
		{ 20, 1, 45 },
		{ 21, 3, 46 },
		{ 21, 1, 47 },
		{ 22, 3, 48 },
		{ 22, 1, 49 },
		{ 23, 3, 50 },
		{ 23, 1, 51 },
		{ 24, 3, 52 },
		{ 24, 1, 53 },
		{ 25, 3, 54 },
		{ 25, 1, 55 },
		{ 26, 3, 56 },
		{ 26, 1, 57 },
		{ 27, 3, 58 },
		{ 27, 3, 59 },
		{ 27, 3, 60 },
		{ 27, 3, 61 },
		{ 27, 3, 62 },
		{ 27, 3, 63 },
		{ 27, 1, 64 },
		{ 28, 3, 65 },
		{ 28, 3, 66 },
		{ 28, 1, 67 },
		{ 29, 3, 68 },
		{ 29, 3, 69 },
		{ 29, 1, 70 },
		{ 30, 3, 71 },
		{ 30, 3, 72 },
		{ 30, 3, 73 },
		{ 30, 1, 74 },
		{ 31, 2, 75 },
		{ 31, 2, 76 },
		{ 31, 2, 77 },
		{ 31, 2, 78 },
		{ 31, 2, 79 },
		{ 31, 1, 80 },
		{ 32, 3, 81 },
		{ 32, 1, 82 },
		{ 32, 1, 83 },
		{ 32, 1, 84 },
		{ 32, 1, 85 },
		{ 32, 1, 86 }
	};
	yyreduction = reduction;

	yytokenaction_size = 123;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 153, YYAT_SHIFT, 16 },
		{ 128, YYAT_SHIFT, 142 },
		{ 153, YYAT_SHIFT, 17 },
		{ 153, YYAT_SHIFT, 18 },
		{ 153, YYAT_SHIFT, 19 },
		{ 32, YYAT_SHIFT, 61 },
		{ 166, YYAT_SHIFT, 10 },
		{ 153, YYAT_SHIFT, 20 },
		{ 166, YYAT_SHIFT, 11 },
		{ 166, YYAT_SHIFT, 12 },
		{ 166, YYAT_SHIFT, 13 },
		{ 166, YYAT_SHIFT, 14 },
		{ 51, YYAT_SHIFT, 7 },
		{ 51, YYAT_SHIFT, 8 },
		{ 51, YYAT_SHIFT, 9 },
		{ 83, YYAT_ERROR, 0 },
		{ 119, YYAT_SHIFT, 81 },
		{ 119, YYAT_SHIFT, 82 },
		{ 119, YYAT_SHIFT, 83 },
		{ 162, YYAT_SHIFT, 166 },
		{ 153, YYAT_SHIFT, 21 },
		{ 153, YYAT_SHIFT, 161 },
		{ 115, YYAT_SHIFT, 79 },
		{ 115, YYAT_SHIFT, 80 },
		{ 128, YYAT_SHIFT, 62 },
		{ 152, YYAT_SHIFT, 160 },
		{ 153, YYAT_SHIFT, 23 },
		{ 153, YYAT_SHIFT, 24 },
		{ 32, YYAT_SHIFT, 62 },
		{ 118, YYAT_SHIFT, 81 },
		{ 118, YYAT_SHIFT, 82 },
		{ 118, YYAT_SHIFT, 83 },
		{ 114, YYAT_SHIFT, 79 },
		{ 114, YYAT_SHIFT, 80 },
		{ 83, YYAT_ERROR, 0 },
		{ 83, YYAT_ERROR, 0 },
		{ 42, YYAT_SHIFT, 81 },
		{ 42, YYAT_SHIFT, 82 },
		{ 42, YYAT_SHIFT, 83 },
		{ 166, YYAT_SHIFT, 22 },
		{ 150, YYAT_SHIFT, 158 },
		{ 166, YYAT_SHIFT, 5 },
		{ 117, YYAT_SHIFT, 68 },
		{ 117, YYAT_SHIFT, 69 },
		{ 117, YYAT_SHIFT, 70 },
		{ 117, YYAT_SHIFT, 71 },
		{ 117, YYAT_SHIFT, 72 },
		{ 117, YYAT_SHIFT, 73 },
		{ 51, YYAT_SHIFT, 90 },
		{ 36, YYAT_SHIFT, 68 },
		{ 36, YYAT_SHIFT, 69 },
		{ 36, YYAT_SHIFT, 70 },
		{ 36, YYAT_SHIFT, 71 },
		{ 36, YYAT_SHIFT, 72 },
		{ 36, YYAT_SHIFT, 73 },
		{ 112, YYAT_SHIFT, 75 },
		{ 112, YYAT_SHIFT, 76 },
		{ 111, YYAT_SHIFT, 75 },
		{ 111, YYAT_SHIFT, 76 },
		{ 110, YYAT_SHIFT, 75 },
		{ 110, YYAT_SHIFT, 76 },
		{ 109, YYAT_SHIFT, 75 },
		{ 109, YYAT_SHIFT, 76 },
		{ 108, YYAT_SHIFT, 75 },
		{ 108, YYAT_SHIFT, 76 },
		{ 107, YYAT_SHIFT, 75 },
		{ 107, YYAT_SHIFT, 76 },
		{ 60, YYAT_SHIFT, 100 },
		{ 60, YYAT_SHIFT, 101 },
		{ 43, YYAT_SHIFT, 84 },
		{ 43, YYAT_SHIFT, 85 },
		{ 41, YYAT_SHIFT, 79 },
		{ 41, YYAT_SHIFT, 80 },
		{ 38, YYAT_SHIFT, 75 },
		{ 38, YYAT_SHIFT, 76 },
		{ 142, YYAT_ERROR, 0 },
		{ 141, YYAT_SHIFT, 153 },
		{ 140, YYAT_SHIFT, 151 },
		{ 139, YYAT_SHIFT, 149 },
		{ 138, YYAT_SHIFT, 148 },
		{ 135, YYAT_SHIFT, 146 },
		{ 132, YYAT_SHIFT, 145 },
		{ 130, YYAT_SHIFT, 144 },
		{ 129, YYAT_SHIFT, 143 },
		{ 127, YYAT_SHIFT, 140 },
		{ 126, YYAT_SHIFT, 139 },
		{ 125, YYAT_SHIFT, 137 },
		{ 116, YYAT_SHIFT, 66 },
		{ 113, YYAT_SHIFT, 67 },
		{ 106, YYAT_SHIFT, 77 },
		{ 105, YYAT_SHIFT, 78 },
		{ 103, YYAT_SHIFT, 134 },
		{ 101, YYAT_SHIFT, 58 },
		{ 97, YYAT_SHIFT, 96 },
		{ 96, YYAT_SHIFT, 130 },
		{ 95, YYAT_SHIFT, 129 },
		{ 92, YYAT_SHIFT, 15 },
		{ 91, YYAT_SHIFT, 127 },
		{ 90, YYAT_SHIFT, 125 },
		{ 89, YYAT_SHIFT, 124 },
		{ 88, YYAT_SHIFT, 123 },
		{ 63, YYAT_SHIFT, 62 },
		{ 59, YYAT_SHIFT, 99 },
		{ 58, YYAT_SHIFT, 96 },
		{ 55, YYAT_SHIFT, 85 },
		{ 54, YYAT_SHIFT, 94 },
		{ 52, YYAT_SHIFT, 62 },
		{ 47, YYAT_SHIFT, 86 },
		{ 40, YYAT_SHIFT, 78 },
		{ 39, YYAT_SHIFT, 77 },
		{ 37, YYAT_SHIFT, 74 },
		{ 35, YYAT_SHIFT, 67 },
		{ 34, YYAT_SHIFT, 66 },
		{ 33, YYAT_SHIFT, 65 },
		{ 25, YYAT_SHIFT, 57 },
		{ 14, YYAT_SHIFT, 51 },
		{ 11, YYAT_SHIFT, 50 },
		{ 10, YYAT_SHIFT, 49 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -150, 1, YYAT_ERROR, 0 },
		{ -170, 1, YYAT_ERROR, 0 },
		{ 120, 1, YYAT_ERROR, 0 },
		{ -173, 1, YYAT_ERROR, 0 },
		{ -177, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -174, 1, YYAT_ERROR, 0 },
		{ -175, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ -176, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -177, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 101 },
		{ -274, 1, YYAT_REDUCE, 83 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ -188, 1, YYAT_REDUCE, 54 },
		{ -165, 1, YYAT_REDUCE, 50 },
		{ -231, 1, YYAT_REDUCE, 58 },
		{ -167, 1, YYAT_REDUCE, 48 },
		{ -231, 1, YYAT_REDUCE, 65 },
		{ -190, 1, YYAT_REDUCE, 52 },
		{ -193, 1, YYAT_REDUCE, 56 },
		{ -215, 1, YYAT_REDUCE, 68 },
		{ -252, 1, YYAT_REDUCE, 71 },
		{ -228, 1, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -189, 1, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -245, 1, YYAT_DEFAULT, 142 },
		{ -196, 1, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ -194, 1, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -199, 1, YYAT_REDUCE, 24 },
		{ -177, 1, YYAT_REDUCE, 19 },
		{ -226, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -201, 1, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ -263, 1, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -192, 1, YYAT_ERROR, 0 },
		{ -193, 1, YYAT_ERROR, 0 },
		{ -195, 1, YYAT_DEFAULT, 142 },
		{ -196, 1, YYAT_ERROR, 0 },
		{ -173, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ -197, 1, YYAT_ERROR, 0 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ -209, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -177, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -211, 1, YYAT_REDUCE, 55 },
		{ -210, 1, YYAT_REDUCE, 51 },
		{ -239, 1, YYAT_REDUCE, 59 },
		{ -241, 1, YYAT_REDUCE, 60 },
		{ -243, 1, YYAT_REDUCE, 62 },
		{ -245, 1, YYAT_REDUCE, 61 },
		{ -247, 1, YYAT_REDUCE, 63 },
		{ -249, 1, YYAT_REDUCE, 64 },
		{ -188, 1, YYAT_REDUCE, 49 },
		{ -254, 1, YYAT_REDUCE, 66 },
		{ -264, 1, YYAT_REDUCE, 67 },
		{ -213, 1, YYAT_REDUCE, 53 },
		{ -238, 1, YYAT_REDUCE, 57 },
		{ -259, 1, YYAT_REDUCE, 69 },
		{ -272, 1, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -206, 1, YYAT_DEFAULT, 153 },
		{ -208, 1, YYAT_ERROR, 0 },
		{ -209, 1, YYAT_DEFAULT, 142 },
		{ -278, 1, YYAT_ERROR, 0 },
		{ -210, 1, YYAT_ERROR, 0 },
		{ -221, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -181, 1, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -213, 1, YYAT_ERROR, 0 },
		{ -214, 1, YYAT_DEFAULT, 153 },
		{ -215, 1, YYAT_DEFAULT, 153 },
		{ -217, 1, YYAT_ERROR, 0 },
		{ -217, 1, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -252, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -267, 1, YYAT_ERROR, 0 },
		{ -271, 1, YYAT_DEFAULT, 92 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -273, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ -254, 1, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_REDUCE, 34 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 88;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 166, 45 },
		{ 83, 52 },
		{ 166, 167 },
		{ 166, 48 },
		{ 166, 29 },
		{ 166, 30 },
		{ 161, 165 },
		{ 166, 31 },
		{ 78, 117 },
		{ 78, 38 },
		{ 78, 41 },
		{ 128, 63 },
		{ 128, 64 },
		{ 153, 32 },
		{ 166, 28 },
		{ 166, 27 },
		{ 51, 92 },
		{ 166, 26 },
		{ 166, 25 },
		{ 166, 33 },
		{ 83, 122 },
		{ 153, 162 },
		{ 153, 37 },
		{ 153, 35 },
		{ 31, 60 },
		{ 51, 91 },
		{ 31, 59 },
		{ 160, 164 },
		{ 51, 93 },
		{ 80, 119 },
		{ 80, 43 },
		{ 77, 116 },
		{ 77, 40 },
		{ 76, 115 },
		{ 76, 42 },
		{ 74, 113 },
		{ 74, 39 },
		{ 73, -1 },
		{ 73, 112 },
		{ 67, 106 },
		{ 67, 34 },
		{ 66, 105 },
		{ 66, 36 },
		{ 58, 97 },
		{ 58, 98 },
		{ 24, 56 },
		{ 24, 44 },
		{ 5, 47 },
		{ 5, 46 },
		{ 158, 163 },
		{ 151, 159 },
		{ 149, 157 },
		{ 148, 156 },
		{ 146, 155 },
		{ 142, 154 },
		{ 140, 152 },
		{ 139, 150 },
		{ 137, 147 },
		{ 127, 141 },
		{ 125, 138 },
		{ 124, 136 },
		{ 123, 135 },
		{ 101, 133 },
		{ 99, 132 },
		{ 97, 131 },
		{ 92, 128 },
		{ 90, 126 },
		{ 82, 121 },
		{ 81, 120 },
		{ 79, 118 },
		{ 75, 114 },
		{ 72, 111 },
		{ 71, 110 },
		{ 70, 109 },
		{ 69, 108 },
		{ 68, 107 },
		{ 63, 104 },
		{ 62, 103 },
		{ 61, 102 },
		{ 57, 95 },
		{ 50, 89 },
		{ 49, 88 },
		{ 47, 87 },
		{ 23, 55 },
		{ 21, 54 },
		{ 20, 53 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 86, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 84, -1 },
		{ 44, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 54, 24 },
		{ 63, 153 },
		{ 0, -1 },
		{ 52, 24 },
		{ 14, 83 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, 166 },
		{ 0, -1 },
		{ 60, 153 },
		{ 59, 153 },
		{ 7, 153 },
		{ 0, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 58, 153 },
		{ 32, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 153 },
		{ 56, 153 },
		{ 61, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 15, 78 },
		{ 15, 77 },
		{ 47, 73 },
		{ 46, 73 },
		{ 45, 73 },
		{ 44, 73 },
		{ 43, 73 },
		{ 10, 78 },
		{ 12, 67 },
		{ 41, 76 },
		{ 4, 80 },
		{ 6, 66 },
		{ -19, 76 },
		{ 39, 80 },
		{ -1, 24 },
		{ 36, 83 },
		{ 35, 83 },
		{ -12, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 153 },
		{ 0, -1 },
		{ 52, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, -1 },
		{ 0, -1 },
		{ 42, 153 },
		{ 0, -1 },
		{ 52, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 166 },
		{ 56, 166 },
		{ 38, 153 },
		{ 0, -1 },
		{ 37, 153 },
		{ -3, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 53, 166 },
		{ 0, -1 },
		{ 35, 153 },
		{ 34, 153 },
		{ 0, -1 },
		{ 33, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 166 },
		{ 0, -1 },
		{ 48, 166 },
		{ 47, 166 },
		{ 0, -1 },
		{ 46, 166 },
		{ 0, -1 },
		{ 0, 74 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 166 },
		{ 0, -1 },
		{ 23, 166 },
		{ 2, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 153 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 398 ".\\myparser.y"


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
