# 0x16. C - Simple Shell

## Description
A simple UNIX command line interpreter that implements basic shell functionality. This project is a milestone for understanding process creation, execution, and system calls in C.

## Requirements
* **OS:** Ubuntu 20.04 LTS
* **Compiler:** `gcc` using flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Style:** All code follows the Betty style.

## Compilation
To compile the shell, use:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
```

## Authors
* Bothaina Albedah
* Osama Alhamdan