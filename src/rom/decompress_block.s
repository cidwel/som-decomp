; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4C30
decompress_block:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0031
    tcd
    tcs
    lda $32,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    phy
    phx
    pha
    tdc
    clc
    .a16
    adc #$0008
    tay
    .i16
    ldx #$4C06
    .a16
    lda #$0029
    mvn #$C1, #$00
    pla
    sep #$20
    pha
    plb
    sta $2D
    xba
    sta $2C
    sta $1D
    sta $1E
    stz $02
    rep #$20
    lda $01,S
    tax
    lda a:$0002,X
    xba
    clc
    adc $03,S
    sta $05
    sep #$20
    lda a:$0000,X
    clc
    adc $2A
    sta $2A
    .a8
    lda #$00
    xba
    lda a:$0000,X
    tax
    lda f:$C14C00,X
    sta $07
    plx
    ply
    .a8
    lda #$C1
    pha
    rep #$20
    clc
    txa
    .a16
    adc #$0004
    tax
    .a16
    lda #$4CB3
    pha
    sep #$20
    .a8
    lda #$00
    pha
    rep #$20
    tdc
    clc
    .a16
    adc #$0023
    pha
    sep #$20
    .a8
    lda #$00
    xba
    rtl
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0033
    tcs
    plp
    pld
    rts
