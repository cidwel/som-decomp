; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-sprite-setup.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb6d0 = $B6D0
routine_7eb7b9 = $B7B9
routine_7ec288 = $C288

.segment "CODE"
.org $945D
construct_sixteen_warm_scene_sprites:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    .a16
    lda #$0010
    sta $01
construct_sixteen_warm_scene_sprites_946d:
    .a16
    lda #$000B
    jsr routine_7eb6d0
    stx $03
    .a16
    lda #$0000
    jsr routine_7ec288
    ldx $03
    sta a:$0004,X
    .a16
    lda #$0068
    jsr routine_7ec288
    clc
    .a16
    adc #$0038
    ldx $03
    sta a:$0002,X
    .a16
    lda #$0004
    jsr routine_7ec288
    clc
    .a16
    adc #$001C
    ldx $03
    sta a:$0006,X
    stz a:$0000,X
    jsr routine_7eb7b9
    lda $01
    dec
    asl
    clc
    adc a:$007C
    tax
    lda $03
    sta a:$0000,X
    dec $01
    bne construct_sixteen_warm_scene_sprites_946d
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
