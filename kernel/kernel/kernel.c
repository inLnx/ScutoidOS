#include <stdio.h>
#include "stdio.c"
#include "../include/kernel/tty.h"

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
}
