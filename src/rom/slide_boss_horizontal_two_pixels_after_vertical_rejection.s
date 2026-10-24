; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $1571
slide_boss_horizontal_two_pixels_after_vertical_rejection:
    lda a:$004E,X
    .a16
    bit #$0001
    bne slide_boss_horizontal_two_pixels_after_vertical_rejection_c21598
    lda a:$002B,X
    clc
    .a16
    adc #$0002
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs slide_boss_horizontal_two_pixels_after_vertical_rejection_c2158d
    jsr test_animation_movement_against_three_active_party_actors
    bcc slide_boss_horizontal_two_pixels_after_vertical_rejection_c21597
slide_boss_horizontal_two_pixels_after_vertical_rejection_c2158d:
    lda a:$002B,X
    sec
    .a16
    sbc #$0002
    sta a:$002B,X
slide_boss_horizontal_two_pixels_after_vertical_rejection_c21597:
    rts
slide_boss_horizontal_two_pixels_after_vertical_rejection_c21598:
    lda a:$002B,X
    clc
    .a16
    adc #$FFFE
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs slide_boss_horizontal_two_pixels_after_vertical_rejection_c215ac
    jsr test_animation_movement_against_three_active_party_actors
    bcc slide_boss_horizontal_two_pixels_after_vertical_rejection_c215b6
slide_boss_horizontal_two_pixels_after_vertical_rejection_c215ac:
    lda a:$002B,X
    sec
    .a16
    sbc #$FFFE
    sta a:$002B,X
slide_boss_horizontal_two_pixels_after_vertical_rejection_c215b6:
    rts
