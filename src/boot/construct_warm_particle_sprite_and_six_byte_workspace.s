; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0a1 = $B0A1
routine_7eb6d0 = $B6D0
routine_7ec288 = $C288

.segment "CODE"
.org $B342
construct_warm_particle_sprite_and_six_byte_workspace:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    .i16
    ldx #$0006
    .a8
    lda #$00
    jsr routine_7eb0a1
    stx $01
    .a8
    lda #$0B
    jsr routine_7eb6d0
    stx $03
    .a8
    lda #$08
    sta a:$0001,X
    stz a:$0000,X
    .a8
    lda #$30
    jsr routine_7ec288
    rep #$20
    clc
    .a16
    adc #$0038
    ldx $03
    sta a:$0002,X
    .a16
    lda #$0070
    jsr routine_7ec288
    clc
    .a16
    adc #$0080
    ldx $03
    sta a:$0004,X
    .a16
    lda #$0020
    sta a:$0006,X
    txa
    ldx $01
    sta a:$0000,X
    .a16
    lda #$0010
    jsr routine_7ec288
    ldx $01
    inc
    sta a:$0004,X
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
