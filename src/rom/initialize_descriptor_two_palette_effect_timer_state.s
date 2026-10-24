; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $41AE
initialize_descriptor_two_palette_effect_timer_state:
    ldx $87
    inc a:$0094,X
    stz a:$0096,X
    clc
    rts
