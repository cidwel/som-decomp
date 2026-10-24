; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-rebound-landing.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $5612
move_boss_axes_and_reflect_velocity_when_rejected:
    lda a:$002B,X
    clc
    adc a:$003C,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_boss_axes_and_reflect_velocity_when_rejected_c25626
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_axes_and_reflect_velocity_when_rejected_c2563a
move_boss_axes_and_reflect_velocity_when_rejected_c25626:
    lda a:$002B,X
    sec
    sbc a:$003C,X
    sta a:$002B,X
    lda a:$003C,X
    .a16
    eor #$FFFF
    inc
    sta a:$003C,X
move_boss_axes_and_reflect_velocity_when_rejected_c2563a:
    lda a:$0032,X
    clc
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_boss_axes_and_reflect_velocity_when_rejected_c2564e
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_axes_and_reflect_velocity_when_rejected_c25662
move_boss_axes_and_reflect_velocity_when_rejected_c2564e:
    lda a:$0032,X
    sec
    sbc a:$0040,X
    sta a:$0032,X
    lda a:$0040,X
    .a16
    eor #$FFFF
    inc
    sta a:$0040,X
move_boss_axes_and_reflect_velocity_when_rejected_c25662:
    rts
