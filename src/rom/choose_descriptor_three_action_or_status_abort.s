; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three.md.
.setcpu "65816"
.smart
.a8
.i16

derive_clamped_target_distance_minus_one = $08BC
derive_four_way_direction_to_low_byte_target = $091D
draw_boss_frame_random_number = $300B
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $630F
choose_descriptor_three_action_or_status_abort:
    ldx $87
    lda $C7
    sta a:$007E,X
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    .a16
    cmp #$0001
    bne choose_descriptor_three_action_or_status_abort_c26341
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0003
    bcs choose_descriptor_three_action_or_status_abort_c26341
    ldx $87
    lda a:$0042,X
    asl
    tax
    lda f:$DCE2BD,X
    clc
    rts
choose_descriptor_three_action_or_status_abort_c26341:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_three_action_or_status_abort_c26356
    ldx $87
    lda a:$0042,X
    asl
    tax
    lda f:$DCE2B7,X
    clc
    rts
choose_descriptor_three_action_or_status_abort_c26356:
    ldx $87
    lda a:$0042,X
    bne choose_descriptor_three_action_or_status_abort_c2636b
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE2A9,X
    clc
    rts
choose_descriptor_three_action_or_status_abort_c2636b:
    .a16
    cmp #$0002
    beq choose_descriptor_three_action_or_status_abort_c2637e
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE2AD,X
    clc
    rts
choose_descriptor_three_action_or_status_abort_c2637e:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE2B1,X
    .a16
    cmp #$DFD4
    bne choose_descriptor_three_action_or_status_abort_c263a3
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0190,Y
    bne choose_descriptor_three_action_or_status_abort_c263a5
    .a16
    lda #$DFD4
choose_descriptor_three_action_or_status_abort_c263a3:
    clc
    rts
choose_descriptor_three_action_or_status_abort_c263a5:
    stz a:$007E,X
    sec
    rts
