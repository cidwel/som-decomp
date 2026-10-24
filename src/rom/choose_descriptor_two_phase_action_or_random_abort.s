; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
request_descriptor_two_half_hp_phase_and_height = $3FB5
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $3FD9
choose_descriptor_two_phase_action_or_random_abort:
    lda a:$007E,X
    bne choose_descriptor_two_phase_action_or_random_abort_c24033
    jsr request_descriptor_two_half_hp_phase_and_height
    bcs choose_descriptor_two_phase_action_or_random_abort_c24033
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcc choose_descriptor_two_phase_action_or_random_abort_c24000
    .a16
    lda #$0000
    jsr draw_boss_frame_random_number
    bne choose_descriptor_two_phase_action_or_random_abort_c23ffe
    .a16
    lda #$D25C
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c23ffe:
    sec
    rts
choose_descriptor_two_phase_action_or_random_abort_c24000:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    and #$00FF
    bne choose_descriptor_two_phase_action_or_random_abort_c24018
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE078,X
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c24018:
    .a16
    cmp #$0001
    bne choose_descriptor_two_phase_action_or_random_abort_c24028
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE080,X
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c24028:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE088,X
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c24033:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcc choose_descriptor_two_phase_action_or_random_abort_c24050
    .a16
    lda #$0000
    jsr draw_boss_frame_random_number
    bne choose_descriptor_two_phase_action_or_random_abort_c2404e
    .a16
    lda #$D270
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c2404e:
    sec
    rts
choose_descriptor_two_phase_action_or_random_abort_c24050:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    and #$00FF
    bne choose_descriptor_two_phase_action_or_random_abort_c24068
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE090,X
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c24068:
    .a16
    cmp #$0001
    bne choose_descriptor_two_phase_action_or_random_abort_c24078
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE098,X
    clc
    rts
choose_descriptor_two_phase_action_or_random_abort_c24078:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE0A0,X
    clc
    rts
