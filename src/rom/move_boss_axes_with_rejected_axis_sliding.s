; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-rebound-landing.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
slide_boss_horizontal_two_pixels_after_vertical_rejection = $1571
slide_boss_vertical_two_pixels_after_horizontal_rejection = $152B
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $36BC
move_boss_axes_with_rejected_axis_sliding:
    lda a:$002B,X
    clc
    adc a:$003C,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_boss_axes_with_rejected_axis_sliding_c236d0
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_axes_with_rejected_axis_sliding_c236dd
move_boss_axes_with_rejected_axis_sliding_c236d0:
    lda a:$002B,X
    sec
    sbc a:$003C,X
    sta a:$002B,X
    jsr slide_boss_vertical_two_pixels_after_horizontal_rejection
move_boss_axes_with_rejected_axis_sliding_c236dd:
    lda a:$0032,X
    clc
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_boss_axes_with_rejected_axis_sliding_c236f1
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_axes_with_rejected_axis_sliding_c236fe
move_boss_axes_with_rejected_axis_sliding_c236f1:
    lda a:$0032,X
    sec
    sbc a:$0040,X
    sta a:$0032,X
    jsr slide_boss_horizontal_two_pixels_after_vertical_rejection
move_boss_axes_with_rejected_axis_sliding_c236fe:
    rts
