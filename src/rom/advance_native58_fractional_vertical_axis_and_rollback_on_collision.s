; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
scan_native58_party_collision_and_mark_party_action_bytes = $7E39

.segment "CODE"
.org $7E08
advance_native58_fractional_vertical_axis_and_rollback_on_collision:
    lda a:$0030,X
    clc
    adc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs advance_native58_fractional_vertical_axis_and_rollback_on_collision_c27e25
    jsr scan_native58_party_collision_and_mark_party_action_bytes
    bcc advance_native58_fractional_vertical_axis_and_rollback_on_collision_c27e38
advance_native58_fractional_vertical_axis_and_rollback_on_collision_c27e25:
    lda a:$0030,X
    sec
    sbc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    sbc a:$0040,X
    sta a:$0032,X
advance_native58_fractional_vertical_axis_and_rollback_on_collision_c27e38:
    rts
