; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-dirty-sprite-loop.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00b8c6 = $B8C6
routine_7eb081 = $B081
routine_7ec3bf = $C3BF

.segment "CODE"
.org $B840
begin_and_repeat_native_sprite_permutation_with_shared_counter:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    sep #$20
    .i16
    ldx #$0220
    jsr routine_7eb081
    .i16
    cpx #$0000
    beq routine_00b8c6
    stx $05
    txy
    ldx a:$02CC
    rep #$20
    .a16
    lda #$0220
    jsr routine_7ec3bf
    ldx a:$02CA
    .a16
    lda #$0020
    sta $01
begin_and_repeat_native_sprite_permutation_with_shared_counter_b86e:
    phx
    ldy a:$0000,X
    lda a:$000A,Y
    .a16
    and #$007F
    pha
    asl
    asl
    asl
    asl
    clc
    adc $05
    tay
    lda a:$0009,X
    pha
    asl
    asl
    asl
    asl
    clc
    adc a:$02CC
    tax
    .a16
    lda #$0008
    sta $03
begin_and_repeat_native_sprite_permutation_with_shared_counter_b893:
    lda a:$0000,Y
    sta a:$0000,X
    inx
    inx
    iny
    iny
    dec $01
    bne begin_and_repeat_native_sprite_permutation_with_shared_counter_b893
    pla
    clc
    adc a:$02CC
    tay
    pla
    clc
    adc $05
    tax
    sep #$20
    lda a:$0200,Y
    sta a:$0200,X
    rep #$20
    plx
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $01
    bne begin_and_repeat_native_sprite_permutation_with_shared_counter_b86e
