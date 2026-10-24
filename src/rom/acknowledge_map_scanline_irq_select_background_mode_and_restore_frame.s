; Recovered Secret of Mana USA routine; behaviour documented in docs/map-scanline-irq.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C1CF
acknowledge_map_scanline_irq_select_background_mode_and_restore_frame:
    sep #$20
    phb
    pha
    .a8
    lda #$00
    pha
    plb
    lda a:$4211
    .a8
    lda #$09
    sta a:$2105
    .a8
    lda #$14
    sta a:$212C
    pla
    plb
    rti
