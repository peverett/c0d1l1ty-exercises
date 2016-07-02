# Codility Lesson Exercises
[c0d1l1ty]([https://codility.com/) is a webset offering coding test questions to allow potential employers to measure a job candidate's proficiency in any given programming language.

Their questions are based around algorithms and [big O notation](https://en.wikipedia.org/wiki/Big_O_notation). 

c0d1l1ty also offer a number of [programming
lessons](https://codility.com/programmers/lessons/), which will help understand
the style of their interview questions. Each lesson has reading material (PDF
document) and one or more exercises. Each exercise has an exhaustive set of test
cases that will be run against any implementation, which will verify correctness
and efficiency within the bounds of O notation.

This repository contains my solutions to the c0d1l1ty lesson exercises. All implementations are in C99 standard C and built using MinGW GCC 4.9.1 within the Qt v5.4.0 development environment. Qt project files have not been included but individual examples can be built with MinGW on Windows or on Linux with the command line:

```
 > make CFLAGS+='-std=c99' CC=GCC main
```
