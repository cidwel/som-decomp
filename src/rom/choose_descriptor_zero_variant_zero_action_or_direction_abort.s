; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16

derive_clamped_target_distance_minus_one = $08BC
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $3D98
choose_descriptor_zero_variant_zero_action_or_direction_abort:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$00AB,X
    .a16
    cmp #$0006
    bne choose_descriptor_zero_variant_zero_action_or_direction_abort_c23da7
    sec
    rts
choose_descriptor_zero_variant_zero_action_or_direction_abort_c23da7:
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0004
    bcc choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dc4
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dbf
    .a16
    lda #$D0BA
    clc
    rts
choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dbf:
    .a16
    lda #$D0BD
    clc
    rts
choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dc4:
    .a16
    cmp #$0003
    bcc choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dce
    .a16
    lda #$D0BF
    clc
    rts
choose_descriptor_zero_variant_zero_action_or_direction_abort_c23dce:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE010,X
    clc
    rts
