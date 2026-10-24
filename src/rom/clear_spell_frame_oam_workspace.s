; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4848
clear_spell_frame_oam_workspace:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    .a16
    lda #$F0F0
    sta a:$0800
    .i16
    ldx #$0800
    .i16
    ldy #$0801
    .a16
    lda #$005E
    mvn #$00, #$00
    .a16
    lda #$0000
    sta a:$0A00
    .i16
    ldx #$0A00
    .i16
    ldy #$0A01
    .a16
    lda #$0004
    mvn #$00, #$00
    .a16
    lda #$0060
    sta f:$00007C
    .a16
    lda #$0006
    sta f:$00005A
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
