Dominus
=======

Dominus is a testing project that is aimed to build a full home
automation system. But watch out, Dominus will become the master of
your own house!


Keywords
--------

Home automation - Arduino - Olinuxino - Android - C/C++ - CMake


Dependencies
------------

Debian Wheezy:
- autotools (automake, autoconf, autoheader, ...)
- arduino-core
- avrdude
- olinuxino cross-compiler (buildroot-a13-olinuxino)


Compile step
------------

Run:
```
mkdir build
cd build
cmake ..
make
```

or just:
```
make
```

Monitor
-------

Type CTRL-A CTRL-D to exit from monitor.


Serial Port
-----------

Just a reminder about getting serial port settings:

  stty -F /dev/ttyXX
