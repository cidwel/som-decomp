; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-six.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
request_descriptor_two_half_hp_phase_and_height = $3FB5
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $4235
choose_descriptor_six_phase_action_or_random_abort:
    lda a:$007E,X
    bne choose_descriptor_six_phase_action_or_random_abort_c24289
    jsr request_descriptor_two_half_hp_phase_and_height
    bcs choose_descriptor_six_phase_action_or_random_abort_c24289
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcc choose_descriptor_six_phase_action_or_random_abort_c2425c
    .a16
    lda #$0000
    jsr draw_boss_frame_random_number
    bne choose_descriptor_six_phase_action_or_random_abort_c2425a
    .a16
    lda #$D4B3
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c2425a:
    sec
    rts
choose_descriptor_six_phase_action_or_random_abort_c2425c:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    and #$00FF
    bne choose_descriptor_six_phase_action_or_random_abort_c24274
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE146,X
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c24274:
    .a16
    cmp #$0001
    bne choose_descriptor_six_phase_action_or_random_abort_c24284
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE14E,X
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c24284:
    .a16
    lda #$D4B5
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c24289:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcc choose_descriptor_six_phase_action_or_random_abort_c242a6
    .a16
    lda #$0000
    jsr draw_boss_frame_random_number
    bne choose_descriptor_six_phase_action_or_random_abort_c242a4
    .a16
    lda #$D4CB
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c242a4:
    sec
    rts
choose_descriptor_six_phase_action_or_random_abort_c242a6:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    and #$00FF
    bne choose_descriptor_six_phase_action_or_random_abort_c242be
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE156,X
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c242be:
    .a16
    cmp #$0001
    bne choose_descriptor_six_phase_action_or_random_abort_c242ce
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE15E,X
    clc
    rts
choose_descriptor_six_phase_action_or_random_abort_c242ce:
    .a16
    lda #$D4CD
    clc
    rts
