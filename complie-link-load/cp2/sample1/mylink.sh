#!/bin/bash
ld -static /usr/lib/crt1.o /usr/lib/crti.o  /usr/lib/gcc-lib/i586-suse-linux/3.3.3/crtbeginT.o -L /usr/lib/gcc-lib/i586-suse-linux/3.3.3/ -L /usr/lib/ -L /lib/ hello.o --start-group -lgcc -lgcc_eh -lc --end-group /usr/lib/gcc-lib/i586-suse-linux/3.3.3/crtend.o /usr/lib/crtn.o
