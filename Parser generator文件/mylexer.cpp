/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 77 of your 30 day trial period.
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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 01/01/18
* Time: 22:02:19
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2017Äê12ÔÂ2ÈÕ
****************************************************************************/
#include "myparser.h"
#include "symboltable.h"
#include "tree.h"
extern sort table;
int area=0;
int lineno=1;
treenode node;

#line 54 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 29 ".\\mylexer.l"

	// place any extra initialisation code here

#line 78 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 34 ".\\mylexer.l"

	// place any extra cleanup code here

#line 90 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 65 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 161 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 71 ".\\mylexer.l"
cout<<"this is short note"<<endl;
#line 168 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 72 ".\\mylexer.l"
cout<<"this is long note"<<endl;
#line 175 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 73 ".\\mylexer.l"
return LSB;
#line 182 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 74 ".\\mylexer.l"
return RSB;
#line 189 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 75 ".\\mylexer.l"
return IF;
#line 196 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 76 ".\\mylexer.l"
return ELSE;
#line 203 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 77 ".\\mylexer.l"
return WHILE;
#line 210 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 78 ".\\mylexer.l"
return FOR;
#line 217 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 79 ".\\mylexer.l"
return INT;
#line 224 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 80 ".\\mylexer.l"
return CHAR;
#line 231 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 82 ".\\mylexer.l"
return FLOAT;
#line 238 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 83 ".\\mylexer.l"
return BOOL;
#line 245 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 84 ".\\mylexer.l"
return TRUE;
#line 252 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 85 ".\\mylexer.l"
return FALSE;
#line 259 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 87 ".\\mylexer.l"
 return INPUT;
#line 266 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 88 ".\\mylexer.l"
return OUTPUT;
#line 273 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 89 ".\\mylexer.l"
 return MAIN;
#line 280 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 90 ".\\mylexer.l"
yylval=&node;
              yylval->attr.valc=yytext[1];
             return CONSTCHAR;
#line 289 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 93 ".\\mylexer.l"
yylval=&node;
              yylval->attr.valc=yytext[1];
             return HELPCHAR;
             
#line 299 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 97 ".\\mylexer.l"
return PPLUS;
#line 306 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 98 ".\\mylexer.l"
return MMINUS;
#line 313 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 99 ".\\mylexer.l"
 return EQ;
#line 320 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 100 ".\\mylexer.l"
return LE;
#line 327 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 101 ".\\mylexer.l"
return GE;
#line 334 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 102 ".\\mylexer.l"
 return NE;
#line 341 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 103 ".\\mylexer.l"
return ASSIGN;
#line 348 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 105 ".\\mylexer.l"
return LS;
#line 355 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 106 ".\\mylexer.l"
return RS;
#line 362 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 107 ".\\mylexer.l"
return LT;
#line 369 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 108 ".\\mylexer.l"
 return GT;
#line 376 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 109 ".\\mylexer.l"
return PLUS;
#line 383 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 110 ".\\mylexer.l"
return MINUS;
#line 390 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 111 ".\\mylexer.l"
 return MUL;
#line 397 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 112 ".\\mylexer.l"
return DIV;
#line 404 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 113 ".\\mylexer.l"
return MOD;
#line 411 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 114 ".\\mylexer.l"
 return SEMICOLON;
#line 418 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 115 ".\\mylexer.l"
 return COMMA;
#line 425 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 116 ".\\mylexer.l"
return LPAREN;
#line 432 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 117 ".\\mylexer.l"
return RPAREN;
#line 439 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 118 ".\\mylexer.l"
area++;
return LBRACE;
#line 447 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 120 ".\\mylexer.l"
area--;
return RBRACE;
#line 455 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 122 ".\\mylexer.l"
return OR;
#line 462 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 123 ".\\mylexer.l"
return AND;
#line 469 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 124 ".\\mylexer.l"
return NOT;
#line 476 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 125 ".\\mylexer.l"
return LAND;
#line 483 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 126 ".\\mylexer.l"
return LOR;
#line 490 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 127 ".\\mylexer.l"
return LXOR;
#line 497 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 130 ".\\mylexer.l"

//cout<<yytext<<endl;
int num=0;
for(int i=0;i<strlen(yytext);i++)
{
num=num*10+yytext[i]-'0';
}
yylval=&node;
yylval->attr.vali=num;
yylval->attr.op=NOTYPE;
return INTNUM;

#line 515 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 143 ".\\mylexer.l"

float fnum=yytext[0]-'0';
for(int i=2;i<strlen(yytext);i++)
{
fnum=(yytext[i]-'0')*0.1+fnum;
}
yylval=&node;
yylval->attr.vali2=fnum;
yylval->attr.op=NOTYPE;
return FLOATNUM;

#line 532 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 155 ".\\mylexer.l"
int i=table.insert(yytext,area);
yylval=&node;
yylval->attr.index=i;
yylval->attr.op=NOTYPE;
return ID;

