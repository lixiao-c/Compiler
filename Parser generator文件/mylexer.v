#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 77 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 01/01/18
# Time: 22:02:19
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [/][/].*[\n]

    2  [/][*](["].*["]|[^*/]*|[*]+[^/]|[/]*)*[*]?[*][/]

    3  "["

    4  "]"

    5  "if"

    6  "else"

    7  "while"

    8  "for"

    9  "int"

   10  "char"

   11  "float"

   12  "bool"

   13  "true"

   14  "false"

   15  "input"

   16  "output"

   17  "main"

   18  ['].[']

   19  [$][n|t]

   20  "++"

   21  "--"

   22  "=="

   23  "<="

   24  ">="

   25  "!="

   26  "="

   27  "<<"

   28  ">>"

   29  "<"

   30  ">"

   31  "+"

   32  "-"

   33  "*"

   34  "/"

   35  "%"

   36  ";"

   37  ","

   38  "("

   39  ")"

   40  "{"

   41  "}"

   42  "||"

   43  "&&"

   44  "!"

   45  "&"

   46  "|"

   47  "^"

   48  [0123456789]+

   49  [0123456789][\.][0123456789]+

   50  [a-zA-Z][a-zA-Z0-9]*

   51  [\n]

   52  [ \t]

   53  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x23 (2)    goto 3
	0x24               goto 7
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2e               goto 3
	0x2f               goto 17
	0x30 - 0x39 (10)   goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x5a (26)   goto 23
	0x5b               goto 24
	0x5c               goto 3
	0x5d               goto 25
	0x5e               goto 26
	0x5f - 0x60 (2)    goto 3
	0x61               goto 23
	0x62               goto 27
	0x63               goto 28
	0x64               goto 23
	0x65               goto 29
	0x66               goto 30
	0x67 - 0x68 (2)    goto 23
	0x69               goto 31
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 32
	0x6e               goto 23
	0x6f               goto 33
	0x70 - 0x73 (4)    goto 23
	0x74               goto 34
	0x75 - 0x76 (2)    goto 23
	0x77               goto 35
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 36
	0x7c               goto 37
	0x7d               goto 38
	0x7e - 0xff (130)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x23 (2)    goto 3
	0x24               goto 7
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2e               goto 3
	0x2f               goto 17
	0x30 - 0x39 (10)   goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x5a (26)   goto 23
	0x5b               goto 24
	0x5c               goto 3
	0x5d               goto 25
	0x5e               goto 26
	0x5f - 0x60 (2)    goto 3
	0x61               goto 23
	0x62               goto 27
	0x63               goto 28
	0x64               goto 23
	0x65               goto 29
	0x66               goto 30
	0x67 - 0x68 (2)    goto 23
	0x69               goto 31
	0x6a - 0x6c (3)    goto 23
	0x6d               goto 32
	0x6e               goto 23
	0x6f               goto 33
	0x70 - 0x73 (4)    goto 23
	0x74               goto 34
	0x75 - 0x76 (2)    goto 23
	0x77               goto 35
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 36
	0x7c               goto 37
	0x7d               goto 38
	0x7e - 0xff (130)  goto 3


state 3
	match 53


state 4
	match 52


state 5
	match 51


state 6
	0x3d               goto 39

	match 44


state 7
	0x6e               goto 40
	0x74               goto 40
	0x7c               goto 40

	match 53


state 8
	match 35


state 9
	0x26               goto 41

	match 45


state 10
	0x00 - 0x09 (10)   goto 42
	0x0b - 0xff (245)  goto 42

	match 53


state 11
	match 38


state 12
	match 39


state 13
	match 33


state 14
	0x2b               goto 43

	match 31


state 15
	match 37


state 16
	0x2d               goto 44

	match 32


state 17
	0x2a               goto 45
	0x2f               goto 46

	match 34


state 18
	0x2e               goto 47
	0x30 - 0x39 (10)   goto 48

	match 48


state 19
	match 36


state 20
	0x3c               goto 49
	0x3d               goto 50

	match 29


