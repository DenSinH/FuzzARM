import numpy as np


def multiply(opcode: int, r0: int, r1: int, r2: int, N, Z, C, V):
    """
    :param opcode:      opcode for multiply instruction (16 <= opcode < 22)
    :param r0:          first operand
    :param r1:          second operand
    :param r2:          (third operand)
    :param: N, Z, C, V: initial CPSR flags
    :return:
    """
    registers = np.array([r0, r1, r2, r1, r0], dtype=np.uint32)

    if opcode == 0b10000:    # MUL
        registers[4] = registers[0] * registers[1]
    elif opcode == 0b10001:  # MLA
        registers[4] = registers[0] * registers[1] + registers[2]
    elif opcode == 0b10010:  # UMULL
        HiLo = np.uint64(registers[0]) * np.uint64(registers[1])
        registers[4] = HiLo >> np.uint64(32)
        registers[3] = HiLo & np.uint64(0xffff_ffff)
    elif opcode == 0b10011:  # UMLAL
        HiLo = np.uint64(registers[0]) * np.uint64(registers[1])
        HiLo += np.uint64(registers[4] << np.uint64(32)) + np.uint64(registers[3])
        registers[4] = HiLo >> np.uint64(32)
        registers[3] = HiLo & np.uint64(0xffff_ffff)
    elif opcode == 0b10100:  # SMULL
        HiLo = np.int64(np.int32(registers[0])) * np.int64(np.int32(registers[1]))
        registers[4] = np.uint32(HiLo >> np.int64(32))
        registers[3] = np.uint32(HiLo & np.int64(0xffff_ffff))
    elif opcode == 0b10101:  # SMLAL
        HiLo = np.int64(np.int32(registers[0])) * np.int64(np.int32(registers[1]))
        HiLo += np.int64(np.int64(registers[4]) << np.int64(32)) + np.int64(registers[3])
        registers[4] = np.uint32(HiLo >> np.int64(32))
        registers[3] = np.uint32(HiLo & np.int64(0xffff_ffff))
    else:
        raise Exception()

    N = 1 if (registers[4] & 0x8000_0000 > 0) else 0
    Z = 1 if registers[4] == 0 and registers[3] == 0 else 0
    # Carry is meaningless
    # oVerflow is unaffected

    CPSR_flags = (N << 3) | (Z << 2) | (C << 1) | V

    # Op2 (shifted), result, status codes
    return registers[3], registers[4], CPSR_flags


if __name__ == '__main__':
    r0 = 0x22557B19
    r1 = 0x89B72E76
    r3, r4, CPSR_flags = multiply(0b10010, r0, r1, 0, 0, 0, 0, 0)
    print(hex(r3), hex(r4), hex(CPSR_flags))
