	.586
	.model flat, stdcall
	option casemap :none

	include D:\masm32\include\msvcrt.inc
	include D:\masm32\include\kernel32.inc
	include D:\masm32\include\masm32.inc

	includelib D:\masm32\lib\msvcrt.lib
	includelib D:\masm32\lib\kernel32.lib
	includelib D:\masm32\lib\masm32.lib


	.data
		_a DWORD 0
		_b DWORD 0
		_c DWORD 0
		_d DWORD 0
		_a1 DWORD 0
		_h DWORD 0
		t0 DWORD 0
		t1 DWORD 0
		t2 DWORD 0
		t3 DWORD 0
		t4 DWORD 0
		t5 DWORD 0
		t6 DWORD 0
		t7 DWORD 0
		t8 DWORD 0
		t9 DWORD 0
		t10 DWORD 0
		t11 DWORD 0
		t12 DWORD 0
		t13 DWORD 0
		t14 DWORD 0
		 ctemp BYTE 0
		 type0 db '%d', 0
		 type1 db '%c', 0
		 type2 db '%s', 0
		 typen db 0dh,0ah, 0
		 typet db 09h, 0

	.code

_start:
L0:
	MOV eax, 0
	MOV _a, eax
	jmp L2
L3:
	MOV eax,1
	MOV ecx,_a
	MOV t0,ecx
	ADD eax,_a
	MOV _a,eax
L2:	MOV eax, _a
	CMP eax, 5
	jl L4
	jmp L1
L4:	invoke crt_printf,addr typet
L5:
	MOV eax, 0
	MOV _b, eax
	jmp L7
L8:
	MOV eax,1
	MOV ecx,_b
	MOV t2,ecx
	ADD eax,_b
	MOV _b,eax
L7:	MOV eax, 4
	SUB eax, _a
	MOV t1, eax
	MOV eax, _b
	CMP eax, t1
	jl L9
	jmp L6
L9:	invoke crt_printf,addr type1,' '
	jmp L8
L6:
	MOV eax, 0
	MOV _c, eax
	jmp L11
L12:
	MOV eax,1
	MOV ecx,_c
	MOV t4,ecx
	ADD eax,_c
	MOV _c,eax
L11:	MOV eax, 2
	MUL _a
	MOV t3, eax
	MOV eax, t3
	ADD eax, 1
	MOV t3, eax
	MOV eax, _c
	CMP eax, t3
	jl L13
	jmp L10
L13:	invoke crt_printf,addr type1,'*'
	jmp L12
L10:
	MOV eax, 0
	MOV _b, eax
	jmp L15
L16:
	MOV eax,1
	MOV ecx,_b
	MOV t6,ecx
	ADD eax,_b
	MOV _b,eax
L15:	MOV eax, 4
	SUB eax, _a
	MOV t5, eax
	MOV eax, _b
	CMP eax, t5
	jl L17
	jmp L14
L17:	invoke crt_printf,addr type1,' '
	jmp L16
L14:	invoke crt_printf,addr typen
	jmp L3
L1:
	MOV eax, 1
	MOV _a1, eax
	jmp L19
L20:
	MOV eax,1
	MOV ecx,_a1
	MOV t7,ecx
	ADD eax,_a1
	MOV _a1,eax
L19:	MOV eax, _a1
	CMP eax, 5
	jl L21
	jmp L18
L21:	invoke crt_printf,addr typet
L22:
	MOV eax, 0
	MOV _b, eax
	jmp L24
L25:
	MOV eax,1
	MOV ecx,_b
	MOV t9,ecx
	ADD eax,_b
	MOV _b,eax
L24:	MOV eax, 4
	SUB eax, _a1
	MOV t8, eax
	MOV eax, _b
	CMP eax, t8
	jl L26
	jmp L23
L26:	invoke crt_printf,addr type1,' '
	jmp L25
L23:
	MOV eax, 0
	MOV _c, eax
	jmp L28
L29:
	MOV eax,1
	MOV ecx,_c
	MOV t11,ecx
	ADD eax,_c
	MOV _c,eax
L28:	MOV eax, 2
	MUL _a1
	MOV t10, eax
	MOV eax, t10
	ADD eax, 1
	MOV t10, eax
	MOV eax, _c
	CMP eax, t10
	jl L30
	jmp L27
L30:	invoke crt_printf,addr type1,'*'
	jmp L29
L27:
	MOV eax, 0
	MOV _b, eax
	jmp L32
L33:
	MOV eax,1
	MOV ecx,_b
	MOV t13,ecx
	ADD eax,_b
	MOV _b,eax
L32:	MOV eax, 4
	SUB eax, _a1
	MOV t12, eax
	MOV eax, _b
	CMP eax, t12
	jl L34
	jmp L31
L34:	invoke crt_printf,addr type1,' '
	jmp L33
L31:	invoke crt_printf,addr typen
	jmp L20
L18:
	MOV eax,0
	MOV _h, eax
	jmp L36
L37:
	MOV eax,1
	MOV ecx,_h
	MOV t14,ecx
	ADD eax,_h
	MOV _h,eax
L36:	MOV eax, _h
	CMP eax, 3
	jl L38
	jmp L35
L38:	invoke crt_printf,addr typet
	invoke crt_printf,addr type1,' '
	invoke crt_printf,addr type1,' '
	invoke crt_printf,addr type1,' '
	invoke crt_printf,addr type1,'*'
	invoke crt_printf,addr type1,'*'
	invoke crt_printf,addr type1,'*'
	invoke crt_printf,addr typen
	jmp L37
L35:	invoke crt_scanf,addr type0,addr _d
	invoke ExitProcess, 0
end _start
