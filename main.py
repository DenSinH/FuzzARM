from lib import generate

import subprocess as sp
from pathlib import Path
import sys
import argparse
from pprint import pprint

parser = argparse.ArgumentParser(description="A fuzzer for the Nintendo GameBoy Advance")
parser.add_argument(
    "number_of_tests",
    metavar="N",
    type=int,
    nargs=None,
    help="Number of tests to generate"
)

parser.add_argument(
    "-T",
    dest="do_thumb_mode",
    help="Amount of THUMB mode tests to generate, choose from 'some', 'all' or 'none'",
    type=str.lower,
    choices=["some", "all", "none"]
)

parser.add_argument(
    "-nM",
    help="Disable multiply tests",
    dest="do_multiply",
    action="store_false"
)

parser.add_argument(
    "-nD",
    help="Disable data processing tests",
    dest="do_data_processing",
    action="store_false"
)

parser.add_argument(
    "-nLS",
    help="Disable load/store tests",
    dest="do_load_store",
    action="store_false"
)

parser.add_argument(
    "--S",
    nargs=None,
    help="Seed to seed the generator with",
    dest="seed"
)

parser.set_defaults(do_thumb_mode="some")

number_of_tests = 0
args = {}

if len(sys.argv) > 1:
    args = vars(parser.parse_args(sys.argv[1:]))
    number_of_tests = args.pop("number_of_tests")

else:
    print(f"No command line arguments given")

    while True:
        try:
            number_of_tests = int(input("Number of tests: "))
            break
        except ValueError:
            print("Please enter a valid number")

    print("To omit certain types of tests, use the command line options ('-h' or '-help' for more information)")


with open("./asm/tests.inc", "w+") as f:
    f.write(generate(number_of_tests, **args))

executable = {
    "win32": "FASMARM.EXE",
    "linux": "fasmarm",
    "linux2": "fasmarm",
    "darwin": "fasmarm.o",
}

if sys.platform not in executable:
    raise OSError("OS not supported: '%s'", sys.platform)

completed_process = sp.run(
    [
        f"./FASMARM/{executable[sys.platform]}",
        str(Path("./asm/main.asm").absolute()),
        str(Path("main.gba").absolute()),
    ]
)

if completed_process.returncode != 0 or completed_process.stderr:
    raise Exception(completed_process.stderr)

print(f"Output ROM to {Path('main.gba').absolute()}")