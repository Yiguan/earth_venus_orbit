# earth_venus_orbit
Simulate the orbit of Earth and Venus, plot the relative position of them.
The purpose of the project is to show the position of the Earth and the Venus, and what can it draw if we connect Earth and Venus consecutively.

# Usage
A C script, earthVSvenus.c, is used to generate the date needed for plot.
Compile the C script with a C compiler, and then run the compiled executible program. The program takes two command arguments:
1) the time(in days) gap, an integer, eg, 5 or 10;
2) the name of output file, which contains all the simulated data.

With the output file, an R script is used to visualize the data - plotPlanet.R.

The R script takes one command argument - the file name of simulated data.

Before using R to visualize the data, make sure you have installed R package - "berryFunctions".

# Examples
```bash
$ clang earthVSvenus.c -o my_program
$ ./my_program 10 data_10days.txt

# using R code for visualization
$ Rscript plotPlanet.R data_10days.txt 
```
