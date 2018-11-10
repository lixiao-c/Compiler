#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 78 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 01/02/18
# Time: 16:08:14
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : MAIN LPAREN RPAREN compound_stmt

    2  compound_stmt : LBRACE statement_list RBRACE

    3  statement_list : statement_list statement
    4                 | statement

    5  statement : expression_stmt
    6            | var_declaration
    7            | compound_stmt
    8            | selection_stmt
    9            | while_stmt
   10            | for_stmt
   11            | io_stmt

   12  expression_stmt : expression SEMICOLON
   13                  | SEMICOLON

   14  selection_stmt : IF LPAREN expression RPAREN statement
   15                 | IF LPAREN expression RPAREN statement ELSE statement

   16  var_declaration : type_specifier varlist SEMICOLON
   17                  | type_specifier var ASSIGN expression SEMICOLON

   18  varlist : varlist COMMA var
   19          | var

   20  type_specifier : INT
   21                 | CHAR
   22                 | FLOAT

   23  var : ID arraylist
   24      | ID

   25  arraylist : arraylist arrayele
   26            | arrayele

   27  arrayele : LSB INTNUM RSB

   28  id : ID
   29     | id arrayoplist

   30  arrayoplist : arrayoplist arrayopele
   31              | arrayopele

   32  arrayopele : LSB expression RSB

   33  while_stmt : WHILE LPAREN expression RPAREN statement

   34  for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement
   35           | FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement
   36           | FOR LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN statement
   37           | FOR LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN statement
   38           | FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement
   39           | FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement
   40           | FOR LPAREN firstexpr SEMICOLON SEMICOLON RPAREN statement
   41           | FOR LPAREN SEMICOLON SEMICOLON RPAREN statement

   42  firstexpr : expression
   43            | type_specifier id ASSIGN expression

   44  io_stmt : io_type LPAREN expression RPAREN SEMICOLON

   45  io_type : INPUT
   46          | OUTPUT

   47  expression : id ASSIGN expression
   48             | or_expression

   49  or_expression : or_expression OR and_expression
   50                | and_expression

   51  and_expression : and_expression AND lor_expression
   52                 | lor_expression

   53  lor_expression : lor_expression LOR lxor_expression
   54                 | lxor_expression

   55  lxor_expression : lxor_expression LXOR land_expression
   56                  | land_expression

   57  land_expression : land_expression LAND com_expression
   58                  | com_expression

   59  com_expression : com_expression EQ normal_expression
   60                 | com_expression LT normal_expression
   61                 | com_expression GT normal_expression
   62                 | com_expression LE normal_expression
   63                 | com_expression GE normal_expression
   64                 | com_expression NE normal_expression
   65                 | normal_expression

   66  normal_expression : normal_expression LS plusminus_expression
   67                    | normal_expression RS plusminus_expression
   68                    | plusminus_expression

   69  plusminus_expression : plusminus_expression PLUS term
   70                       | plusminus_expression MINUS term
   71                       | term

   72  term : term MUL factor
   73       | term DIV factor
   74       | term MOD factor
   75       | single

   76  single : single PPLUS
   77         | single MMINUS
   78         | MMINUS single
   79         | PPLUS single
   80         | NOT single
   81         | factor

   82  factor : LPAREN expression RPAREN
   83         | id
   84         | INTNUM
   85         | CONSTCHAR
   86         | HELPCHAR
   87         | FLOATNUM


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	MAIN  shift 1

	program  goto 2


state 1
	program : MAIN . LPAREN RPAREN compound_stmt

	LPAREN  shift 3


state 2
	$accept : program . $end  (0)

	$end  accept


state 3
	program : MAIN LPAREN . RPAREN compound_stmt

	RPAREN  shift 4


state 4
	program : MAIN LPAREN RPAREN . compound_stmt

	LBRACE  shift 5

	compound_stmt  goto 6


state 5
	compound_stmt : LBRACE . statement_list RBRACE

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 46
	statement_list  goto 47
	expression_stmt  goto 48


state 6
	program : MAIN LPAREN RPAREN compound_stmt .  (1)

	.  reduce 1


state 7
	type_specifier : INT .  (20)

	.  reduce 20


state 8
	type_specifier : CHAR .  (21)

	.  reduce 21


state 9
	type_specifier : FLOAT .  (22)

	.  reduce 22


