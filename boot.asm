mov ah, 0x0e
mov al, 'S'
int 0x10
mov ah, 0x0e
mov al, 'C'
int 0x10
mov ah, 0x0e
mov al, 'U'
int 0x10
mov ah, 0x0e
mov al, 'T'
int 0x10
mov ah, 0x0e
mov al, 'O'
int 0x10
mov ah, 0x0e
mov al, 'I'
int 0x10     
mov ah, 0x0e
mov al, 'D'
iny 0x10
label:
 db "Welcome to ScutoidOS beta!", 0
 [org ox7c00]
 mov ah, 0x0e
 mov al, [label]


  jmp $

times 510-($-$$) db 0
db 0x55, 0xaa