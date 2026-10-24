; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16

add_direction_table_acceleration_and_clamp_boss_velocity = $32BC
advance_descriptor_eleven_sine_height_with_fractional_carry = $8CFB
move_projectile_by_velocity_and_prepare_terrain = $3F4C

.segment "CODE"
.org $8D29
accelerate_descriptor_eleven_and_update_height_then_simple_terrain_motion:
    .a16
    lda #$0002
    sta $1A
    .a16
    lda #$DC00
    sta $0D
    .a16
    lda #$E5DB
    sta $0C
    jsr add_direction_table_acceleration_and_clamp_boss_velocity
    jsr advance_descriptor_eleven_sine_height_with_fractional_carry
    jsr move_projectile_by_velocity_and_prepare_terrain
    rts
