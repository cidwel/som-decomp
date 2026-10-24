; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $6DFB
choose_descriptor_eight_state_from_phase_bits_direction_and_rng:
    lda a:$007E,X
    .a16
    bit #$0001
    bne choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e33
    .a16
    lda #$0004
    jsr draw_boss_frame_random_number
    beq choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e2f
    ldx $87
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0008
    bcs choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e25
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE461,X
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e25:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE469,X
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e2f:
    .a16
    lda #$E85C
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e33:
    ldx $87
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$007E,X
    .a16
    bit #$8000
    bne choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e67
    .a16
    lda #$0004
    jsr draw_boss_frame_random_number
    beq choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e63
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE479,X
    beq choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e56
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e56:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE471,X
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e63:
    .a16
    lda #$E860
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e67:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE481,X
    beq choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e75
    rts
choose_descriptor_eight_state_from_phase_bits_direction_and_rng_c26e75:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE475,X
    rts
