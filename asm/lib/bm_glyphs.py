from PIL import Image
import numpy as np
import sys

np.set_printoptions(threshold=sys.maxsize)

# convert to bitmap
glyphs = Image.open("./glyphs.png")
bm = (np.array(glyphs) == 1).astype(int)

print(bm.shape)
asm = "\nalign 4\nglyphs:\n"
i = 0
for y in range(bm.shape[0] // 8):
    for x in range(bm.shape[1] // 8):
        glyph = "db "
        tile = bm[8 * y: 8 * y + 8, 8 * x:8 * x + 8]
        print(chr(32 + i))
        for line in tile:
            print(line)
            glyph += "{0:#04x}, ".format(int("".join(str(b) for b in line), 2))
        glyph = glyph[:-2] + f"  ;  {chr(32 + i)}\n"
        asm += f"   {glyph}"
        i += 1

with open("./glyphs.inc", "w+") as f:
    f.write(asm)