state 10
	selection_stmt : IF . LPAREN expression RPAREN statement
	selection_stmt : IF . LPAREN expression RPAREN statement ELSE statement

	LPAREN  shift 49


state 11
	while_stmt : WHILE . LPAREN expression RPAREN statement

	LPAREN  shift 50


state 12
	io_type : INPUT .  (45)

	.  reduce 45


state 13
	io_type : OUTPUT .  (46)

	.  reduce 46


state 14
	for_stmt : FOR . LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON expression RPAREN statement
	for_stmt : FOR . LPAREN SEMICOLON expression SEMICOLON RPAREN statement
	for_stmt : FOR . LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement
	for_stmt : FOR . LPAREN firstexpr SEMICOLON SEMICOLON RPAREN statement
	for_stmt : FOR . LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN statement
	for_stmt : FOR . LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN statement
	for_stmt : FOR . LPAREN SEMICOLON SEMICOLON RPAREN statement

	LPAREN  shift 51


state 15
	id : ID .  (28)

	.  reduce 28


state 16
	factor : CONSTCHAR .  (85)

	.  reduce 85


state 17
	factor : INTNUM .  (84)

	.  reduce 84


state 18
	factor : FLOATNUM .  (87)

	.  reduce 87


state 19
	factor : HELPCHAR .  (86)

	.  reduce 86


state 20
	single : NOT . single

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	single  goto 53
	factor  goto 44


state 21
	factor : LPAREN . expression RPAREN

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 54
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 22
	expression_stmt : SEMICOLON .  (13)

	.  reduce 13


state 23
	single : PPLUS . single

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	single  goto 55
	factor  goto 44


state 24
	single : MMINUS . single

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	single  goto 56
	factor  goto 44


state 25
	io_stmt : io_type . LPAREN expression RPAREN SEMICOLON

	LPAREN  shift 57


state 26
	statement : io_stmt .  (11)

	.  reduce 11


state 27
	statement : for_stmt .  (10)

	.  reduce 10


state 28
	statement : while_stmt .  (9)

	.  reduce 9


state 29
	statement : selection_stmt .  (8)

	.  reduce 8


state 30
	statement : var_declaration .  (6)

	.  reduce 6


state 31
	var_declaration : type_specifier . varlist SEMICOLON
	var_declaration : type_specifier . var ASSIGN expression SEMICOLON

	ID  shift 58

	var  goto 59
	varlist  goto 60


state 32
	id : id . arrayoplist
	expression : id . ASSIGN expression
	factor : id .  (83)

	ASSIGN  shift 61
	LSB  shift 62
	.  reduce 83

	arrayoplist  goto 63
	arrayopele  goto 64


state 33
	expression_stmt : expression . SEMICOLON

	SEMICOLON  shift 65


state 34
	lor_expression : lxor_expression .  (54)
	lxor_expression : lxor_expression . LXOR land_expression

	LXOR  shift 66
	.  reduce 54


state 35
	or_expression : and_expression .  (50)
	and_expression : and_expression . AND lor_expression

	AND  shift 67
	.  reduce 50


state 36
	land_expression : com_expression .  (58)
	com_expression : com_expression . LT normal_expression
	com_expression : com_expression . GT normal_expression
	com_expression : com_expression . EQ normal_expression
	com_expression : com_expression . GE normal_expression
	com_expression : com_expression . LE normal_expression
	com_expression : com_expression . NE normal_expression

	EQ  shift 68
	LT  shift 69
	LE  shift 70
	GT  shift 71
	GE  shift 72
	NE  shift 73
	.  reduce 58


state 37
	or_expression : or_expression . OR and_expression
	expression : or_expression .  (48)

	OR  shift 74
	.  reduce 48


state 38
	normal_expression : normal_expression . RS plusminus_expression
	com_expression : normal_expression .  (65)
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 65


state 39
	lor_expression : lor_expression . LOR lxor_expression
	and_expression : lor_expression .  (52)

	LOR  shift 77
	.  reduce 52


state 40
	lxor_expression : land_expression .  (56)
	land_expression : land_expression . LAND com_expression

	LAND  shift 78
	.  reduce 56


state 41
	normal_expression : plusminus_expression .  (68)
	plusminus_expression : plusminus_expression . MINUS term
	plusminus_expression : plusminus_expression . PLUS term

	PLUS  shift 79
	MINUS  shift 80
	.  reduce 68


