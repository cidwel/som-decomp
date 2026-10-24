; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native70-palette-cycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D407
initialize_native70_palette_cycle_phase:
    ldx $87
    inc a:$0094,X
    stz a:$0096,X
    clc
    rts
