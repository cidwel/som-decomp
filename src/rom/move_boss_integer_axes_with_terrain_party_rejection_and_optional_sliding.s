; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
slide_boss_horizontal_two_pixels_after_vertical_rejection = $1571
slide_boss_vertical_two_pixels_after_horizontal_rejection = $152B
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $0A47
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding:
    sta $C3
    lda a:$002B,X
    clc
    adc a:$003C,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a5d
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a71
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a5d:
    lda a:$002B,X
    sec
    sbc a:$003C,X
    sta a:$002B,X
    lda $C3
    .a16
    bit #$0001
    bne move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a71
    jsr slide_boss_vertical_two_pixels_after_horizontal_rejection
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a71:
    lda a:$0032,X
    clc
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a85
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a99
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a85:
    lda a:$0032,X
    sec
    sbc a:$0040,X
    sta a:$0032,X
    lda $C3
    .a16
    bit #$0001
    bne move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a99
    jsr slide_boss_horizontal_two_pixels_after_vertical_rejection
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding_c20a99:
    rts
