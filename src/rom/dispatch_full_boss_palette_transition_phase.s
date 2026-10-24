; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_single_color_boss_palette_transition_phase = $27DC

.segment "CODE"
.org $27C1
dispatch_full_boss_palette_transition_phase:
    lda a:$009E,X
    bmi dispatch_single_color_boss_palette_transition_phase
    lda a:$0094,X
    asl
    tax
    jmp ($27CE,X)
