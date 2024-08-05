; Print "SCUTOID BETA VERSION1"
mov ah, 0x0e
mov al, 'S'
int 0x10
mov al, 'C'
int 0x10
mov al, 'U'
int 0x10
mov al, 'T'
int 0x10
mov al, 'O'
int 0x10
mov al, 'I'
int 0x10
mov al, 'D'
int 0x10

mov al,'T'
int 0x10
mov al,'W'
int 0x10
mov al,'O'
int 0x10
char:
 db 0 
  mov ah, 0
   int 0x16
   mov al, [char]
buffer:
 times 10 db 0 
; Infinite Loop
jmp $

; boot.asm
   mov ax, 0x07c0
   mov ds, ax

   cld
ch_loop:lodsb
   or al, al ; zero=end of str
   jz hang   ; get out
   mov ah, 0x0E
   mov bh, 0
   int 0x10
   jmp ch_loop
   hang:
   jmp hang


; Fill Remaining Boot Sector with Zeros
times 1020-($-$$) db 0 ; apperently this is worth about 2 bytes

; Boot Signature
db 0x55
db 0xaa
