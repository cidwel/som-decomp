; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-target-steering.md.
.setcpu "65816"
.smart
.a8
.i16

add_direction_table_acceleration_and_clamp_boss_velocity = $32BC
derive_eight_way_direction_to_low_byte_target = $0941
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $63AC
steer_native_boss_toward_nearest_target_with_capped_acceleration:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    .a16
    lda #$0004
    sta $1A
    .a16
    lda #$DC00
    sta $0D
    .a16
    lda #$E2F3
    sta $0C
    jsr add_direction_table_acceleration_and_clamp_boss_velocity
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    rts
