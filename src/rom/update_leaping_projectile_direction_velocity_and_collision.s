; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

add_direction_table_acceleration_and_clamp_boss_velocity = $32BC
derive_eight_way_direction_from_coordinate_pairs = $2E50
derive_eight_way_direction_to_low_byte_target = $0941
prepare_boss_loader_resource_expansion = $24C3
select_boss_animation_and_reset_frame_cursor = $1394
test_parent_status_or_projectile_collision = $3F64

.segment "CODE"
.org $7480
update_leaping_projectile_direction_velocity_and_collision:
    ldx $87
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
    lda #$E545
    sta $0C
    jsr add_direction_table_acceleration_and_clamp_boss_velocity
    lda a:$003C,X
    sta $46
    lda a:$0040,X
    sta $4E
    stz $56
    stz $5E
    jsr derive_eight_way_direction_from_coordinate_pairs
    asl
    tax
    lda f:$DCE535,X
    sta $97
    lda f:$DCE525,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $97
    sta a:$0098,X
    lda a:$0032,X
    sta a:$0022,X
    jsr test_parent_status_or_projectile_collision
    bcs update_leaping_projectile_direction_velocity_and_collision_c274d8
    rts
update_leaping_projectile_direction_velocity_and_collision_c274d8:
    .a16
    lda #$015C
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0027
    jsr prepare_boss_loader_resource_expansion
    ldx $87
    inc a:$0094,X
    stz a:$0090,X
    clc
    rts
