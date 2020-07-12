from lib.DataProcessing import DataProcessing
from lib.Multiply import multiply

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
        LSB    : 0000 opcode OR 0001 mul(l)/mla(l) opcode
        LSB + 1: r2 value (shift amount OR operand 3) 
        MSB - 1: shift type (OR higher byte of r2 value for mul(l)/mla(l))
        MSB    : 
            low nibble: CPSR flags expected value
            high nibble: CPSR flags initial value
"""

VALID_ARM_TESTS = list(range(22))
VALID_THUMB_TESTS = [0, 1, 2, 4, 5, 6, 8, 10, 11, 12, 13, 14, 15, 16]


def generate(number_of_tests: int, seed=None):
    if seed:
        random.seed(seed)

    if number_of_tests < 1:
        raise ValueError(f"Cannot generate less than 1 test")

    tests = "; assortment of randomly generated tests\nalign 4\ntests:\n        dw {0:#010x}".format(number_of_tests)
    test_set = set()
    while len(test_set) < number_of_tests:
        thumb_mode = 0  # random.getrandbits(1)
        opcode = random.choice([VALID_ARM_TESTS, VALID_THUMB_TESTS][thumb_mode])
        r0_value = np.uint32(random.getrandbits(32))
        r1_value = np.uint32(random.getrandbits(32))
        N, Z, C, V = random.getrandbits(1), random.getrandbits(1), random.getrandbits(1), random.getrandbits(1)

        if opcode < 16:
            r2_value = random.randint(0, 33)
            shift_type = random.randint(0, 3)
            r3_expected, r4_expected, CPSR_flags = DataProcessing(opcode, r0_value, r1_value, r2_value, shift_type, N, Z, C, V)
        else:
            r2_value = random.randint(0, 0xff)
            shift_type = random.randint(0, 0xff)
            C = 0  # C is garbage for multiplies
            r3_expected, r4_expected, CPSR_flags = multiply(opcode, r0_value, r1_value, r2_value | (shift_type << 24), N, Z, C, V)

        CPSR_init = (N << 3) | (Z << 2) | (C << 1) | V

        test_string = "\n        dw "
        test_string += "{0:#010x}, ".format(r0_value)
        test_string += "{0:#010x}, ".format(r1_value)
        test_string += "{0:#010x}, ".format(r3_expected)
        test_string += "{0:#010x}, ".format(r4_expected)
        test_string += "{0:#010x}".format(opcode | (thumb_mode << 7) | (r2_value << 8) | (shift_type << 16) | (CPSR_flags << 24) | (CPSR_init << 28))
        test_set.add(test_string)

    tests += "".join(sorted(test_set))

    return tests


if __name__ == '__main__':

    print(generate(100))
