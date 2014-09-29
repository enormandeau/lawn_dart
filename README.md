# Lawn Dart
Model Rocketry Flight Simulator

# About **Lawn Dart** is a crude but evolving rocket flight simulator that
works in the terminal, that is, there is no graphical user interface. It is
written in [C](http://en.wikipedia.org/wiki/C_\(programming_language\)) and is
my first project in that language. Its aims is primarily to be a fun project to
learn more about C. I am, however, keen on getting feedback and ideas about how
to turn this baby project into a more useful program.

**Lawn Dart** is developed with Linux and MacOSX systems in mind, although it
should compile and work under Windows. If anybody would like to report on
Windows usage or compilation specificities, I will be glad to add the
information here.

# TODO
## Top priority
- Assert that parameters have valid values
- Parse command line arguments with parameters

## Soon
- Use real motor data (stored in `/data/motors`)
- Create Struct for motors
- Make physics models more accurate

## Sometimes
- Calculate gravity as a function of altitude
- Calculate air density as a function of altitude
- Output simulation data to a .csv file

# Installing
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

