; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller-pool.md.
.setcpu "65816"
.smart
.a8
.i16

add_direction_table_acceleration_and_clamp_boss_velocity = $32BC
derive_eight_way_direction_to_low_byte_target = $0941
test_parent_status_or_projectile_collision = $3F64

.segment "CODE"
.org $3F12
update_homing_projectile_reorientation_acceleration_and_parent_contact:
    ldx $87
    inc a:$00B2,X
    lda a:$00B2,X
    .a16
    cmp #$0003
    bcs update_homing_projectile_reorientation_acceleration_and_parent_contact_c23f3f
    stz a:$00B2,X
    lda a:$00A9,X
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
    lda #$E048
    sta $0C
    jsr add_direction_table_acceleration_and_clamp_boss_velocity
update_homing_projectile_reorientation_acceleration_and_parent_contact_c23f3f:
    lda a:$0032,X
    sta a:$0022,X
    jsr test_parent_status_or_projectile_collision
    bcs update_homing_projectile_reorientation_acceleration_and_parent_contact_c23f4b
    rts
update_homing_projectile_reorientation_acceleration_and_parent_contact_c23f4b:
    rts
