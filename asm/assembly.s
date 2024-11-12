section  .text
 global _start  ;something about linker (ld)

 _start:  ; linker entry point
  mov edx,len ;length into edx register
  move ecx,msg ;moves message into the ecx register
  move ebx,1 ;moves one into ebx (stdout file descriptor)
  mov eax,4 ;moves 4 into eax (system call number for sys write)
  int 0x80 ; call kernel
  mov eax,1 ; system call number for (sys exit)
  int 0x80 ; call kernel again
  section  .data ; holds the main data
  msg db "ASM text"