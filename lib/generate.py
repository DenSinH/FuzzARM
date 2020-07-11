from lib.DataProcessing import DataProcessing

import random
import numpy as np

"""
Format for tests.inc file:

1 word: # of tests

  words:
    r0 value (operand 1)
    r1 value (operand 2)
    r3 expected value (operand 2 shifted)
    r4 expected value (output)
    
    word:
        LSB    : opcode
        LSB + 1: shift type
        MSB - 1: r2 value (shift amount)
        MSB    : 
            low nibble: CPSR flags expected value
            high nibble: CPSR flags initial value

    
"""


def generate(number_of_tests: int, seed=None):
    if seed:
        random.seed(seed)

    if number_of_tests < 1:
        raise ValueError(f"Cannot generate less than 1 test")

    tests = "; assortment of randomly generated tests\nalign 4\ntests:\n        dw {0:#010x}".format(number_of_tests)
    test_set = set()
    while len(test_set) < number_of_tests:
        opcode       = random.randint(0, 15)
        shift_type   = random.randint(0, 3)
        shift_amount = random.randint(0, 33)
        r0_value     = np.uint32(random.getrandbits(32))
        r1_value     = np.uint32(random.getrandbits(32))
        N, Z, C, V   = random.getrandbits(1), random.getrandbits(1), random.getrandbits(1), random.getrandbits(1)

        CPSR_init = (N << 3) | (Z << 2) | (C << 1) | V

        r3_expected, r4_expected, CPSR_flags = DataProcessing(opcode, r0_value, r1_value, shift_amount, shift_type, N, Z, C, V)

        test_string = "\n        dw "
        test_string += "{0:#010x}, ".format(r0_value)
        test_string += "{0:#010x}, ".format(r1_value)
        test_string += "{0:#010x}, ".format(r3_expected)
        test_string += "{0:#010x}, ".format(r4_expected)
        test_string += "{0:#010x}".format(opcode | (shift_type << 8) | (shift_amount << 16) | (CPSR_flags << 24) | (CPSR_init << 28))
        test_set.add(test_string)

    tests += "".join(sorted(test_set))

    return tests


if __name__ == '__main__':

    print(generate(100))
