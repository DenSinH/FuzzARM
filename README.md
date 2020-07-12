# GBATestROMGenerator
A random basic test ROM generator for the GBA. It tests both ARM and THUMB mode instructions (Data processing/ALU operations/direct adding/subtraction/loading and storing in various different ways), so basically the basic functions of the CPU.

I plan on making it optional to add certain tests (for example, adding only THUMB tests, or not allowing load/store tests to be generated)

*Disclaimer* I do not own FASMARM in any way shape or form, nor have I contributed to it. I merely use it in this project to compile the generated .asm ROMS.

### Generating a ROM:
Running `main.py` will prompt you with a question for how many tests you want, you can give any value greater than or equal to 1. Note that you will have to make sure that the ROM size will not get too big, so you should not do over about ~1600000 tests (I did about 1000 for testing this script, that should be enough really, but if you really want you can add way more)

After this, the script will finish running and make a `main.gba` file in the same folder, or overwrite the file with that name if it exists.

### ROM generation requirements:
The only libraries I used are `random`, `numpy` and `subprocess`. I think these are all builtin in Python (though I'm not sure about `numpy`).

### ROM running requirements:
If you are building an emulator, I wrote this so that it can be ran from the very early stages of emulation. It uses rendering mode 4 to diplay the results, so you will need that. Other than that, I do _not_ use any SWIs/DMAs/Timers/IRQs/Weird IO registers (Only `DISPCNT` and `KEYINPUT`). You should be fine having most the basic instructions implemented, I use conditional operations, branches, arithmetic operations, and PSR transfers, but that should be about it. 

I think these ROMs should be very useful for debugging purposes, as they do not have any timing requirements, as mentioned above. If the ROM doesn't run _at all_ on your emulator, you should be able to copmare logs with established emulators like mGBA or Nanoboy Advance (though mGBA does not always pass apparently, VBA doesn't either).

### The ROM in the repo:
There is a ROM in the repo (`main.gba`). This ROM holds 10000 randomly generated tests for ARM/THUMB mode and all things it can possibly test. If you do not want to generate more ROMs yourself, you can simply download that one.

### Output:
If you pass all tests, the ROM will display "End of testing" right away.
If you fail any test, the ROM will hang on that test, and display the following things:
  - what instruction you failed (e.g. `tst r0, r1, asr r2`)
  - the input parameters (e.g. `r0 001A5342, etc.`)
  - the values it got
  - the values it expected
  
You can press any button (except L or R) to continue testing until you hit the next error. 
Once there are no more tests failing, "End of testing" will be displayed as well (though if you have failed tests before, old text might still be displayed).
  
#### The data processing tests work as follows:
  - r1 is shifted by r2 with the proper shift type, and stored in r3
  - r0 and r3 are operated upon, and stored in r4
#### Note: this causes `ADC`/`SBC`/`RSC` behavior to be off: in the tests, the operation uses the _new_ value for C (after the shifting operation), while it should use the _old_ value of C. A working emulator or hardware, should still pass the tests, because I account for this difference in generating the ROM!
#### The multiplication instructions work as follows:
  - no register is shifted
  - r0, r1 are operated upon, and the result is stored in r3 (and r4 in case of a `MULL/MLAL` instruction)
  
#### The load/store instructions work as follows:
  - no register is shifted
  - r4 (and r3 for `LDM`/`SWP` instructions) are stored
  - r4 (and r3 for `LDM`/`SWP` instructions) are changed to the value of `r12`, which always holds `0800XXXX` as far as I'm aware
  - r4 (and r3 for `LDM`/`SWP` instructions) are loaded from the same addresses
#### Note: no strange edge case behavior is tested for loading and storing: all loads/stores tested are word aligned!
  
The ROM uses a PSR transfer to initialize the CPSR to some arbitrary value to improve testing accuracy. 

### Screenshots:
Not sign extending a sign extended halfword load in 'THUMB' mode:

![Sign extend gone wrong](https://github.com/DenSinH/GBATestROMGenerator/blob/master/Screenshots/THUMB%20sign%20extend%20gone%20wrong.png)

Passing all tests:

![Passed all tests](https://github.com/DenSinH/GBATestROMGenerator/blob/master/Screenshots/Passed.png)
