; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-palette-apis.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BD4F
rotate_native_palette_word_range_left:
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
    sec
    sbc $03
    beq rotate_native_palette_word_range_left_bd9d
    bcc rotate_native_palette_word_range_left_bd9d
    sta $05
    asl $03
    clc
    txa
    adc $03
    tax
    lda a:$0000,X
    sta $03
rotate_native_palette_word_range_left_bd8c:
    lda a:$0002,X
    sta a:$0000,X
    inx
    inx
    dec $05
    bne rotate_native_palette_word_range_left_bd8c
    lda $03
    sta a:$0000,X
rotate_native_palette_word_range_left_bd9d:
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
