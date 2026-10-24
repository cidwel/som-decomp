; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-cluster-setup.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb6d0 = $B6D0
routine_7eb7b9 = $B7B9
routine_7ec288 = $C288

.segment "CODE"
.org $9373
construct_four_warm_scene_template_sprites:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    .a16
    lda #$0004
    sta $01
    lda a:$007E
    sta $05
    .a16
    lda #$0003
    jsr routine_7ec288
    sta $03
    asl
    clc
    adc $03
    asl
    asl
    sta $03
construct_four_warm_scene_template_sprites_9398:
    .a16
    lda #$000B
    jsr routine_7eb6d0
    txa
    ldy $05
    sta a:$0000,Y
    iny
    iny
    sty $05
    stz a:$0000,X
    stz a:$0002,X
    stz a:$0004,X
    stz a:$0006,X
    txy
    ldx $03
    sep #$20
    lda f:$7E5EEE,X
    clc
    .a8
    adc #$38
    sta a:$0002,Y
    inx
    lda f:$7E5EEE,X
    sta a:$0004,Y
    inx
    lda f:$7E5EEE,X
    .a8
    and #$3F
    sta a:$0006,Y
    lda f:$7E5EEE,X
    .a8
    and #$C0
    sta a:$0000,Y
    inx
    stx $03
    tyx
    jsr routine_7eb7b9
    rep #$20
    dec $01
    bne construct_four_warm_scene_template_sprites_9398
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
