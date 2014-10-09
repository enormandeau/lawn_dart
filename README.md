# Lawn Dart
Model Rocketry Flight Simulator

# About
**Lawn Dart** is a crude but evolving rocket flight simulator that works in the
terminal, that is, there is no graphical user interface. It is written in
[C](http://en.wikipedia.org/wiki/C_\(programming_language\)) and is my first
project in that language. Its aims is primarily to be a fun project to learn
more about C. I am, however, keen on getting feedback and ideas about how to
turn this baby project into a more useful program.

**Lawn Dart** is developed with Linux systems in mind. It may compile on MacOSX
or Windows, although this may require tweaking the Makefile in order to point
to the installation of the `argtable` library (see installation section below).

# TODO
## Top priority
- Use real motor data (stored in `/data/motors`)
  - Read file line by line:
        if (fgets(line, BUFFER_SIZE, stdin) != NULL) {
           /* ... */
        }
  - Discard lines starting with ';'
  - Split other lines:
        sscanf(time, "%d:%d", &minutes, &seconds);
  - First data line contains:
    - name
    - diameter (mm)
    - length (mm)
    - possible delays (s)
    - propellant mass (kg)
    - initial motor mass (kg)
    - company
  - Other lines contain:
    - time (s)
    - thrust (N)

## Soon
- Assert that parameters have valid values
- Parse command line arguments with parameters

## Sometimes
- Revise simulation.c for errors
- Revise physics.c to improve accuracy
- Calculate gravity as a function of altitude
- Calculate air density as a function of altitude
- Output simulation data to a .csv file
- Add angle of attack drag with wind and gusts
- Do multiple simulations per run to assess wind effect

# Installing

## Depenencies
In order to compile, you will need to install
[argtable](http://argtable.sourceforge.net/) from source.

You will have to add the following to your `~/.profile` or `~/.bashrc` file:

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

To use **Lawn Dart**, you will need to compile it. From the `src` folder,
simply run:

```
make
```

to compile the program. The `lawn_dart` executable will be
created. To install it to `/usr/local/bin`, run:

```
sudo make install
```

# Usage
To get usage help, launch the executable without options, either

```
./lawn_dart
```

or, if you installed it system wide, simply

```
lawn_dart
```

# License
This project is covered by the GPLv3 license. Read the LICENSE file for
information about the license affecting the pipeline.

