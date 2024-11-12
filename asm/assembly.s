SECTION .data
msg db 'Hello', 0Ah ;this appears to be a variable name
SECTION .text
global _start
_start:

mov edx, 13
move ecx, 0Ah
mov ebx, 1
mov eax, 4
int 80h
