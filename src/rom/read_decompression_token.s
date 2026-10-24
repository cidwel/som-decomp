; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4CC0
read_decompression_token:
    lda a:$0000,X
    inx
    cpy $05
    bcs read_decompression_token_c14ce1
    .a8
    bit #$80
    beq read_decompression_token_c14ce0
    .a8
    and #$7F
    pha
    and $07
    xba
    lda a:$0000,X
    inx
    rep #$20
    inc
    sta $03
    sep #$20
    pla
    rep #$02
read_decompression_token_c14ce0:
    rtl
read_decompression_token_c14ce1:
    pla
    pla
    pla
    rtl
