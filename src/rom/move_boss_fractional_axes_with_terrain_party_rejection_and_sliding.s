; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
slide_boss_horizontal_two_pixels_after_vertical_rejection = $1571
slide_boss_vertical_two_pixels_after_horizontal_rejection = $152B
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $36FF
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding:
    lda a:$0029,X
    clc
    adc a:$003A,X
    sta a:$0029,X
    lda a:$002B,X
    adc a:$003C,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c2371c
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c23732
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c2371c:
    lda a:$0029,X
    sec
    sbc a:$003A,X
    sta a:$0029,X
    lda a:$002B,X
    sbc a:$003C,X
    sta a:$002B,X
    jsr slide_boss_vertical_two_pixels_after_horizontal_rejection
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c23732:
    lda a:$0030,X
    clc
    adc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c2374f
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c23765
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c2374f:
    lda a:$0030,X
    sec
    sbc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    sbc a:$0040,X
    sta a:$0032,X
    jsr slide_boss_horizontal_two_pixels_after_vertical_rejection
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding_c23765:
    rts
