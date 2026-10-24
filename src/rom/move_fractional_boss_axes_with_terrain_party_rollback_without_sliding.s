; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-fractional-motion.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $0A9A
move_fractional_boss_axes_with_terrain_party_rollback_without_sliding:
    sta $C3
    lda a:$0029,X
    clc
    adc a:$003A,X
    sta a:$0029,X
    lda a:$002B,X
    adc a:$003C,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20ab9
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20acc
move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20ab9:
    lda a:$0029,X
    sec
    sbc a:$003A,X
    sta a:$0029,X
    lda a:$002B,X
    sbc a:$003C,X
    sta a:$002B,X
move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20acc:
    lda a:$0030,X
    clc
    adc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20ae9
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20afc
move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20ae9:
    lda a:$0030,X
    sec
    sbc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    sbc a:$0040,X
    sta a:$0032,X
move_fractional_boss_axes_with_terrain_party_rollback_without_sliding_c20afc:
    rts
