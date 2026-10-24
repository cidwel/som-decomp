; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16

compare_target_axis_proximity_with_literal_early_return = $3A63
compute_capped_boss_maximum_over_current_hp_ratio = $09B4
derive_clamped_target_distance_minus_one = $08BC
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $60CE
choose_descriptor_five_target_hold_or_hp_fallback:
    ldx $87
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
    .a16
    cmp #$0002
    bcs choose_descriptor_five_target_hold_or_hp_fallback_c260fb
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_five_target_hold_or_hp_fallback_c260f3
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE27A,X
    clc
    rts
choose_descriptor_five_target_hold_or_hp_fallback_c260f3:
    ldx $87
    lda a:$00A9,X
    jsr derive_clamped_target_distance_minus_one
choose_descriptor_five_target_hold_or_hp_fallback_c260fb:
    .a16
    cmp #$0004
    bcs choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$00A9,X
    jsr compare_target_axis_proximity_with_literal_early_return
    bcs choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$0020,X
    .a16
    cmp #$0040
    bcc choose_descriptor_five_target_hold_or_hp_fallback_c26157
    .a16
    cmp #$00C0
    bcs choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$0022,X
    .a16
    cmp #$0040
    bcc choose_descriptor_five_target_hold_or_hp_fallback_c26157
    .a16
    cmp #$00A0
    bcs choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$000B,Y
    cmp a:$000B,X
    bne choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$0060,Y
    bne choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$000E,Y
    bne choose_descriptor_five_target_hold_or_hp_fallback_c26157
    lda a:$01E5,Y
    .a16
    cmp #$0024
    beq choose_descriptor_five_target_hold_or_hp_fallback_c26157
    .a16
    lda #$0002
    sta a:$007E,X
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE29A,X
    clc
    rts
choose_descriptor_five_target_hold_or_hp_fallback_c26157:
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcc choose_descriptor_five_target_hold_or_hp_fallback_c2616e
    lda a:$0042,X
    bne choose_descriptor_five_target_hold_or_hp_fallback_c26169
    .a16
    lda #$DD84
    clc
    rts
choose_descriptor_five_target_hold_or_hp_fallback_c26169:
    .a16
    lda #$DD92
    clc
    rts
choose_descriptor_five_target_hold_or_hp_fallback_c2616e:
    sec
    rts
