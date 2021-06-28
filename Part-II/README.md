# Part-II

This assignment tests the familiarity with gem5 ISA description. The task is to implement an x87 floating point instruction called FSUBR. 

FSUBR subtracts the value in a floating-point register from the value in another register or a memory location, and stores the result in the first specified register. If one operand is specified, the instruction subtracts the value in ST(0) from the value in memory and stores the result in ST(0). If two operands are specified, it subtracts the value in ST(0) from the value in another floating-point register or vice versa.
The FSUBR instructions perform the reverse operations of the FSUB instructions.

The link to the assigment and tutorial is given [here](http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/wiki/index.php?n=Main.Homework2).

An entire instruction in gem5 is divided into micro-ops and macro-ops. By providing the ISA decoder with the information on the macro-op, we then define the macro-op in terms of micro-op, and lastly all the micro-op are induvidually defined. 

## Usage/Solution

1. Read the manuals for x87 instructions and x87 encoding. This gives a rough idea about the implementation. Now, open `~/gem5/src/arch/x86/isa/x87.isa`. At first glance it might be hard to read. But, on closer inspection you realise that the `opcode`, `modRM_Mod`, `modRM_Reg` fields are being decoded bit by bit. Use the `x87.isa` given in this repository and make the relevent changes. (indicated with //Change...)

2. Implement the macro-ops in terms of the micro-ops by going to `~/gem5/src/arch/x86/isa/insts/x87/arithmetic/subtract.py`. Use the `subtract.py` given in the repository and make the relevent changes. 

3. Compile gem5 for x86 ISA to make sure there no errors. To compile type: 
```shell
/usr/bin/env python3 $(which scons) build/X86/gem5.opt
```
After compilation, you should get this message without any errors. 
```shell
...
 [     CXX] X86/python/m5/info.py.cc -> .o
 [     CXX] X86/base/date.cc -> .o
 [    LINK]  -> X86/gem5.opt
scons: done building targets.
```
4. Build the Makefile for the `subtract_inline.cpp` and use this in the cpu built in Part-I. (The process for using this as the test bench remains the same as Part-I)
```shell
make 
```
Then go to `~/gem5/configs/new_directory/sieve_config.py` and change the line
```python3
binary = '../gem5_101_solutions/Part-II/out/fsubr'
```
Now run the cpu in `~/gem5`:
```shell
build/X86/gem5.opt configs/new_directory/sieve_config.py --l2_size='2MB' --l1d_size='512kB' --l1i_size='512kB'
```
The output should be `4.200000`

This shows that the instruction FSUBR has succesfully been implemented.