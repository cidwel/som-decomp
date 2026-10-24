; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $41A0
dispatch_descriptor_two_palette_effect_three_states:
    lda a:$0094,X
    asl
    tax
    jmp ($41A8,X)
