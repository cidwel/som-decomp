; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4576
restore_actor_appearance_context_long:
    plp
    plb
    pld
    rtl
