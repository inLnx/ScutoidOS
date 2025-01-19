mov ah, 0x0e ; switches OS into teletype (TTY)
mov al, 'S' ; Prints S
int 0x10 ; S will stay in in al after the interrupt,
; to change it run it again with a different letter
jmp $

times 510-($-$$) db 0
db 0x55, 0xaa