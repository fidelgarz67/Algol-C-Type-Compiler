%include "io64.inc" 
	common x 8 		 ;defined global variable
	common count 8 		 ;defined global variable
section .data

section .text

	 global main
main: 
	 mov rbp, rsp 		 ;Create SP and BP for Main method
	 mov r8, rsp 		 ;Function header SP to be at most BP
	 add r8, -24, 		 ;Get a chunk of mem. for the AR 
	 mov [r8], rbp 		 ;Function header stores the old BP
	 mov [r8+8], rsp 		 ;Function header stores the old SP
	 mov rsp, r8 		 ;Function header's new SP

	 mov rbx, 3 		 ;Array Number
	 mov rax, x 		 ;Move variable name into rax
	 mov [rax], rbx 		 ;Move rbx into mem. of rax (assign value)	 mov rax, 5 		 ;Array Number
	 mov [rsp + 16], rax 		 ;Move rax into SP + offset
	 mov rbx, 5 		 ;Array Number
	 mov rax, [rsp + 16] 		 ;Move the SP + offset into rax
	 cmp rax, rbx 		 ;Compare rax and rbx
	 setge al 		 ;Set al greater than or equal
	 mov rbx, 1 		 ;Move 1 into rbx
	 and rax, rbx 		 ;Add both rax and rbx
	 mov [rsp + 16], rax 		 ;Move rax into SP +offset
	 mov rsi, [rsp + 16] 		 ;Writing and Expression
	 PRINT_DEC 8, rsi		 ;Writing in a value
	 NEWLINE

	 mov rbp, [rsp] 		 ;Function restores the offset
	 mov rsp, [rsp+8] 		 ;Function restores the SP
	 mov rsp, rbp 		 ;Sets the SP and offset to be the same
	 xor rax, rax
	 ret

