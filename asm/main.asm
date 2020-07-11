format binary as 'gba'

include './lib/constants.inc'
include './lib/macros.inc'


header:
        include './lib/header.inc'

main:
        include './init.asm'

        bl run_tests

        mainloop:
                b mainloop

include './lib/text.asm'
include './run_tests.asm'