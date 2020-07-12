# GBATestROMGenerator
A random basic test ROM generator for the GBA. It tests both ARM and THUMB mode instructions (Data processing/ALU operations/direct adding/subtraction), so basically the basic functions of the CPU. I plan on adding load/store tests as well.

*Disclaimer* I do not own FASMARM in any way shape or form, nor have I contributed to it. I merely use it in this project to compile the generated .asm ROMS

### Generating a ROM:
Running `main.py` will prompt you with a question for how many tests you want, you can give any value greater than or equal to 1. Note that you will have to make sure that the ROM size will not get too big, so you should not do over about ~1600000 tests (I did about 1000 for testing this script, that should be enough really, but if you really want you can add way more)

After this, the script will finish running and make a `main.gba` file in the same folder, or overwrite the file with that name if it exists.

### Requirements:
The only libraries I used are `random`, `numpy` and `subprocess`. I think these are all builtin in Python (though I'm not sure about `numpy`).

### Output:
If you pass all tests, the ROM will display "End of testing" right away.
If you fail any test, the ROM will hang on that test, and display the following things:
  - what instruction you failed (e.g. `tst r0, r1, asr r2`)
  - the input parameters (e.g. `r0 001A5342, etc.`)
  - the values it got
  - the values it expected
  
  
The ROM uses a PSR transfer to initialize the CPSR to some arbitrary value to improve testing accuracy. 

### Screenshots:
Setting part of the result to 0 in a `SMULL` instruction:


![TST EOR instead of AND](https://github.com/DenSinH/GBATestROMGenerator/blob/master/Screenshots/SMULL.png)

Passing all tests:

![Passed all tests](https://github.com/DenSinH/GBATestROMGenerator/blob/master/Screenshots/Passed.png)
