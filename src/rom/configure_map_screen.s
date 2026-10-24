; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AA60
configure_map_screen:
    rep #$30
    lda $30
    .a16
    and #$003F
    sta $00
    asl
    asl
    asl
    clc
    adc $00
    tax
    lda f:$C80100,X
    sta $20
    lda f:$C80102,X
    sta $22
    lda f:$C80104,X
    sta $24
    lda f:$C80105,X
    sta $25
    lda f:$C80107,X
    sta $27
    sta a:$0600
    sta f:$7EDE00
    stz $2C
    stz $2E
    stz a:$4306
    stz a:$4316
    stz a:$4326
    stz a:$4336
    stz a:$4346
    stz a:$4356
    stz a:$4366
    stz a:$4376
    sep #$30
    lda $20
    sta a:$2106
    stz a:$2123
    stz a:$2124
    stz a:$2125
    stz a:$212A
    stz a:$212B
    lda $21
    sta a:$212C
    lda $22
    sta a:$212D
    stz a:$212E
    stz a:$212F
    .a8
    lda #$02
    sta a:$2130
    lda $23
    sta a:$2131
    stz a:$2132
    .a8
    lda #$00
    sta a:$2126
    sta a:$2128
    .a8
    lda #$FF
    sta a:$2127
    sta a:$2129
    .a8
    lda #$60
    lsr
    lsr
    lsr
    lsr
    lsr
    .a8
    ora #$60
    sta $91
    sta a:$2101
    rts