state 21
	0x3d               goto 51

	match 26


state 22
	0x3d               goto 52
	0x3e               goto 53

	match 30


state 23
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 50


state 24
	match 3


state 25
	match 4


state 26
	match 47


state 27
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 54
	0x70 - 0x7a (11)   goto 23

	match 50


state 28
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 55
	0x69 - 0x7a (18)   goto 23

	match 50


state 29
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 56
	0x6d - 0x7a (14)   goto 23

	match 50


state 30
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61               goto 57
	0x62 - 0x6b (10)   goto 23
	0x6c               goto 58
	0x6d - 0x6e (2)    goto 23
	0x6f               goto 59
	0x70 - 0x7a (11)   goto 23

	match 50


state 31
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x65 (5)    goto 23
	0x66               goto 60
	0x67 - 0x6d (7)    goto 23
	0x6e               goto 61
	0x6f - 0x7a (12)   goto 23

	match 50


state 32
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61               goto 62
	0x62 - 0x7a (25)   goto 23

	match 50


state 33
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 63
	0x76 - 0x7a (5)    goto 23

	match 50


state 34
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 64
	0x73 - 0x7a (8)    goto 23

	match 50


state 35
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 65
	0x69 - 0x7a (18)   goto 23

	match 50


state 36
	match 40


state 37
	0x7c               goto 66

	match 46


state 38
	match 41


state 39
	match 25


state 40
	match 19


state 41
	match 43


state 42
	0x27               goto 67


state 43
	match 20


state 44
	match 21


state 45
	0x00 - 0x21 (34)   goto 45
	0x22               goto 68
	0x23 - 0x29 (7)    goto 45
	0x2a               goto 69
	0x2b - 0x2e (4)    goto 45
	0x2f               goto 45
	0x30 - 0xff (208)  goto 45


state 46
	0x00 - 0x09 (10)   goto 46
	0x0a               goto 70
	0x0b - 0xff (245)  goto 46


state 47
	0x30 - 0x39 (10)   goto 71


state 48
	0x30 - 0x39 (10)   goto 48

	match 48


state 49
	match 27


state 50
	match 23


state 51
	match 22


state 52
	match 24


state 53
	match 28


state 54
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 72
	0x70 - 0x7a (11)   goto 23

	match 50


state 55
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61               goto 73
	0x62 - 0x7a (25)   goto 23

	match 50


state 56
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x72 (18)   goto 23
	0x73               goto 74
	0x74 - 0x7a (7)    goto 23

	match 50


state 57
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 75
	0x6d - 0x7a (14)   goto 23

	match 50


state 58
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 76
	0x70 - 0x7a (11)   goto 23

	match 50


state 59
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 77
	0x73 - 0x7a (8)    goto 23

	match 50


state 60
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 5


state 61
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6f (15)   goto 23
	0x70               goto 78
	0x71 - 0x73 (3)    goto 23
	0x74               goto 79
	0x75 - 0x7a (6)    goto 23

	match 50


state 62
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 80
	0x6a - 0x7a (17)   goto 23

	match 50


state 63
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 81
	0x75 - 0x7a (6)    goto 23

	match 50


state 64
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 82
	0x76 - 0x7a (5)    goto 23

	match 50


state 65
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 83
	0x6a - 0x7a (17)   goto 23

	match 50


state 66
	match 42


state 67
	match 18


state 68
	0x00 - 0x09 (10)   goto 68
	0x0a               goto 45
	0x0b - 0x21 (23)   goto 68
	0x22               goto 68
	0x23 - 0x29 (7)    goto 68
	0x2a               goto 84
	0x2b - 0x2e (4)    goto 68
	0x2f               goto 68
	0x30 - 0xff (208)  goto 68


state 69
	0x00 - 0x29 (42)   goto 45
	0x2a               goto 85
	0x2b - 0x2e (4)    goto 45
	0x2f               goto 86
	0x30 - 0xff (208)  goto 45


state 70
	match 1


state 71
	0x30 - 0x39 (10)   goto 71

	match 49


