; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16

derive_clamped_target_distance_minus_one = $08BC
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $3D5A
choose_descriptor_zero_state_from_target_distance_and_direction:
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0002
    bcs choose_descriptor_zero_state_from_target_distance_and_direction_c23d80
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_zero_state_from_target_distance_and_direction_c23d80
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_zero_state_from_target_distance_and_direction_c23d7c
    .a16
    lda #$D0AA
    rts
choose_descriptor_zero_state_from_target_distance_and_direction_c23d7c:
    .a16
    lda #$D09E
    rts
choose_descriptor_zero_state_from_target_distance_and_direction_c23d80:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE000,X
    rts
