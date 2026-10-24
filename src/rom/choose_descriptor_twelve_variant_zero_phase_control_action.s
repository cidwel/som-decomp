; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B

.segment "CODE"
.org $543D
choose_descriptor_twelve_variant_zero_phase_control_action:
    ldx $87
    lda a:$007E,X
    bne choose_descriptor_twelve_variant_zero_phase_control_action_c25497
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    bne choose_descriptor_twelve_variant_zero_phase_control_action_c25465
    ldx $87
    lda a:$0034,X
    .a16
    and #$FF0F
    sta a:$0034,X
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE262,X
    clc
    rts
choose_descriptor_twelve_variant_zero_phase_control_action_c25465:
    ldx $87
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_twelve_variant_zero_phase_control_action_c25489
    ldx $87
    lda a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    .a16
    cmp #$0003
    bcc choose_descriptor_twelve_variant_zero_phase_control_action_c25484
    .a16
    cmp #$0007
    bcc choose_descriptor_twelve_variant_zero_phase_control_action_c25489
choose_descriptor_twelve_variant_zero_phase_control_action_c25484:
    .a16
    lda #$DB26
    clc
    rts
choose_descriptor_twelve_variant_zero_phase_control_action_c25489:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE25E,X
    clc
    rts
choose_descriptor_twelve_variant_zero_phase_control_action_c25497:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_twelve_variant_zero_phase_control_action_c254b7
    ldx $87
    lda a:$0034,X
    .a16
    bit #$0060
    bne choose_descriptor_twelve_variant_zero_phase_control_action_c254b7
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE266,X
    clc
    rts
choose_descriptor_twelve_variant_zero_phase_control_action_c254b7:
    ldx $87
    lda a:$0034,X
    .a16
    and #$FF0F
    sta a:$0034,X
    .a16
    lda #$DB29
    clc
    rts
