; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E128
restore_selected_effect_native_context_long:
    plp
    plb
    pld
    rtl
