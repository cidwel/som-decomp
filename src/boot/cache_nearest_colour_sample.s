; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $86F1
cache_nearest_colour_sample:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    sep #$20
    lda a:$0000,Y
    sta $07
    lda a:$0001,Y
    sta $08
    lda a:$0002,Y
    sta $09
    phb
    .a8
    lda #$7F
    pha
    plb
    .a8
    lda #$F7
    sta $04
    .a8
    lda #$FF
    sta $02
    .a8
    lda #$E8
    sta $01
    ldy a:$001A
cache_nearest_colour_sample_8721:
    lda a:$0000,Y
    sec
    sbc $07
    bcs cache_nearest_colour_sample_872c
    .a8
    eor #$FF
    inc
cache_nearest_colour_sample_872c:
    sta $06
    rep #$20
    php
    sei
    sep #$20
    xba
    lda $06
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    plp
    sta $0A
    sep #$20
    lda a:$0001,Y
    sec
    sbc $08
    bcs cache_nearest_colour_sample_8753
    .a8
    eor #$FF
    inc
cache_nearest_colour_sample_8753:
    sta $06
    rep #$20
    php
    sei
    sep #$20
    xba
    lda $06
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    plp
    clc
    adc $0A
    sta $0A
    sep #$20
    lda a:$0002,Y
    sec
    sbc $09
    bcs cache_nearest_colour_sample_877d
    .a8
    eor #$FF
    inc
cache_nearest_colour_sample_877d:
    sta $06
    rep #$20
    php
    sei
    sep #$20
    xba
    lda $06
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    plp
    clc
    adc $0A
    cmp $02
    bcs cache_nearest_colour_sample_87a2
    sta $02
    lda $01
    sta $04
cache_nearest_colour_sample_87a2:
    clc
    tya
    .a16
    adc #$0004
    tay
    sep #$20
    dec $01
    beq cache_nearest_colour_sample_87b1
    jmp cache_nearest_colour_sample_8721
cache_nearest_colour_sample_87b1:
    .a8
    lda #$F7
    sec
    sbc $04
    sta f:$7F8000,X
    plb
    rep #$20
    sta $0A,S
    tsc
    clc
    .a16
    adc #$0009
    tcs
    pla
    plp
    pld
    rts
