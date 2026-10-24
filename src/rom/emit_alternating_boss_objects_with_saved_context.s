; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_nine_boss_objects_on_alternating_phases = $133F

.segment "CODE"
.org $0250
emit_alternating_boss_objects_with_saved_context:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    jsr emit_nine_boss_objects_on_alternating_phases
    plb
    pld
    plp
    rtl
