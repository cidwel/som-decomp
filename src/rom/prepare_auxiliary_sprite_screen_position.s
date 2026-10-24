; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C4C9
prepare_auxiliary_sprite_screen_position:
    rep #$20
    lda a:$D001,Y
    .a16
    bit #$0080
    beq prepare_auxiliary_sprite_screen_position_c2c4fd
    rep #$20
    lda a:$D002,Y
    sec
    sbc $AC
    sta $04
    bcs prepare_auxiliary_sprite_screen_position_c2c4e8
    adc $C0
    .a16
    cmp #$0180
    bcs prepare_auxiliary_sprite_screen_position_c2c4e8
    sta $04
prepare_auxiliary_sprite_screen_position_c2c4e8:
    lda a:$D004,Y
    sec
    sbc $AE
    sta $06
    bcs prepare_auxiliary_sprite_screen_position_c2c525
    adc $C2
    .a16
    cmp #$0140
    bcs prepare_auxiliary_sprite_screen_position_c2c525
    sta $06
    bra prepare_auxiliary_sprite_screen_position_c2c525
prepare_auxiliary_sprite_screen_position_c2c4fd:
    rep #$20
    lda a:$D002,Y
    sec
    sbc $A8
    sta $04
    bcs prepare_auxiliary_sprite_screen_position_c2c512
    adc $C0
    .a16
    cmp #$0180
    bcs prepare_auxiliary_sprite_screen_position_c2c512
    sta $04
prepare_auxiliary_sprite_screen_position_c2c512:
    lda a:$D004,Y
    sec
    sbc $AA
    sta $06
    bcs prepare_auxiliary_sprite_screen_position_c2c525
    adc $C2
    .a16
    cmp #$0140
    bcs prepare_auxiliary_sprite_screen_position_c2c525
    sta $06
prepare_auxiliary_sprite_screen_position_c2c525:
    rts
