# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <argtable2.h> // install from http://argtable.sourceforge.net/

# include "argparse.h"
# include "messages.h"

struct Args parse_arguments(int argc, char *argv[]) {

    struct Args args;
    args.mass = 0.1;
    args.diam = 0.042;
    args.cd =   0.8;
    args.wind = 0.0;
    args.run_simulation = 0;

    // Simulation options
    struct arg_dbl *mass = arg_dbl1("m", "mass", "<float>",
            "Mass of rocket without motor (g)");
    struct arg_dbl *diam = arg_dbl1("d", "diam", "<float>",
            "Diameter of rocket (mm)");
    struct arg_dbl *cd = arg_dbl1("c", "cd", "<float>",
            "Drag coefficient of rocket");
    struct arg_dbl *wind = arg_dbl1("w", "wind", "<float>",
            "Wind speed (km/h)");
    struct arg_str *motor = arg_str1("M", "motor", "<str>",
            "Motor (use '-l' or '--list_motors' to see list");

    // Help options
    struct arg_lit *help = arg_lit0("h", "help", "Printing help");
    struct arg_lit *list_motors = arg_lit0("l", "list_motors", "List motors");
    struct arg_end *end = arg_end(20);

    // Prepare argtable
    void *argtable[] = {mass, diam, cd, wind, motor, help, list_motors, end};
    const char *progname = "lawn_dart";
    int nerrors;
    int exitcode=0;

    // Verify the argtable[] entries were allocated sucessfully
    if (arg_nullcheck(argtable) != 0) {
        // NULL entries were detected, some allocations must have failed
        printf("%s: insufficient memory\n",progname);
        exitcode=1;
    }

    // Parse the command line as defined by argtable[]
    nerrors = arg_parse(argc, argv, argtable);

    // Check for --help
    if (help->count > 0 || argc == 1) { // TODO or if there are no arguments
        printf("Lawn Dart: A Model Rocket Flight Simulator\n\n");
        printf("%s", progname);
        arg_print_syntax(stdout, argtable,"\n");
        puts("");
        arg_print_glossary(stdout, argtable,"  %-25s %s\n");
        puts("");
        print_help();
    }
    else if (list_motors->count > 0) {
        print_motor_list();
    }
    else {
        printf("%lf, %lf, %lf, %lf, %s\n",
            mass->dval[0], diam->dval[0], cd->dval[0], wind->dval[0], motor->sval[0]);
        args.run_simulation = 0;
    }

    return args;
}

/*
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
*/

