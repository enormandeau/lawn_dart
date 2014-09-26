// Initial speed (m/s)
// Acceleration (m/s²)
// Delta t (s)
double new_speed(double initial_speed, double acceleration, double delta_t) {
    return initial_speed + acceleration * delta_t;
}

double gravity(double altitude) {
    return 9.81;
}

// CD = Drag Coefficient (dimensionless, from 0.4 to 1.0)
// Rho = Air density (~1.225 kg/m³)
// Speed = Air speed (m/s)
// Surface = Front rocket surface (m²)
double drag(double cd, double rho, double speed, double surface) {
    return 0.5 * cd * rho * speed*speed * surface;
}

// force = Applied force (N)
// Mass = rocket mass (kg)
// Acceleration (m/s²)
//
// F = m*a
// a = F/m
double acceleration(double force, double mass, double altitude) {
    return force / mass;
}
