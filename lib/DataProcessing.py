import numpy as np

np.seterr(all="ignore")


def get_CV_add(Op1, Op2, Result):
    C = 1 if (int(Op1) + int(Op2) > 0xffff_ffff) else 0
    V = (((Op1 ^ Result) & (~Op1 ^ Op2)) >> 31)
    return C, V


def get_CV_add_C(Op1, Op2, C, Result):
    C = 1 if (int(Op1) + int(Op2) + C> 0xffff_ffff) else 0
    V = (((Op1 ^ Result) & (~Op1 ^ Op2)) >> 31)
    return C, V


def get_CV_sub(Op1, Op2, Result):
    C = 1 if (Op2 <= Op1) else 0
    V = (((Op1 ^ Op2) & (~Op2 ^ Result)) >> 31)
    return C, V


def get_CV_sub_C(Op1, Op2, C, Result):
    C = 1 if (int(Op2) + 1 - C <= Op1) else 0
    V = (((Op1 ^ Op2) & (~Op2 ^ Result)) >> 31)
    return C, V


def DataProcessing(opcode: int, r0: int, r1: int, r2: int, shift_type: int, N, Z, C, V):
    """
    :param opcode:      opcode for dataprocessing instruction (0 <= opcode < 16)
    :param r0:          first operand
    :param r1:          second operand
    :param r2:          shift amount
    :param: shift_type: shift type for second operand (LSL, LSR, ASR, ROR)
    :param: N, Z, C, V: initial CPSR flags
    :return:
    """
    registers = np.array([r0, r1, r2, 0, 0], dtype=np.uint32)

    # r3 = mov r1, shift_type, #r2
    if registers[2] != 0:
        if shift_type == 0b00:
            """  LSL  """
            if registers[2] > 32:
                C = 0
                registers[3] = 0
            elif registers[2] == 32:
                C = registers[1] & 0x1
            else:
                C = (registers[1] >> (32 - registers[2])) & 0x01
                registers[3] = registers[1] << registers[2]
        elif shift_type == 0b01:
            """  LSR  """
            if registers[2] > 32:
                C = 0
                registers[3] = 0
            elif registers[2] == 32:
                C = (registers[1] >> 31) & 0x1
            else:
                C = ((registers[1] >> (registers[2] - 1)) & 0x01)
                registers[3] = registers[1] >> registers[2]
        elif shift_type == 0b10:
            """  ASR  """
            if registers[2] < 32:
                C = (registers[1] >> (registers[2] - 1)) & 0x01
                registers[3] = np.uint32(np.int32(registers[1]) >> registers[2])
            else:
                registers[3] = np.uint32(0xffff_ffff) if registers[1] & 0x8000_0000 > 0 else 0
                C = registers[3] & 0x01
        elif shift_type == 0b11:
            """  ROR  """
            shift_amount = registers[2] & 0x1f
            if shift_amount != 0:
                C = (registers[1] >> (shift_amount - 1)) & 0x01
                registers[3] = ((registers[1] >> shift_amount) | ((registers[1] & ((1 << shift_amount) - 1)) << (32 - shift_amount)))
            else:
                C = 1 if (registers[1] & 0x8000_0000) != 0 else 0
                registers[3] = registers[1]
        else:
            raise Exception()
    else:
        # no special case shifting with register specified shift amount
        registers[3] = registers[1]

    """
    Note: for ADC/SBC/RSC instructions, normally you would take the initial value of C, but because of the way
    I implemented the testing in the asm rom, the new value of C will be used
    """

    if opcode == 0b0000:        # AND
        result = registers[4] = registers[0] & registers[3]
    elif opcode == 0b0001:      # EOR
        result = registers[4] = registers[0] ^ registers[3]
    elif opcode == 0b0010:      # SUB
        result = registers[4] = registers[0] - registers[3]
        C, V = get_CV_sub(registers[0], registers[3], registers[4])
    elif opcode == 0b0011:      # RSB
        result = registers[4] = registers[3] - registers[0]
        C, V = get_CV_sub(registers[3], registers[0], registers[4])
    elif opcode == 0b0100:      # ADD
        result = registers[4] = registers[0] + registers[3]
        C, V = get_CV_add(registers[0], registers[3], registers[4])
    elif opcode == 0b0101:      # ADC
        result = registers[4] = np.uint32(registers[0] + registers[3] + C)
        C, V = get_CV_add_C(registers[0], registers[3], C, registers[4])
    elif opcode == 0b0110:      # SBC
        result = registers[4] = np.uint32(registers[0] - (registers[3] + 1 - C))
        C, V = get_CV_sub_C(registers[0], registers[3], C, registers[4])
    elif opcode == 0b0111:      # RSC
        result = registers[4] = np.uint32(registers[3] - (registers[0] + 1 - C))
        C, V = get_CV_sub_C(registers[3], registers[0], C, registers[4])
    elif opcode == 0b1000:      # TST
        result = np.uint32(registers[0] & registers[3])
    elif opcode == 0b1001:      # TEQ
        result = np.uint32(registers[0] ^ registers[3])
    elif opcode == 0b1010:      # CMP
        result = np.uint32(registers[0] - registers[3])
        C, V = get_CV_sub(registers[0], registers[3], result)
    elif opcode == 0b1011:      # CMN
        result = np.uint32(registers[0] + registers[3])
        C, V = get_CV_add(registers[0], registers[3], result)
    elif opcode == 0b1100:      # ORR
        result = registers[4] = np.uint32(registers[0] | registers[3])
    elif opcode == 0b1101:      # MOV
        result = registers[4] = registers[3]
    elif opcode == 0b1110:      # BIC
        result = registers[4] = np.uint32(registers[0] & ~registers[3])
    elif opcode == 0b1111:      # MVN
        result = registers[4] = ~registers[3]
    else:
        raise Exception()

    N = 1 if result & 0x8000_0000 else 0
    Z = 1 if result == 0 else 0

    CPSR_flags = (N << 3) | (Z << 2) | (C << 1) | V

    # Op2 (shifted), result, status codes
    return registers[3], registers[4], CPSR_flags


if __name__ == '__main__':
    r0 = 0x857370AA
    r1 = 0xF69CEA3A
    r2 = 0x00000020

    r3, r4, CPSR_flags = DataProcessing(0b0111, r0, r1, r2, 3, 1, 0, 1, 1)
    print(hex(r3), hex(r4), hex(CPSR_flags))

