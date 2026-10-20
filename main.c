#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t collatz(size_t long_num) {
    /* Numbers are bloat, use binary */
    return ( long_num & 1 ) ? ((long_num << 1) + long_num ) + 1 : long_num >> 1;
}

size_t printer(size_t long_num, bool verbose) {
    size_t  steps = 0;

    /* perhaps there is a less ugly way? */
    if (verbose) {
        while ( long_num > 1 ) {
        long_num = collatz(long_num);
        printf("%zu\n", long_num);
        steps++;
        }
    }
    else {
        while ( long_num > 1 ) {
        long_num = collatz(long_num);
        steps++;
        }
    }

    return steps;
}

int print_help(char *argv[]) {
    fprintf(stderr,"Usage: %s <number> [-v]"
           "\n\n", argv[0]);
    return 1;
}

int main(int argc, char *argv[]) {
    if ( argc < 2 || argc > 3 )
        return print_help(argv);
    /* quit from the start */

    bool verbose = false;
    char *endptr;
    long  int_number = strtol(argv[1], &endptr, 10);

    /* check the number for nonsense */
    if (int_number <= 0 )
        return print_help(argv);
    if (*endptr != '\0' )
        return print_help(argv);
    if (argc >= 3 && argv[2][0] == '-' && argv[2][1] == 'v' && argv[2][2] == '\0')
        verbose = true;
    else if (argc >= 3 && argv[2][1] != 'v')
        return print_help(argv);

    size_t long_num = int_number;

    printf("%s took %zu steps\n", argv[1], printer(long_num, verbose));
    return 0;
}

