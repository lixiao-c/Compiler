%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2017年12月2日
****************************************************************************/
#include "myparser.h"
#include "symboltable.h"
#include "tree.h"
extern sort table;
int area=0;
int lineno=1;
treenode node;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

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

// place any declarations here

WS	[\n]
WSP [ \t]
INT [0123456789]+
FLOATNUM [0123456789][\.][0123456789]+
NUM {INT}|{FLOAT}
ID [a-zA-Z][a-zA-Z0-9]*

CONSTCHAR ['].[']
HELPCHAR [$][n|t]

ERROR .

//注释正则
B ["].*["]
F [^*/]*
G [*]+[^/]
H [/]*
R [*]?
K [/][*]({B}|{F}|{G}|{H})*{R}[*][/]
A [/][/].*[\n]

%%
/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{A}        cout<<"this is short note"<<endl;
{K}         cout<<"this is long note"<<endl;
"["   {return LSB;}
"]"   {return RSB;}
"if"  {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"int" {return INT;}
"char"  {return CHAR;}
//"double" {return DOUBLE;}
"float" {return FLOAT;}
"bool"  {return BOOL;}
"true"  {return TRUE;}
"false" {return FALSE;}

"input"		{ return INPUT;}
"output"		{return OUTPUT;}
"main"		{ return MAIN;}
{CONSTCHAR}      {yylval=&node;
              yylval->attr.valc=yytext[1];
             return CONSTCHAR;}                
{HELPCHAR}   {yylval=&node;
              yylval->attr.valc=yytext[1];
             return HELPCHAR;
             }
"++"        {return PPLUS;}
"--"        {return MMINUS;}
"=="        { return EQ;}
"<="        {return LE;}
">="        {return GE;}
"!="        { return NE;}
"="         {return ASSIGN;}
//"~"         {return LNOT;}
"<<"        {return LS;}
">>"        {return RS;}
"<"         {return LT;}
">"         { return GT;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         { return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
";"         { return SEMICOLON;}
","         { return COMMA;}
"("         {return LPAREN;}
")"         {return RPAREN;}
"{"         {area++;
return LBRACE;}
"}"         {area--;
return RBRACE;}
"||"        {return OR;}
"&&"        {return AND;}
"!"         {return NOT;}
"&"         {return LAND;}
"|"         {return LOR;}
"^"         {return LXOR;}

//num
{INT}   {
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
}

{FLOATNUM} {
float fnum=yytext[0]-'0';
for(int i=2;i<strlen(yytext);i++)
{
fnum=(yytext[i]-'0')*0.1+fnum;
}
yylval=&node;
yylval->attr.vali2=fnum;
yylval->attr.op=NOTYPE;
return FLOATNUM;
}
{ID}            
{int i=table.insert(yytext,area);
yylval=&node;
yylval->attr.index=i;
yylval->attr.op=NOTYPE;
return ID;
}

{WS}				    {lineno++;}/* do nothing */    
{WSP}           ;             

{ERROR} {cout<<yytext;return ERROR;}
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