state 42
	term : term . DIV factor
	term : term . MUL factor
	term : term . MOD factor
	plusminus_expression : term .  (71)

	MUL  shift 81
	DIV  shift 82
	MOD  shift 83
	.  reduce 71


state 43
	term : single .  (75)
	single : single . PPLUS
	single : single . MMINUS

	PPLUS  shift 84
	MMINUS  shift 85
	.  reduce 75


state 44
	single : factor .  (81)

	.  reduce 81


state 45
	statement : compound_stmt .  (7)

	.  reduce 7


state 46
	statement_list : statement .  (4)

	.  reduce 4


state 47
	compound_stmt : LBRACE statement_list . RBRACE
	statement_list : statement_list . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	RBRACE  shift 86
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 87
	expression_stmt  goto 48


state 48
	statement : expression_stmt .  (5)

	.  reduce 5


state 49
	selection_stmt : IF LPAREN . expression RPAREN statement
	selection_stmt : IF LPAREN . expression RPAREN statement ELSE statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 88
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 50
	while_stmt : WHILE LPAREN . expression RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 89
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 51
	for_stmt : FOR LPAREN . SEMICOLON expression SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN . SEMICOLON expression SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN . firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN . firstexpr SEMICOLON SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN . firstexpr SEMICOLON SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN . firstexpr SEMICOLON expression SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN . SEMICOLON SEMICOLON RPAREN statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 90
	PPLUS  shift 23
	MMINUS  shift 24

	firstexpr  goto 91
	type_specifier  goto 92
	id  goto 32
	expression  goto 93
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 52
	id : id . arrayoplist
	factor : id .  (83)

	LSB  shift 62
	.  reduce 83

	arrayoplist  goto 63
	arrayopele  goto 64


state 53
	single : single . PPLUS
	single : single . MMINUS
	single : NOT single .  (80)

	.  reduce 80


state 54
	factor : LPAREN expression . RPAREN

	RPAREN  shift 94


state 55
	single : PPLUS single .  (79)
	single : single . PPLUS
	single : single . MMINUS

	MMINUS  shift 85
	.  reduce 79


state 56
	single : single . PPLUS
	single : single . MMINUS
	single : MMINUS single .  (78)

	.  reduce 78


state 57
	io_stmt : io_type LPAREN . expression RPAREN SEMICOLON

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 95
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 58
	var : ID .  (24)
	var : ID . arraylist

	LSB  shift 96
	.  reduce 24

	arraylist  goto 97
	arrayele  goto 98


state 59
	varlist : var .  (19)
	var_declaration : type_specifier var . ASSIGN expression SEMICOLON

	ASSIGN  shift 99
	.  reduce 19


state 60
	varlist : varlist . COMMA var
	var_declaration : type_specifier varlist . SEMICOLON

	SEMICOLON  shift 100
	COMMA  shift 101


state 61
	expression : id ASSIGN . expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 102
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 62
	arrayopele : LSB . expression RSB

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 103
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


63: shift-reduce conflict (shift 62, reduce 29) on LSB
state 63
	arrayoplist : arrayoplist . arrayopele
	id : id arrayoplist .  (29)

	LSB  shift 62
	.  reduce 29

	arrayopele  goto 104


state 64
	arrayoplist : arrayopele .  (31)

	.  reduce 31


state 65
	expression_stmt : expression SEMICOLON .  (12)

	.  reduce 12


state 66
	lxor_expression : lxor_expression LXOR . land_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	com_expression  goto 36
	normal_expression  goto 38
	land_expression  goto 105
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 67
	and_expression : and_expression AND . lor_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	lxor_expression  goto 34
	com_expression  goto 36
	normal_expression  goto 38
	lor_expression  goto 106
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 68
	com_expression : com_expression EQ . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 107
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 69
	com_expression : com_expression LT . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 108
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 70
	com_expression : com_expression LE . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 109
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 71
	com_expression : com_expression GT . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 110
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 72
	com_expression : com_expression GE . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 111
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 73
	com_expression : com_expression NE . normal_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	normal_expression  goto 112
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 74
	or_expression : or_expression OR . and_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	lxor_expression  goto 34
	and_expression  goto 113
	com_expression  goto 36
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 75
	normal_expression : normal_expression LS . plusminus_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	plusminus_expression  goto 114
	term  goto 42
	single  goto 43
	factor  goto 44


