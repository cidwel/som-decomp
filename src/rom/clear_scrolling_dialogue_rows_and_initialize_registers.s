; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $095C
clear_scrolling_dialogue_rows_and_initialize_registers:
    .i16
    ldx #$0800
clear_scrolling_dialogue_rows_and_initialize_registers_cc095f:
    stz a:$93FF,X
    dex
    bne clear_scrolling_dialogue_rows_and_initialize_registers_cc095f
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$44
    tsb a:$1D04
    rep #$20
    stz a:$003E
    .a16
    lda #$001C
    sta a:$0040
    .i16
    ldy #$0000
    .i16
    ldx #$0000
    sep #$20
    .a8
    lda #$06
clear_scrolling_dialogue_rows_and_initialize_registers_cc0984:
    xba
    lda f:$CC0B5B,X
    sta a:$0602,Y
    inx
    iny
    xba
    dec
    bne clear_scrolling_dialogue_rows_and_initialize_registers_cc0984
    plb
    inc a:$A161
    rts
