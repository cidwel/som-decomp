; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2992
advance_single_boss_palette_transition_phase:
    ldx $87
    inc a:$0094,X
    clc
    rts
