; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $27DC
dispatch_single_color_boss_palette_transition_phase:
    lda a:$0094,X
    asl
    tax
    jmp ($27E4,X)
