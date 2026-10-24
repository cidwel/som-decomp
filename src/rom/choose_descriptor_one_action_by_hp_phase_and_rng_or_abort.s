; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one.md.
.setcpu "65816"
.smart
.a8
.i16

compare_target_axis_proximity_with_literal_early_return = $3A63
derive_clamped_target_distance_minus_one = $08BC
derive_four_way_direction_to_low_byte_target = $091D
draw_boss_frame_random_number = $300B
request_descriptor_one_phase_eight_at_half_hp = $4330
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $4341
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort:
    lda a:$007E,X
    bne choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c24356
    jsr request_descriptor_one_phase_eight_at_half_hp
    bcc choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c24356
    lda a:$0042,X
    asl
    tax
    lda f:$DCE17E,X
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c24356:
    lda a:$0042,X
    asl
    asl
    asl
    asl
    clc
    adc a:$007E,X
    sta a:$0358
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0001
    bcs choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2439f
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2439f
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    sta $1A
    ldx $87
    lda a:$0042,X
    asl
    asl
    clc
    adc $1A
    tax
    lda f:$DCE182,X
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2439f:
    .a16
    cmp #$0002
    bcs choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243ce
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    beq choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243bd
    ldx $87
    lda a:$00AB,X
    asl
    clc
    adc a:$0358
    tax
    lda f:$DCE18A,X
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243bd:
    ldx $87
    lda a:$00AB,X
    asl
    clc
    adc a:$0358
    tax
    lda f:$DCE1AA,X
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243ce:
    lda a:$00A9,X
    jsr compare_target_axis_proximity_with_literal_early_return
    bcs choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243e9
    ldx $87
    lda a:$00AB,X
    asl
    clc
    adc a:$0358
    tax
    lda f:$DCE1CA,X
    beq choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243e9
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243e9:
    .a16
    lda #$0010
    jsr draw_boss_frame_random_number
    bne choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2440f
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243fe
    .a16
    lda #$D6A3
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c243fe:
    ldx $87
    lda a:$0042,X
    bne choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2440a
    .a16
    lda #$D6A5
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2440a:
    .a16
    lda #$D6C8
    clc
    rts
choose_descriptor_one_action_by_hp_phase_and_rng_or_abort_c2440f:
    sec
    rts
