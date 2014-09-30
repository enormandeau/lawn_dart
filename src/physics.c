// New speed (m/s)
// ---
// Initial speed (m/s)
// Acceleration (m/s²)
// Delta t (s)
double new_speed(double initial_speed,
                 double acceleration,
                 double delta_t) {
    return initial_speed + acceleration * delta_t;
}

// Gravity (m/s²)
// ---
// Altitude (m)
double gravity(double altitude) {
    return 9.81;
}

// Drag = (kg*m/s²)
// ---
// CD = Drag Coefficient (dimensionless, from 0.4 to 1.0)
// Rho = Air density (~1.225 kg/m³)
// Speed = Air speed (m/s)
// Surface = Front rocket surface (m²)
double drag(double cd,
            double rho,
            double speed,
            double surface) {
    return 0.5 * cd * rho * speed * speed * surface;
}

// Acceleration (m/s²)
// ---
// force = Applied force (N)
// Mass = rocket mass (kg)
//
// F = m*a
// a = F/m
double acceleration(double force,
                    double mass,
                    double altitude) {
    return force / mass;
}

// Thrust (N)
// ---
// Motor (char[])
// Time (s)
double thrust(double *motor,
              double time) {
    int index;
    int max_index = 20;
    double ret;
    double motor_delta_t = 0.1;

    index = (int) (time / motor_delta_t);

    if (index < max_index) {
        ret = motor[index];
    }
    else {
        ret = 0;
    }

    return ret;
}