state 76
	normal_expression : normal_expression RS . plusminus_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	plusminus_expression  goto 115
	term  goto 42
	single  goto 43
	factor  goto 44


state 77
	lor_expression : lor_expression LOR . lxor_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	lxor_expression  goto 116
	com_expression  goto 36
	normal_expression  goto 38
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 78
	land_expression : land_expression LAND . com_expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	com_expression  goto 117
	normal_expression  goto 38
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 79
	plusminus_expression : plusminus_expression PLUS . term

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	term  goto 118
	single  goto 43
	factor  goto 44


state 80
	plusminus_expression : plusminus_expression MINUS . term

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 52
	term  goto 119
	single  goto 43
	factor  goto 44


state 81
	term : term MUL . factor

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	LPAREN  shift 21

	id  goto 52
	factor  goto 120


state 82
	term : term DIV . factor

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	LPAREN  shift 21

	id  goto 52
	factor  goto 121


state 83
	term : term MOD . factor

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	LPAREN  shift 21

	id  goto 52
	factor  goto 122


state 84
	single : single PPLUS .  (76)

	.  reduce 76


state 85
	single : single MMINUS .  (77)

	.  reduce 77


state 86
	compound_stmt : LBRACE statement_list RBRACE .  (2)

	.  reduce 2


state 87
	statement_list : statement_list statement .  (3)

	.  reduce 3


state 88
	selection_stmt : IF LPAREN expression . RPAREN statement
	selection_stmt : IF LPAREN expression . RPAREN statement ELSE statement

	RPAREN  shift 123


state 89
	while_stmt : WHILE LPAREN expression . RPAREN statement

	RPAREN  shift 124


state 90
	for_stmt : FOR LPAREN SEMICOLON . expression SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON . expression SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON . SEMICOLON RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 125
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 126
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 91
	for_stmt : FOR LPAREN firstexpr . SEMICOLON expression SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr . SEMICOLON SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN firstexpr . SEMICOLON SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr . SEMICOLON expression SEMICOLON RPAREN statement

	SEMICOLON  shift 127


state 92
	firstexpr : type_specifier . id ASSIGN expression

	ID  shift 15

	id  goto 128


state 93
	firstexpr : expression .  (42)

	.  reduce 42


state 94
	factor : LPAREN expression RPAREN .  (82)

	.  reduce 82


state 95
	io_stmt : io_type LPAREN expression . RPAREN SEMICOLON

	RPAREN  shift 129


state 96
	arrayele : LSB . INTNUM RSB

	INTNUM  shift 130


state 97
	arraylist : arraylist . arrayele
	var : ID arraylist .  (23)

	LSB  shift 96
	.  reduce 23

	arrayele  goto 131


state 98
	arraylist : arrayele .  (26)

	.  reduce 26


state 99
	var_declaration : type_specifier var ASSIGN . expression SEMICOLON

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 132
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 100
	var_declaration : type_specifier varlist SEMICOLON .  (16)

	.  reduce 16


state 101
	varlist : varlist COMMA . var

	ID  shift 58

	var  goto 133


state 102
	expression : id ASSIGN expression .  (47)

	.  reduce 47


state 103
	arrayopele : LSB expression . RSB

	RSB  shift 134


state 104
	arrayoplist : arrayoplist arrayopele .  (30)

	.  reduce 30


state 105
	lxor_expression : lxor_expression LXOR land_expression .  (55)
	land_expression : land_expression . LAND com_expression

	LAND  shift 78
	.  reduce 55


state 106
	lor_expression : lor_expression . LOR lxor_expression
	and_expression : and_expression AND lor_expression .  (51)

	LOR  shift 77
	.  reduce 51


state 107
	com_expression : com_expression EQ normal_expression .  (59)
	normal_expression : normal_expression . RS plusminus_expression
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 59


state 108
	com_expression : com_expression LT normal_expression .  (60)
	normal_expression : normal_expression . RS plusminus_expression
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 60


state 109
	normal_expression : normal_expression . RS plusminus_expression
	com_expression : com_expression LE normal_expression .  (62)
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 62


