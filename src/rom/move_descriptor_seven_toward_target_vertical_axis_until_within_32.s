; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47

.segment "CODE"
.org $734B
move_descriptor_seven_toward_target_vertical_axis_until_within_32:
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bmi move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27365
    .a16
    cmp #$0020
    bcc move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27386
move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27365:
    lda a:$0004,Y
    sec
    sbc a:$0032,X
    bmi move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27376
    .a16
    lda #$0002
    sta a:$0040,X
    bra move_descriptor_seven_toward_target_vertical_axis_until_within_32_c2737c
move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27376:
    .a16
    lda #$FFFE
    sta a:$0040,X
move_descriptor_seven_toward_target_vertical_axis_until_within_32_c2737c:
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    stz a:$0040,X
    clc
    rts
move_descriptor_seven_toward_target_vertical_axis_until_within_32_c27386:
    sec
    rts
