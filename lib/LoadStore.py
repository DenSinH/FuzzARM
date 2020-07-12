import numpy as np


def LoadStore(opcode: int, r0: int, r1: int, r2: int, N, Z, C, V):
    registers = np.array([r0, r1, r2, r1, r0], dtype=np.uint32)

    if opcode == 0b100000:  # ldr / str
        pass  # load store r4 @ r2
    elif opcode == 0b100001:  # ldrh / strh
        registers[4] &= np.uint32(0xffff)
    elif opcode == 0b100010:  # ldrsh / strh
        registers[4] = np.uint32(np.int32(np.int16(registers[4] & np.uint32(0xffff))))
    elif opcode == 0b100011:  # ldrb / strb
        registers[4] &= np.uint32(0xff)
    elif opcode == 0b100100:  # ldrsb / strb
        registers[4] = np.uint32(np.int32(np.int8(registers[4] & np.uint32(0xff))))
    elif opcode == 0b100101:  # ldm / stm
        pass  # push / pop r3 and r4
    elif opcode == 0b100110:  # swp (ARM only)
        # str r4, [MEM_WRAM]
        # swp r3 -> MEM -> r4
        # ldr r3, [MEM_WRAM]
        # in the end, nothing changes
        pass
    else:
        raise Exception()

    # CPSR flags unaffected
    CPSR_flags = (N << 3) | (Z << 2) | (C << 1) | V

    return registers[3], registers[4], CPSR_flags


if __name__ == '__main__':
    r0 = 0x857370AA
    r1 = 0xF69CEA3A
    r2 = 0x00000020

    r3, r4, CPSR_flags = LoadStore(0b100100, r0, r1, r2, 1, 1, 0, 1)
    print(hex(r3), hex(r4), hex(CPSR_flags))