state 110
	com_expression : com_expression GT normal_expression .  (61)
	normal_expression : normal_expression . RS plusminus_expression
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 61


state 111
	com_expression : com_expression GE normal_expression .  (63)
	normal_expression : normal_expression . RS plusminus_expression
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 63


state 112
	normal_expression : normal_expression . RS plusminus_expression
	com_expression : com_expression NE normal_expression .  (64)
	normal_expression : normal_expression . LS plusminus_expression

	LS  shift 75
	RS  shift 76
	.  reduce 64


state 113
	or_expression : or_expression OR and_expression .  (49)
	and_expression : and_expression . AND lor_expression

	AND  shift 67
	.  reduce 49


state 114
	plusminus_expression : plusminus_expression . MINUS term
	plusminus_expression : plusminus_expression . PLUS term
	normal_expression : normal_expression LS plusminus_expression .  (66)

	PLUS  shift 79
	MINUS  shift 80
	.  reduce 66


state 115
	normal_expression : normal_expression RS plusminus_expression .  (67)
	plusminus_expression : plusminus_expression . MINUS term
	plusminus_expression : plusminus_expression . PLUS term

	PLUS  shift 79
	MINUS  shift 80
	.  reduce 67


state 116
	lor_expression : lor_expression LOR lxor_expression .  (53)
	lxor_expression : lxor_expression . LXOR land_expression

	LXOR  shift 66
	.  reduce 53


state 117
	land_expression : land_expression LAND com_expression .  (57)
	com_expression : com_expression . LT normal_expression
	com_expression : com_expression . GT normal_expression
	com_expression : com_expression . EQ normal_expression
	com_expression : com_expression . GE normal_expression
	com_expression : com_expression . LE normal_expression
	com_expression : com_expression . NE normal_expression

	EQ  shift 68
	LT  shift 69
	LE  shift 70
	GT  shift 71
	GE  shift 72
	NE  shift 73
	.  reduce 57


state 118
	term : term . DIV factor
	plusminus_expression : plusminus_expression PLUS term .  (69)
	term : term . MUL factor
	term : term . MOD factor

	MUL  shift 81
	DIV  shift 82
	MOD  shift 83
	.  reduce 69


state 119
	term : term . DIV factor
	plusminus_expression : plusminus_expression MINUS term .  (70)
	term : term . MUL factor
	term : term . MOD factor

	MUL  shift 81
	DIV  shift 82
	MOD  shift 83
	.  reduce 70


state 120
	term : term MUL factor .  (72)

	.  reduce 72


state 121
	term : term DIV factor .  (73)

	.  reduce 73


state 122
	term : term MOD factor .  (74)

	.  reduce 74


state 123
	selection_stmt : IF LPAREN expression RPAREN . statement
	selection_stmt : IF LPAREN expression RPAREN . statement ELSE statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 135
	expression_stmt  goto 48


state 124
	while_stmt : WHILE LPAREN expression RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 136
	expression_stmt  goto 48


state 125
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . expression RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON . RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	RPAREN  shift 137
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 138
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 126
	for_stmt : FOR LPAREN SEMICOLON expression . SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON expression . SEMICOLON RPAREN statement

	SEMICOLON  shift 139


state 127
	for_stmt : FOR LPAREN firstexpr SEMICOLON . expression SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON . SEMICOLON RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON . SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON . expression SEMICOLON RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 140
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 141
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 128
	firstexpr : type_specifier id . ASSIGN expression
	id : id . arrayoplist

	ASSIGN  shift 142
	LSB  shift 62

	arrayoplist  goto 63
	arrayopele  goto 64


state 129
	io_stmt : io_type LPAREN expression RPAREN . SEMICOLON

	SEMICOLON  shift 143


state 130
	arrayele : LSB INTNUM . RSB

	RSB  shift 144


state 131
	arraylist : arraylist arrayele .  (25)

	.  reduce 25


state 132
	var_declaration : type_specifier var ASSIGN expression . SEMICOLON

	SEMICOLON  shift 145


state 133
	varlist : varlist COMMA var .  (18)

	.  reduce 18


state 134
	arrayopele : LSB expression RSB .  (32)

	.  reduce 32


state 135
	selection_stmt : IF LPAREN expression RPAREN statement .  (14)
	selection_stmt : IF LPAREN expression RPAREN statement . ELSE statement

	ELSE  shift 146
	.  reduce 14


