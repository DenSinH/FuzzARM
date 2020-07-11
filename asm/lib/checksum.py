with open("./header.bin",  "rb") as f:
    header = bytearray(f.read())

chk = 0
for i in range(0xA0, 0xBC):
    chk = chk - header[i]

chk = (chk - 0x19) & 0xff

print(hex(chk))
input()
