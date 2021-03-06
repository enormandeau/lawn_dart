# Lawn Dart

Model Rocketry Flight Simulator

# About

**Lawn Dart** is a crude but evolving (at its own pace) rocket flight simulator
that works in the terminal. That is, there is no graphical user interface. It
is written in [C](http://en.wikipedia.org/wiki/C_\(programming_language\)) and
also happens to be my first project in that language. It is mainly a fun
project to learn started to help me learn more about C.

**Lawn Dart** is developed with Linux systems in mind. It may compile on MacOSX
or Windows, although this may require tweaking the Makefile in order to point
to the installation of the `argtable` library (see installation section below).
If you install lawn_dart on MacOSX or Windows, you can send me the installation
procedure and I will add it to this document.

# TODO

## Top priority

- Use real motor data (stored in `/data/motors`)
  - Read file line by line:
        if (fgets(line, BUFFER_SIZE, stdin) != NULL) {
           ; /* ... */
        }
  - Discard lines starting with ';'
  - First data line contains:
    - name
    - diameter (mm)
    - length (mm)
    - possible delays separated by '-' (s)
    - propellant mass (kg)
    - initial motor mass (kg)
    - company abbreviation
  - Split other lines:
        sscanf(line, "%d %d", &time, &thrust);

## Soon

- Use [argtable3](https://github.com/argtable/argtable3)
  - Include in project files directy?

## Sometimes

- Revise simulation.c for errors
- Revise physics.c to improve accuracy
- Calculate gravity as a function of altitude
- Calculate air density as a function of altitude
- Output simulation data to a .csv file

## Maybe

- Add angle of attack drag with wind and gusts
- Assess effect of wind and gusts (multiple simulations per run)

# Installing

## Depenencies

In order to compile lawn_dart, you will need to install
[argtable](http://argtable.sourceforge.net/) from source:

```bash
    wget http://prdownloads.sourceforge.net/argtable/argtable2-13.tar.gz
    tar xvfz argtable2-13.tar.gz
    cd argtable2-13
    ./configure
    make
    sudo make install
```

You will have to add the following to your `~/.profile` or `~/.bashrc` file:

```bash
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

To use **Lawn Dart**, you will need to compile it. From the `src` folder,
simply run:

```bash
    make
```

The `lawn_dart` executable will be created. To install it to `/usr/local/bin`,
run:

```bash
    sudo make install
```

# Usage

To get usage help, launch the executable without options or with the `-h`
option. If you installed it system wide :

```bash
    lawn_dart
```

Otherwise, from the **`src`** folder of the lawn_dart directory :

```bash
    ./lawn_dart
```

# License

This project is covered by the GPLv3 license. Read the LICENSE file for
more information.

