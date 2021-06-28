# We need to write the microop for the FSUBR1 and FSUBR2 similar to FSUB1 and FSUB2
# Register

microcode = '''
def macroop FSUB1_R
{
    subfp st(0), st(0), sti
};


def macroop FSUB1_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), st(0), ufp1
};

def macroop FSUB1_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), st(0), ufp1
};

def macroop FSUB2_R
{
    subfp sti, sti, st(0)
};

def macroop FSUB2_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), st(0), ufp1
};

def macroop FSUB2_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), st(0), ufp1
};

def macroop FSUBP
{
    subfp st(1), st(1), st(0), spm=1
};

def macroop FSUBP_R
{
    subfp sti, sti, st(0), spm=1
};

def macroop FSUBP_M
{
    fault "std::make_shared<UnimpInstFault>()"
};

def macroop FSUBP_P
{
   fault "std::make_shared<UnimpInstFault>()"
};

# We need to write the microcode for the FSUBR1 and FSUBR2 similar to FSUB1 and FSUB2
# Register
def macroop FSUBR1_R
{
    subfp st(0), sti, st(0)
};

# Operands from the memory using the address
def macroop FSUBR1_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), ufp1, st(0)
};

# Address of the instruction pointer to read the operand
def macroop FSUBR1_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), ufp1, st(0)
};

# Register
def macroop FSUBR2_R
{
    subfp sti, st(0), sti
};

# Operands from the memory using the address
def macroop FSUBR2_M
{
    ldfp ufp1, seg, sib, disp
    subfp st(0), ufp1, st(0)
};

# Address of the instruction pointer to read the operand
def macroop FSUBR2_P
{
    rdip t7
    ldfp ufp1, seg, riprel, disp
    subfp st(0), ufp1, st(0)
};

def macroop FSUBRP
{
    subfp st(1), st(0), st(1), spm=1
};

def macroop FSUBRP_R
{
    subfp sti, st(0), sti, spm=1
};

def macroop FSUBRP_M
{
    fault "std::make_shared<UnimpInstFault>()"
};

def macroop FSUBRP_P
{
   fault "std::make_shared<UnimpInstFault>()"
};

# FISUB
# FSUBRP
# FISUBR
'''