#line 544 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 162 ".\\mylexer.l"
lineno++;
#line 551 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 163 ".\\mylexer.l"
;
#line 558 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 165 ".\\mylexer.l"
cout<<yytext;return ERROR;
#line 565 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 242;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 0, 106 },
		{ 57, 30 },
		{ 40, 7 },
		{ 45, 105 },
		{ 85, 69 },
		{ 68, 99 },
		{ 60, 31 },
		{ 78, 61 },
		{ 40, 7 },
		{ 86, 69 },
		{ 62, 32 },
		{ 79, 61 },
		{ 58, 30 },
		{ 69, 99 },
		{ 61, 31 },
		{ 59, 30 },
		{ 40, 7 },
		{ 63, 33 },
		{ 45, 17 },
		{ 49, 20 },
		{ 50, 20 },
		{ 4, 1 },
		{ 6, 1 },
		{ 46, 17 },
		{ 68, 106 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 84, 105 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 85, 85 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 99, 85 },
		{ 64, 34 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 65, 35 },
		{ 25, 1 },
		{ 26, 1 },
		{ 52, 22 },
		{ 53, 22 },
		{ 23, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 23, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 31, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 32, 1 },
		{ 23, 1 },
		{ 33, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 34, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 35, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 97, 97 },
		{ 66, 37 },
		{ 67, 42 },
		{ 70, 46 },
		{ 39, 6 },
		{ 105, 97 },
		{ 72, 54 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 73, 55 },
		{ 74, 56 },
		{ 75, 57 },
		{ 76, 58 },
		{ 77, 59 },
		{ 47, 18 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 23, 107 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 48, 48 },
		{ 80, 62 },
		{ 81, 63 },
		{ 82, 64 },
		{ 83, 65 },
		{ 41, 9 },
		{ 51, 21 },
		{ 87, 72 },
		{ 88, 73 },
		{ 89, 74 },
		{ 90, 75 },
		{ 91, 76 },
		{ 92, 78 },
		{ 93, 80 },
		{ 94, 81 },
		{ 95, 82 },
		{ 96, 83 },
		{ 98, 84 },
		{ 0, 10 },
		{ 100, 90 },
		{ 101, 91 },
		{ 102, 92 },
		{ 103, 94 },
		{ 104, 96 },
		{ 54, 27 },
		{ 55, 28 },
		{ 107, 103 },
		{ 56, 29 },
		{ 43, 14 },
		{ 44, 16 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 53 },
		{ 0, 0, 52 },
		{ 0, 0, 51 },
		{ 0, 71, 44 },
		{ 0, -105, 53 },
		{ 0, 0, 35 },
		{ 0, 179, 45 },
		{ -42, 220, 53 },
		{ 0, 0, 38 },
		{ 0, 0, 39 },
		{ 0, 0, 33 },
		{ 0, 197, 31 },
		{ 0, 0, 37 },
		{ 0, 196, 32 },
		{ 0, -21, 34 },
		{ 48, 120, 48 },
		{ 0, 0, 36 },
		{ 0, -38, 29 },
		{ 0, 157, 26 },
		{ 0, 26, 30 },
		{ 107, 0, 50 },
		{ 0, 0, 3 },
		{ 0, 0, 4 },
		{ 0, 0, 47 },
		{ 107, 125, 50 },
		{ 107, 133, 50 },
		{ 107, 131, 50 },
		{ 107, -93, 50 },
		{ 107, -93, 50 },
		{ 107, -84, 50 },
		{ 107, -97, 50 },
		{ 107, -58, 50 },
		{ 107, -20, 50 },
		{ 0, 0, 40 },
		{ 0, 5, 46 },
		{ 0, 0, 41 },
		{ 0, 0, 25 },
		{ 0, 0, 19 },
		{ 0, 0, 43 },
		{ 0, 91, 0 },
		{ 0, 0, 20 },
		{ 0, 0, 21 },
		{ 99, 0, 0 },
		{ -46, 121, 0 },
		{ 71, 0, 0 },
		{ 0, 155, 48 },
		{ 0, 0, 27 },
		{ 0, 0, 23 },
		{ 0, 0, 22 },
		{ 0, 0, 24 },
		{ 0, 0, 28 },
		{ 107, 23, 50 },
		{ 107, 64, 50 },
		{ 107, 47, 50 },
		{ 107, 55, 50 },
		{ 107, 53, 50 },
		{ 107, 51, 50 },
		{ 107, 0, 5 },
		{ 107, -102, 50 },
		{ 107, 108, 50 },
		{ 107, 98, 50 },
		{ 107, 98, 50 },
		{ 107, 111, 50 },
		{ 0, 0, 42 },
		{ 0, 0, 18 },
		{ 105, 0, 0 },
		{ -45, -35, 0 },
		{ 0, 0, 1 },
		{ 0, 145, 49 },
		{ 107, 111, 50 },
		{ 107, 106, 50 },
		{ 107, 120, 50 },
		{ 107, 107, 50 },
		{ 107, 126, 50 },
		{ 107, 0, 8 },
		{ 107, 107, 50 },
		{ 107, 0, 9 },
		{ 107, 115, 50 },
		{ 107, 114, 50 },
		{ 107, 126, 50 },
		{ 107, 120, 50 },
		{ 97, 182, 0 },
		{ 99, 8, 0 },
		{ 0, 0, 2 },
		{ 107, 0, 12 },
		{ 107, 0, 10 },
		{ 107, 0, 6 },
		{ 107, 130, 50 },
		{ 107, 116, 50 },
		{ 107, 117, 50 },
		{ 107, 0, 17 },
		{ 107, 117, 50 },
		{ 107, 0, 13 },
		{ 107, 134, 50 },
		{ 105, 86, 0 },
		{ 106, 0, 2 },
		{ -45, -26, 2 },
		{ 107, 0, 14 },
		{ 107, 0, 11 },
		{ 107, 0, 15 },
		{ 107, 122, 50 },
		{ 107, 0, 7 },
		{ -68, -4, 2 },
		{ -106, -7, 0 },
		{ 0, 70, 16 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 166 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


