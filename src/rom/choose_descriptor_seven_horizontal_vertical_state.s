; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16

select_alive_hero_nearest_on_vertical_axis = $7303

.segment "CODE"
.org $70C5
choose_descriptor_seven_horizontal_vertical_state:
    jsr select_alive_hero_nearest_on_vertical_axis
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0004,Y
    sta $97
    lda a:$0002,Y
    sta $95
    sec
    sbc a:$002B,X
    bpl choose_descriptor_seven_horizontal_vertical_state_c270f9
    lda a:$0032,X
    sec
    sbc $97
    sta $99
    bmi choose_descriptor_seven_horizontal_vertical_state_c270f5
    .a16
    cmp #$0020
    bcs choose_descriptor_seven_horizontal_vertical_state_c270f5
    .a16
    lda #$EB6F
    rts
choose_descriptor_seven_horizontal_vertical_state_c270f5:
    .a16
    lda #$EB73
    rts
choose_descriptor_seven_horizontal_vertical_state_c270f9:
    lda a:$0032,X
    sec
    sbc $97
    sta $99
    bmi choose_descriptor_seven_horizontal_vertical_state_c2710c
    .a16
    cmp #$0020
    bcs choose_descriptor_seven_horizontal_vertical_state_c2710c
    .a16
    lda #$EB6D
    rts
choose_descriptor_seven_horizontal_vertical_state_c2710c:
    .a16
    lda #$EB71
    rts
