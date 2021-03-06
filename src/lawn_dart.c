# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "messages.h"
# include "argparse.h"
# include "physics.h"
# include "simulation.h"

# define delta_t 0.001

int main(int argc, char *argv[]) {
    struct Args args = parse_arguments(argc, argv);
    if (args.run_simulation) {
        simulation(args.mass, args.diam, args.cd, args.wind, delta_t);
    }

    return 0;
}

