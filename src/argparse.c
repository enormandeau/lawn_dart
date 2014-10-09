# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "argtable2.h"

# include "argparse.h"
# include "messages.h"

struct Args parse_arguments(int argc, char *argv[]) {
    // New argument parsing using argtable2
    struct Args args;
    args.mass = 0.1;
    args.diam = 0.042;
    args.cd =   0.8;
    args.wind = 0.0;
    args.run_simulation = 1;

    puts("inside new parse_arguments");

    // parse arguments
    struct arg_lit *list = arg_lit0("lL", "list", "list_files");

    // act based on arguments (-h, -l...)

    return args;
}

struct Args parse_arguments_old(int argc, char *argv[]) {
    struct Args args;
    args.mass = 0.0;
    args.diam = 0.0;
    args.cd =   0.0;
    args.wind = 0.0;
    args.run_simulation = 0;

    if (argc <= 4) {
        if (argc == 1) {
            print_help();
        }
        if (argc > 1) {
            if (strcmp(argv[1], "-l") == 0 ||
                    strcmp(argv[1], "--list_motors") == 0) {
                print_motor_list();
            }
            else {
                print_not_enough_parameters();
                print_help();
            }
        }
    }
    else if (argc > 5) {
        print_too_many_parameters();
        print_help();
    }
    else {
        args.mass =     atof(argv[1]) / 1000; // g -> Kg
        args.diam =     atof(argv[2]) / 1000; // mm -> m
        args.cd =       atof(argv[3]);        // unit less
        args.wind =     atof(argv[4]) / 3.6;  // km/h -> m/s
        args.run_simulation = 1;
    }

    return args;
}

