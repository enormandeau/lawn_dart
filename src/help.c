# include <stdio.h>

void help(void) {
    puts("\
    Lawn Dart: Model Rocket Flight Simulator\n\
    \n\
    Usage:\n\
        lawn_dart mass diam cd avgimp totimp wind duration\n\
    \n\
    mass = Mass of rocket in grams\n\
    diam = Diameter of body tube in millimeters\n\
    cd   = Coefficient of penetration (0.6 to 0.9)\n\
    avgimp (will disapear)\n\
    totimp (will disapear)\n\
    wind = Speed of wind in kilometers per hour\n\
    duration = Maximum duration of simulation\n");
}

