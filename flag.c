#include <string.h>
#include "flag.h"

char* progname;
PRINT_FLAG print_flag;
const char** flags;
size_t length;

int main(int argc, char* argv[]) {
    // initialize default values
    progname = argv[0];
    print_flag = flag;
    flags = FLAGS_JP;
    length = 0; // byte length limit for byte_flag(), 0 = unlimited

    if (argc > 1) {
        // handle arguments if any
        options(argc, argv);
    }

    // generate random number and print flag
    srandom(clock());
    unsigned count = random() % FLAGS_COUNT;
    print_flag(flags[count]);
    return EXIT_SUCCESS;
}

void flag(const char* heavy_words) {
    fprintf(stdout, "flag{%s}\n", heavy_words);
}

void byte_flag(const char* heavy_words) {
    fprintf(stdout, "flag{");
    size_t i = 0;
    size_t str_length = strlen(heavy_words);
    while (i < str_length && (length == 0 || i < length)) {
        fprintf(stdout, "%.2hhx", heavy_words[i++]);
    }
    while (i++ < length) {
        fprintf(stdout, "0f");
    }
    fprintf(stdout, "}\n");
}

void print_help(FILE* output) {
    fprintf(output, HELP_MSG, progname);
}

void print_invalid(int option, const char* arg) {
    if (option == 512) {
        fprintf(stderr, INVALID_MSG, progname, "--reserved", arg);
    } else {
        char opt[3] = "\0";
        opt[0] = '-';
        opt[1] = (char)option;
        fprintf(stderr, INVALID_MSG, progname, opt, arg);
    }
    print_help(stderr);
    exit(EXIT_FAILURE);
}

void options(int argc, char* argv[]) {
    int opt, index;
    char* endptr;
    while ((opt = getopt_long(argc, argv, "bl:h", OPTS, &index)) != -1) {
        switch (opt) {
            case 'b':
                // -b, --byte
                print_flag = byte_flag;
                // Check if optional argument is provided for "-b"
                if (argv[optind] && *argv[optind] != '-') {
                    length = strtoll(argv[optind], &endptr, 10);
                    if (*endptr != '\0') {
                        print_invalid(opt, argv[optind]);
                    }
                    optind++;
                }
                break;
            case 'l':
                // -l, --lang
                if (optarg != NULL) {
                    if (optarg[0] == 'j' || optarg[0] == 'J') {
                        flags = FLAGS_JP;
                        break;
                    } else if (optarg[0] == 'c' || optarg[0] == 'C') {
                        flags = FLAGS_CN;
                        break;
                    }
                }
                print_invalid(opt, argv[optind]);
                break;
            case 'h':
                // -h, --help
                print_help(stdout);
                exit(EXIT_SUCCESS);
            default:
                print_help(stderr);
                exit(EXIT_FAILURE);
        }
    }
}
