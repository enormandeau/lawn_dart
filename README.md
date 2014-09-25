# Lawn Dart
Model Rocketry Flight Simulator

# About
**Lawn Dart** is a crude but evolving rocket flight simulator. It is written in
the [C language](http://en.wikipedia.org/wiki/C_\(programming_language\)). It also
happens to be my first C project. Its aims is primarily to be a fun project to
canalize my C programming apprenticeship. I am, however, keen on getting
feedback and ideas about how to turn this baby project into a useful program.

This is developed with Linux and MacOSX users in mind, although it should
work fine under Windows. I do not use Windows, however, so I cannot confirm it.
If anybody would like to report on Windows usage or specificities about
installation, I will be glad to add the information in this manual.

# Installing
To use **Lawn Dart**, you will need to compile it. From the `src` folder,
simply run:

```
make
```

to compile the program. The `lawn_dart` executable will be
created.

```
sudo make install
```

will attempt to install it to `/usr/local/bin`.

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

