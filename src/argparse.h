
struct Args parse_arguments(int argc, char *argv[]);

struct Args {
    double mass;
    double diam;
    double cd;
    double wind;
    int run_simulation;
    char motor[100];
};

