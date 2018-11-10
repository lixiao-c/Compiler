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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/02/18
* Time: 16:08:14
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 28 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 43 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE treenode*
#endif

#line 82 "myparser.h"
#define INT 257
#define CHAR 258
#define FLOAT 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define INPUT 263
#define OUTPUT 264
#define FOR 265
#define BOOL 266
#define TRUE 267
#define FALSE 268
#define ID 269
#define NUM 270
#define CONSTCHAR 271
#define MAIN 272
#define INTNUM 273
#define FLOATNUM 274
#define HELPCHAR 275
#define AND 276
#define OR 277
#define NOT 278
#define ASSIGN 279
#define EQ 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define NE 285
#define PLUS 286
#define MINUS 287
#define MUL 288
#define DIV 289
#define MOD 290
#define LPAREN 291
#define RPAREN 292
#define SEMICOLON 293
#define COMMA 294
#define LBRACE 295
#define RBRACE 296
#define PPLUS 297
#define MMINUS 298
#define LOR 299
#define LXOR 300
#define LAND 301
#define LSB 302
#define RSB 303
#define LS 304
#define RS 305
#define ERROR 306
#define UMINUS 307
#endif
