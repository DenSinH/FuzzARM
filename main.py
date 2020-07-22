from lib import generate

import subprocess as sp
from pathlib import Path
import sys


while True:
    try:
        number_of_tests = int(input("Number of tests: "))
        break
    except ValueError:
        print("Please enter a valid number")


with open("./asm/tests.inc", "w+") as f:
    f.write(generate(number_of_tests))

executable = {
    "win32": "FASMARM.EXE",
    "linux": "fasmarm",
    "linux2": "fasmarm",
    "darwin": "fasmarm.o"
}

if sys.platform not in executable:
    raise OSError("OS not supported")

if "linux" in sys.platform or "darwin" in sys.platform:
    print("chmod +x ./FASMARM/fasmarm")
    chmod = sp.run("chmod +x ./FASMARM/fasmarm")
    if chmod.stdout:
        print(chmod.stdout)
    if chmod.returncode != 0:
        print(chmod.sterr)
        raise OSError("Could not chmod ./FASMARM/fasmarm")


completed_process = sp.run(
    [
        f"./FASMARM/{executable[sys.platform]}",
        str(Path("./asm/main.asm").absolute()),
        str(Path("./main.gba").absolute())
     ]
)

if completed_process.returncode != 0 or completed_process.stderr:
    raise Exception(completed_process.stderr)

