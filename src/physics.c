double new_speed(double initial_speed,
        double acceleration,
        double delta_t) {
    return initial_speed + (acceleration * delta_t) / 2;
}

double gravity(double altitude) {
    return 9.81;
}

double drag(double speed, double diameter, double cd) {
    return diameter * cd * speed * speed;
}

double acceleration(double force, double mass, double altitude) {
    // F = m*a
    // a = F/m
    return 1000 * force / mass - gravity(altitude);
}
