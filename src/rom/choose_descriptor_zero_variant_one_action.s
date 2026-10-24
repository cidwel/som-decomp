; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16

derive_clamped_target_distance_minus_one = $08BC
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $3DDB
choose_descriptor_zero_variant_one_action:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0003
    bcc choose_descriptor_zero_variant_one_action_c23e06
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_zero_variant_one_action_c23df8
    .a16
    lda #$D0BA
    clc
    rts
choose_descriptor_zero_variant_one_action_c23df8:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE020,X
    clc
    rts
choose_descriptor_zero_variant_one_action_c23e06:
    .a16
    cmp #$0002
    bcc choose_descriptor_zero_variant_one_action_c23e19
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE024,X
    clc
    rts
choose_descriptor_zero_variant_one_action_c23e19:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE010,X
    clc
    rts
