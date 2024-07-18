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
mov al, ' '
int 0x10
mov al, 'B'
int 0x10
mov al, 'E'
int 0x10
mov al, 'T'
int 0x10
mov al, 'A'
int 0x10
mov al, ' '
int 0x10
mov al, 'V'
int 0x10
mov al, 'E'
int 0x10
mov al, 'R'
int 0x10
mov al, 'S'
int 0x10
mov al, 'I'
int 0x10
mov al, 'O'
int 0x10
mov al, 'N'
int 0x10
mov al, '1'
int 0x10
msg   db 'Hello User', 13, 10, 0

; Infinite Loop
jmp $

; boot.asm
   mov ax, 0x07c0
   mov ds, ax

   mov si, msg
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
times 510-($-$$) db 0 ; apperently this is worth about 2 bytes

; Boot Signature
db 0x55
db 0xaa
