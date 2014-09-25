# include <stdio.h>
# include <stdlib.h>
# include "simulation.h"
# include "physics.h"
# include "help.h"

int main(int argc, char *argv[]) {
    int ret = 0;

    if (argc <= 7) {
        help();
        
        ret = 1;
    }
    else {
        // TODO
        // - Pass arvg[] directly to simulation?
        // - Create struct to hold arguments?
        double mass =     atof(argv[1]);
        double diam =     atof(argv[2]);
        double cd =       atof(argv[3]);
        double avgimp =   atof(argv[4]);
        double totimp =   atof(argv[5]);
        double wind =     atof(argv[6]);
        double duration = atof(argv[7]);

        simulation(mass, diam, cd, avgimp, totimp, wind, duration);
        ret = 0;
    }
    return ret;
}
