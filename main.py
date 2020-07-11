from lib import generate

import subprocess as sp
from pathlib import Path
import sys

with open("./asm/tests.inc", "w+") as f:
    f.write(generate(100))

executable = {
    "win32": "FASMARM.EXE",
    "linux": "fasmarm.o",
    "linux2": "fasmarm.o",
    "darwin": "fasmarm"
}

if sys.platform not in executable:
    raise OSError("OS not supported")

completed_process = sp.run(
    [
        f"./FASMARM/{executable[sys.platform]}",
        str(Path("./asm/main.asm").absolute()),
        str(Path("./main.gba").absolute())
     ]
)

if completed_process.returncode != 0 or completed_process.stderr:
    raise Exception(completed_process.stderr)

