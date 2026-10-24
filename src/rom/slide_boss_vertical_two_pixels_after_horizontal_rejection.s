; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $152B
slide_boss_vertical_two_pixels_after_horizontal_rejection:
    lda a:$004E,X
    .a16
    bit #$0002
    bne slide_boss_vertical_two_pixels_after_horizontal_rejection_c21552
    lda a:$0032,X
    clc
    .a16
    adc #$0002
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs slide_boss_vertical_two_pixels_after_horizontal_rejection_c21547
    jsr test_animation_movement_against_three_active_party_actors
    bcc slide_boss_vertical_two_pixels_after_horizontal_rejection_c21551
slide_boss_vertical_two_pixels_after_horizontal_rejection_c21547:
    lda a:$0032,X
    sec
    .a16
    sbc #$0002
    sta a:$0032,X
slide_boss_vertical_two_pixels_after_horizontal_rejection_c21551:
    rts
slide_boss_vertical_two_pixels_after_horizontal_rejection_c21552:
    lda a:$0032,X
    clc
    .a16
    adc #$FFFE
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs slide_boss_vertical_two_pixels_after_horizontal_rejection_c21566
    jsr test_animation_movement_against_three_active_party_actors
    bcc slide_boss_vertical_two_pixels_after_horizontal_rejection_c21570
slide_boss_vertical_two_pixels_after_horizontal_rejection_c21566:
    lda a:$0032,X
    sec
    .a16
    sbc #$FFFE
    sta a:$0032,X
slide_boss_vertical_two_pixels_after_horizontal_rejection_c21570:
    rts
