/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;

    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting if the shift amount
is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the spec) to
check the legality of your solutions.
2. Each function has a maximum number of operations (integer, logical,
or comparison) that you are allowed to use for your implementation
of the function.  The max operator count is checked by dlc.
Note that assignment ('=') is not counted; you may use as many of
these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to verify that your solutions produce
 *      the correct answers.
 */
#endif

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // nor and and find the oppposites of each other, looks for differences and similarites 
    int nor = ~x & ~y;
    int and = x & y;
    // doing a and of these will combine the differences between the two into one 
    int ans = ~and & ~nor;
    return ans;
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    // easier function, ! operator already checks for zero and non zero
    return !x;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // constructing 0xAAAAAAAA like in the description to use as comparison
    int oddB = 0xAA + (0xAA<<8) + (0xAA<<16) + (0xAA<<24);
    // comparing values of x and the mask we constructed 
    int val = (x & oddB);
    // returning the opposite of the XOR of val and the mask
    return !(val ^ oddB);
}

/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    // n coveres a range of 33 values so subtract n from 33
    int sub = 33 + ~n;
    // shift x by the subtration of n from 33
    int shift = (x << sub);
    // take the shift and shift it to the right by the subtraction again (shift right and left in attempt to sign extend)
    int shift2 = shift >> sub;
    // return XOR will return 0 if the same but we want the opposite of that so put the ! to switch it if the numbers are the same 
    return !(x ^ shift2);
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
    // find both exponenet and fraction
    unsigned ex = (uf << 1) >> 24;
    unsigned fract = uf << 9;

    // wasn't super sure on how to do this, set the last bit to 0 for the sign of the bit
    int res = uf & 0x7fffffff;

    //check for NaN and return argument if it is
    if ((ex==255) && (fract!=0x00)){
        return uf;
    }
    
    return res;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    // set mask for 32 bit and set the fraction portion of byte
    unsigned shiftMask = ~(1 << 31);
    unsigned fraction = (~0x00) + (1 << 23);

    // 'and' for mask and each unsigned variable, floating point arguments
    unsigned floatF = shiftMask & uf;
    unsigned floatG = shiftMask & ug;

    // check for all 0's in that case it'll return 1
    if ((floatF == 0x00) && (floatG == 0x00)){
        return 1;
    }

    // check for NaN or non zero masks and return 0, otherwise return the floating point arguments for f and g
    if (((floatF >> 23 == 255) && (fraction & uf) != 0x00)) {
        return 0;
    } else if (((floatG >> 23 == 255) && (fraction & ug) != 0x00)) {
        return 0;
    } else {
        return uf == ug;
    }
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678, 1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // shift n over 3 beczuse it is most significant
    int shiftN = n << 3;
    // shift x over by n shift 
    int shiftX = x >> shiftN;
    // return the two values (0xFF) from shifted x
    return (shiftX & 255);
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    // shift all bits over by 31 since we are looking at 32 bit 
    // add x and y and shift as well to use for comparison later
    int val = x + y;
    int shiftX = x >> 31;
    int shiftY = y >> 31;
    int shiftV = val >> 31;
    // negate xor of x and y shift and x and v to know if you can add them 
    return !(~(shiftX ^ shiftY) & (shiftX ^ shiftV));
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    // create all ones
    int ones = ~0;
    // shift the high bit into the ones
    int shiftHi = ones << highbit << 1;
    // shoft lowbit into ones
    int shiftLo = ones << lowbit;
    // xor the shifted high and shifted low
    int comp = shiftHi ^ shiftLo;
    // return comp and the shfited low to create a mask
    return comp & shiftLo;
}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
    // shoft n over by three
    int shift = n << 3;
    // set mask of c to 255 since that is the max per directions
    int maskC = 255;
    // shift c over by shift n
    int shiftC = c << shift;
    // the not of shifting maskC by shift of n
    int shiftMask = ~(maskC << shift);
    // and of x and shiftmask or shoft of c to replace the byte in n
    return (x & shiftMask) | shiftC;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    // set mask since 32 bit, leading bit should be 0 
    int leadingBit = !(x >> 31);
    // checks if x has as most 1 bit set and nonzero otherwise 
    int powCheck = (x + (~1 + 1)) & x;
    // checks if the number is zero
    int checkZero = !!x;
    // checks all the conditions above and returns a val if all conditions are/aren't met
    return checkZero & leadingBit & !powCheck;
}

/*
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
    // taking from the other floating point functions, set masks and shift uf by mask
    unsigned shiftMask = ~(1 << 31);
    unsigned fraction = (~0) + (1 << 23);
    unsigned floatF = shiftMask & uf;
    unsigned sign = uf >> 31;
    int frac = fraction & uf;
    int power = 2;
    // set exponent and mask
    unsigned ex = (floatF << 1) >> 24;
    // check for NaN
    if (ex == 255) {
        return uf;
    }
    // Set condition for while the power is greater than 0 
    // set int to power of 2 for while loop so it is able to compute 4*f (setting it almost to ^2)
    while (power--){
        if (ex == 0){
            // if exponenet is zero, look at the fraction portion of the byte
            if (frac & (1 << 22)) {
                // if conditions above are satisfied, shift fraction over by one and set exponent to 1 
                frac = frac << 1;
                ex = 1;
            } else {
                // else if fraction mask is not 1 << 22 set exponent to 0
                frac = frac << 1;
                ex = 0;
            }
        } else {
            // if exponent is not 0
            if (ex != 255){
                // if exponent is not 11111111 then add 1 to the exponenent 
                ex = ex + 1;
            }
            if (ex == 255) {
                // otherwise, set fraction to 0
                frac = 0x00;
            } 
        }
    }

    // after the while loop, 'and' the new fraction and the mask for fraction as well as exponenet and 1111 1111 (mask for exponent)
    frac = frac & fraction;
    ex = ex & 255; 

    // return either sign or exponent of the fraction, whichever has value 
    return (sign << 31) | ((ex) << 23) | frac; 
}

