; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-colour-setup.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8fc7 = $8FC7
routine_7e90da = $90DA
routine_7eb081 = $B081

.segment "CODE"
.org $94BF
construct_warm_scene_colour_hdma_records:
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
    .i16
    ldx #$0031
    jsr routine_7eb081
    stx $03
    .i16
    ldy #$5ECD
    sty $05
    .a8
    lda #$7E
    sta $07
    .i16
    ldy #$51C0
    sty $08
    .a8
    lda #$7E
    sta $0A
    .i16
    ldy #$0000
    .a8
    lda #$10
    sta $01
construct_warm_scene_colour_hdma_records_94ed:
    lda [$05],Y
    sta a:$0000,X
    rep #$20
    lda [$08],Y
    sta a:$0001,X
    sep #$20
    inx
    inx
    inx
    iny
    iny
    dec $01
    bne construct_warm_scene_colour_hdma_records_94ed
    .a8
    lda #$00
    sta a:$0000,X
    .a8
    lda #$00
    xba
    .a8
    lda #$05
    jsr routine_7e8fc7
    .a8
    lda #$02
    sta a:$0000,X
    .a8
    lda #$22
    sta a:$0001,X
    .a8
    lda #$7F
    sta a:$0004,X
    php
    sei
    rep #$20
    lda $03
    sta a:$0002,X
    jsr routine_7e90da
    .a16
    lda #$0005
    jsr routine_7e8fc7
    .a16
    lda #$5ECD
    sta a:$0002,X
    sep #$20
    .a8
    lda #$00
    sta a:$0000,X
    .a8
    lda #$21
    sta a:$0001,X
    .a8
    lda #$7E
    sta a:$0004,X
    jsr routine_7e90da
    plp
    rep #$20
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
