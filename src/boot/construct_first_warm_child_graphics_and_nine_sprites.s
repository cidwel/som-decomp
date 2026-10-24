; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0a1 = $B0A1
routine_7eb6d0 = $B6D0
routine_7eba7f = $BA7F
routine_7ebbab = $BBAB
routine_7ebbfe = $BBFE
routine_7ebc9a = $BC9A

.segment "CODE"
.org $B97A
construct_first_warm_child_graphics_and_nine_sprites:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    sep #$20
    jsr routine_7eba7f
    .i16
    ldx #$0018
    .a8
    lda #$00
    jsr routine_7eb0a1
    stx $03
    .a8
    lda #$08
    jsr routine_7ebbab
    phx
    .a8
    lda #$7E
    xba
    .a8
    lda #$1E
    .i16
    ldy #$5180
    jsr routine_7ebc9a
    plx
    jsr routine_7ebbfe
    ldx $03
    sta a:$0016,X
    sta $05
    .a8
    lda #$09
    sta $01
    stz $07
    stz $08
construct_first_warm_child_graphics_and_nine_sprites_b9b8:
    stx $09
    jsr routine_7eb6d0
    lda $05
    sta a:$0001,X
    stz a:$0003,X
    txy
    ldx $07
    lda f:$7E6028,X
    inx
    clc
    .a8
    adc #$86
    sta a:$0002,Y
    lda f:$7E6028,X
    rep #$20
    .a16
    and #$00FF
    inx
    clc
    .a16
    adc #$0060
    sta a:$0004,Y
    stx $07
    ldx $09
    tya
    sta a:$0000,X
    inx
    inx
    sep #$20
    dec $01
    bne construct_first_warm_child_graphics_and_nine_sprites_b9b8
    ldx $03
    rep #$20
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
