# Part I

The problem statement for Part I of the `CS 752` course is given [here](http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/wiki/index.php?n=Main.Homework1)

The configuration files are present in `/configs/learning_gem5/part1`, I modified it as per the problem statement.  

I had a hard time understanding `super()`. This stackoverflow [thread](https://stackoverflow.com/questions/576169/understanding-python-super-with-init-methods) helped in bringing clarity.

The plan was to use `sieve.c` but the makefile gave a lot of bt. So, I just ripped `sieve.cpp` from g4g and made some small changes. 

## Usage

1. Add the `sieve_config.py` to the directory `~/gem5/config/new_directory/`.

2. Add the `Makefile` and `sieve.cpp` to `~/gem5/tests/test-progs/sieve/src/`. And make  a directory `../sieve/bin`. 

3. Open terminal at `src` and execute the makefile
```shell
$ make -f Makefile
```
Your output should be: 
```shell
g++ -o ../bin/sieve sieve.cpp -pthread -std=c++17
```
Now the `/bin` directory will have the binaries of `sieve.cpp`.

4. Now, execute the following command at location `~/gem5`.
```shell
$ build/X86/gem5.opt configs/new_directory/sieve_config.py --l2_size='2MB' --l1d_size='512kB' --l1i_size='512kB'
```
This should successfully run and the output should be something like
```shell
...
...
Number of primes: 78498
Exiting @ tick 76009375000 because exiting with last active thread context
```
Number of primes: 78498
Exiting @ tick 75950298000 because exiting with last active thread context