state 136
	while_stmt : WHILE LPAREN expression RPAREN statement .  (33)

	.  reduce 33


state 137
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 147
	expression_stmt  goto 48


state 138
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expression . RPAREN statement

	RPAREN  shift 148


state 139
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON . expression RPAREN statement
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON . RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	RPAREN  shift 149
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 150
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 140
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON . RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON . expression RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	RPAREN  shift 151
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 152
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 141
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression . SEMICOLON expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression . SEMICOLON RPAREN statement

	SEMICOLON  shift 153


state 142
	firstexpr : type_specifier id ASSIGN . expression

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 154
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 143
	io_stmt : io_type LPAREN expression RPAREN SEMICOLON .  (44)

	.  reduce 44


state 144
	arrayele : LSB INTNUM RSB .  (27)

	.  reduce 27


state 145
	var_declaration : type_specifier var ASSIGN expression SEMICOLON .  (17)

	.  reduce 17


state 146
	selection_stmt : IF LPAREN expression RPAREN statement ELSE . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 155
	expression_stmt  goto 48


state 147
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON RPAREN statement .  (41)

	.  reduce 41


state 148
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expression RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 156
	expression_stmt  goto 48


state 149
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 157
	expression_stmt  goto 48


state 150
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON expression . RPAREN statement

	RPAREN  shift 158


state 151
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 159
	expression_stmt  goto 48


state 152
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON expression . RPAREN statement

	RPAREN  shift 160


state 153
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON . expression RPAREN statement
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON . RPAREN statement

	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	RPAREN  shift 161
	PPLUS  shift 23
	MMINUS  shift 24

	id  goto 32
	expression  goto 162
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44


state 154
	firstexpr : type_specifier id ASSIGN expression .  (43)

	.  reduce 43


state 155
	selection_stmt : IF LPAREN expression RPAREN statement ELSE statement .  (15)

	.  reduce 15


state 156
	for_stmt : FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement .  (38)

	.  reduce 38


state 157
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement .  (39)

	.  reduce 39


state 158
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 163
	expression_stmt  goto 48


state 159
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON RPAREN statement .  (40)

	.  reduce 40


state 160
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 164
	expression_stmt  goto 48


state 161
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 165
	expression_stmt  goto 48


state 162
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression . RPAREN statement

	RPAREN  shift 166


state 163
	for_stmt : FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement .  (35)

	.  reduce 35


state 164
	for_stmt : FOR LPAREN firstexpr SEMICOLON SEMICOLON expression RPAREN statement .  (36)

	.  reduce 36


state 165
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON RPAREN statement .  (37)

	.  reduce 37


state 166
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN . statement

	INT  shift 7
	CHAR  shift 8
	FLOAT  shift 9
	IF  shift 10
	WHILE  shift 11
	INPUT  shift 12
	OUTPUT  shift 13
	FOR  shift 14
	ID  shift 15
	CONSTCHAR  shift 16
	INTNUM  shift 17
	FLOATNUM  shift 18
	HELPCHAR  shift 19
	NOT  shift 20
	LPAREN  shift 21
	SEMICOLON  shift 22
	LBRACE  shift 5
	PPLUS  shift 23
	MMINUS  shift 24

	io_type  goto 25
	io_stmt  goto 26
	for_stmt  goto 27
	while_stmt  goto 28
	selection_stmt  goto 29
	var_declaration  goto 30
	type_specifier  goto 31
	id  goto 32
	expression  goto 33
	lxor_expression  goto 34
	and_expression  goto 35
	com_expression  goto 36
	or_expression  goto 37
	normal_expression  goto 38
	lor_expression  goto 39
	land_expression  goto 40
	plusminus_expression  goto 41
	term  goto 42
	single  goto 43
	factor  goto 44
	compound_stmt  goto 45
	statement  goto 167
	expression_stmt  goto 48


state 167
	for_stmt : FOR LPAREN firstexpr SEMICOLON expression SEMICOLON expression RPAREN statement .  (34)

	.  reduce 34


##############################################################################
# Summary
##############################################################################

State 63 contains 1 shift-reduce conflict(s)


48 token(s), 33 nonterminal(s)
88 grammar rule(s), 168 state(s)


##############################################################################
# End of File
##############################################################################
