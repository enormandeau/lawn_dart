# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <argtable2.h> // install from http://argtable.sourceforge.net/

# include "argparse.h"
# include "messages.h"

struct Args parse_arguments(int argc, char *argv[]) {

    struct Args args;
    args.mass = 0.0;
    args.diam = 0.0;
    args.cd =   0.0;
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
    struct arg_str *motor = arg_str1("M", "motor", "<string>",
            "Motor (use '-l' or '--list_motors' to see list");

    // Help options
    struct arg_lit *help = arg_lit0("h", "help", "Printing help");
    struct arg_lit *list_motors = arg_lit0("l", "list_motors", "List motors");
    struct arg_end *end = arg_end(20);

    // Prepare argtable
    void *argtable[] = {mass, diam, cd, wind, motor, help, list_motors, end};
    const char *progname = "lawn_dart";
    int nerrors;

    // Verify the argtable[] entries were allocated sucessfully
    if (arg_nullcheck(argtable) != 0) {
        // NULL entries were detected, some allocations must have failed
        printf("%s: insufficient memory\n",progname);
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
        // If all required options have been specified
        if (!nerrors) {
            // Get options from params
            args.mass = mass->dval[0] / 1000.0;
            args.diam = diam->dval[0] / 1000.0;
            args.cd =   cd->dval[0];
            args.wind = wind->dval[0] / 3.6;

            // Assert proper values
            int all_params_ok = 1;
            if (args.mass < 0.001 || args.mass > 1000.0) all_params_ok = 0;
            if (args.diam < 0.001 || args.diam > 1.0) all_params_ok = 0;
            if (args.cd < 0.0 || args.cd > 1.0) all_params_ok = 0;
            if (args.wind < 0.0 || args.wind > 100.0) all_params_ok = 0;

            // Confirm to run simulation
            if (all_params_ok) {
                args.run_simulation = 1;
            }
        }
        else {
            puts("--- Missing required parameters ---\n");
            printf("%s", progname);
            arg_print_syntax(stdout, argtable,"\n");
            puts("");
            arg_print_glossary(stdout, argtable,"  %-25s %s\n");
            puts("");
            print_help();
        }
    }

    return args;
}

