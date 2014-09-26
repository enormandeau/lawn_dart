// Speed: V = Vo + (a*dt)/2
double new_speed(double initial_speed, double acceleration, double delta_t);

// F = m*a --> a = F/m
double acceleration(double force, double mass, double altitude);

// D = f(diameter, CD, speed)
double drag(double cd, double rho, double speed, double surface);

// G = f(altitude)
double gravity(double altitude);

// Simulation
void simulation(
        double mass,
        double diam,
        double cd,
        double wind,
        double altitude);

