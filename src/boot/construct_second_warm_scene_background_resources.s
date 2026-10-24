; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e809b = $809B
routine_7e8fc7 = $8FC7
routine_7e90da = $90DA
routine_7ebbab = $BBAB
routine_7ebbfe = $BBFE
routine_7ebc9a = $BC9A
routine_7ec76d = $C76D
routine_7ec870 = $C870

.segment "CODE"
.org $CA65
construct_second_warm_scene_background_resources:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    .a16
    lda #$0042
    .i16
    ldx #$0011
    jsr routine_7e809b
    stx $07
    .a16
    lda #$0001
    jsr routine_7e8fc7
    lda $07
    sta a:$000A,X
    .a16
    lda #$57C0
    sta a:$0002,X
    .a16
    lda #$0220
    sta a:$0005,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    jsr routine_7e90da
    .a8
    lda #$00
    jsr routine_7ebbab
    phx
    .a8
    lda #$7E
    xba
    .a8
    lda #$1E
    .i16
    ldy #$51A0
    jsr routine_7ebc9a
    plx
    jsr routine_7ebbfe
    asl
    asl
    .a8
    ora #$20
    sta $06
    rep #$20
    .a16
    lda #$0010
    jsr routine_7ec76d
    stx $03
    txy
    .i16
    ldx #$0000
    sep #$20
    .a8
    lda #$1D
    sta $01
construct_second_warm_scene_background_resources_cacb:
    .a8
    lda #$20
    sta $09
    lda $05
construct_second_warm_scene_background_resources_cad1:
    lda f:$7E60C8,X
    inx
    sta a:$0000,Y
    iny
    lda $06
    sta a:$0000,Y
    iny
    dec $09
    bne construct_second_warm_scene_background_resources_cad1
    dec $01
    bne construct_second_warm_scene_background_resources_cacb
    ldx $03
    jsr routine_7ec870
    rep #$20
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
