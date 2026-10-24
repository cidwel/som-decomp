; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one.md.
.setcpu "65816"
.smart
.a8
.i16

derive_clamped_target_distance_minus_one = $08BC
derive_four_way_direction_to_low_byte_target = $091D
draw_boss_frame_random_number = $300B
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $42E8
choose_descriptor_one_state_by_distance_direction_and_rng:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0002
    bcs choose_descriptor_one_state_by_distance_direction_and_rng_c24318
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    and #$00FF
    beq choose_descriptor_one_state_by_distance_direction_and_rng_c24324
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE166,X
    rts
choose_descriptor_one_state_by_distance_direction_and_rng_c24318:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE176,X
    rts
choose_descriptor_one_state_by_distance_direction_and_rng_c24324:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE16E,X
    rts
