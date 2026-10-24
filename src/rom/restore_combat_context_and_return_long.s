; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4000
restore_combat_context_and_return_long:
    plp
    plb
    pld
    rtl
