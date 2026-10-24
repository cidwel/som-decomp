; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-palette-apis.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BDA7
rotate_native_palette_word_range_right:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    stx $01
    sta $05
    .a16
    and #$00FF
    sta $03
    lda $05
    xba
    .a16
    and #$00FF
    sta $05
    sec
    sbc $03
    beq rotate_native_palette_word_range_right_bdf7
    bcc rotate_native_palette_word_range_right_bdf7
    sta $03
    asl $05
    clc
    txa
    adc $05
    tax
    lda a:$0000,X
    sta $05
rotate_native_palette_word_range_right_bde6:
    dex
    dex
    lda a:$0000,X
    sta a:$0002,X
    dec $03
    bne rotate_native_palette_word_range_right_bde6
    lda $05
    sta a:$0000,X
rotate_native_palette_word_range_right_bdf7:
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
