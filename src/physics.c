double new_speed(double initial_speed,
        double acceleration,
        double delta_t) {
    return initial_speed + acceleration * delta_t;
}

double gravity(double altitude) {
    return 9.81;
}

double drag(double cd, double rho, double speed, double surface) {
    return 0.5 * cd * rho * speed*speed * surface;
}

double acceleration(double force, double mass, double altitude) {
    // F = m*a
    // a = F/m
    return 1000 * force / mass - gravity(altitude);
}