state 72
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 87
	0x6d - 0x7a (14)   goto 23

	match 50


state 73
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 88
	0x73 - 0x7a (8)    goto 23

	match 50


state 74
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 89
	0x66 - 0x7a (21)   goto 23

	match 50


state 75
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x72 (18)   goto 23
	0x73               goto 90
	0x74 - 0x7a (7)    goto 23

	match 50


state 76
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61               goto 91
	0x62 - 0x7a (25)   goto 23

	match 50


state 77
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 8


state 78
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 92
	0x76 - 0x7a (5)    goto 23

	match 50


state 79
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 9


state 80
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6d (13)   goto 23
	0x6e               goto 93
	0x6f - 0x7a (12)   goto 23

	match 50


state 81
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6f (15)   goto 23
	0x70               goto 94
	0x71 - 0x7a (10)   goto 23

	match 50


state 82
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 95
	0x66 - 0x7a (21)   goto 23

	match 50


state 83
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 96
	0x6d - 0x7a (14)   goto 23

	match 50


state 84
	0x00 - 0x09 (10)   goto 68
	0x0a               goto 45
	0x0b - 0x21 (23)   goto 68
	0x22               goto 68
	0x23 - 0x29 (7)    goto 68
	0x2a               goto 97
	0x2b - 0x2e (4)    goto 68
	0x2f               goto 98
	0x30 - 0xff (208)  goto 68


state 85
	0x00 - 0x21 (34)   goto 45
	0x22               goto 68
	0x23 - 0x29 (7)    goto 45
	0x2a               goto 85
	0x2b - 0x2e (4)    goto 45
	0x2f               goto 99
	0x30 - 0xff (208)  goto 45


state 86
	match 2


state 87
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 12


state 88
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 10


state 89
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 6


state 90
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 100
	0x66 - 0x7a (21)   goto 23

	match 50


state 91
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 101
	0x75 - 0x7a (6)    goto 23

	match 50


state 92
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 102
	0x75 - 0x7a (6)    goto 23

	match 50


state 93
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 17


state 94
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 103
	0x76 - 0x7a (5)    goto 23

	match 50


state 95
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 13


state 96
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 104
	0x66 - 0x7a (21)   goto 23

	match 50


state 97
	0x00 - 0x09 (10)   goto 68
	0x0a               goto 45
	0x0b - 0x21 (23)   goto 68
	0x22               goto 68
	0x23 - 0x29 (7)    goto 68
	0x2a               goto 97
	0x2b - 0x2e (4)    goto 68
	0x2f               goto 105
	0x30 - 0xff (208)  goto 68


state 98
	0x00 - 0x09 (10)   goto 106
	0x0b - 0x21 (23)   goto 106
	0x22               goto 68
	0x23 - 0xff (221)  goto 106

	match 2


state 99
	0x00 - 0x21 (34)   goto 45
	0x22               goto 68
	0x23 - 0x29 (7)    goto 45
	0x2a               goto 69
	0x2b - 0x2e (4)    goto 45
	0x2f               goto 45
	0x30 - 0xff (208)  goto 45

	match 2


state 100
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 14


state 101
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 11


state 102
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 15


state 103
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 107
	0x75 - 0x7a (6)    goto 23

	match 50


state 104
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 7


state 105
	0x00 - 0x09 (10)   goto 68
	0x0a               goto 45
	0x0b - 0x21 (23)   goto 68
	0x22               goto 68
	0x23 - 0x29 (7)    goto 68
	0x2a               goto 84
	0x2b - 0x2e (4)    goto 68
	0x2f               goto 68
	0x30 - 0xff (208)  goto 68

	match 2


state 106
	0x00 - 0x09 (10)   goto 106
	0x0b - 0x21 (23)   goto 106
	0x22               goto 68
	0x23 - 0xff (221)  goto 106


state 107
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x61 - 0x7a (26)   goto 23

	match 16


#############################################################################
# Summary
#############################################################################

1 start state(s)
53 expression(s), 107 state(s)


#############################################################################
# End of File
#############################################################################
