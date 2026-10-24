; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16

compute_capped_boss_maximum_over_current_hp_ratio = $09B4
derive_eight_way_direction_to_low_byte_target = $0941
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B

.segment "CODE"
.org $54C7
choose_descriptor_twelve_variant_one_hp_event_or_phase_action:
    ldx $87
    lda a:$00BE,X
    bne choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c254e3
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    ldx $87
    .a16
    cmp #$0003
    bcc choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c254e3
    .a16
    lda #$0001
    sta a:$00BE,X
    .a16
    lda #$DB38
    clc
    rts
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c254e3:
    ldx $87
    lda a:$007E,X
    bne choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2553d
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    bne choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2550b
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
    lda f:$DCE270,X
    clc
    rts
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2550b:
    ldx $87
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2552f
    ldx $87
    lda a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    .a16
    cmp #$0003
    bcc choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2552a
    .a16
    cmp #$0007
    bcc choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2552f
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2552a:
    .a16
    lda #$DB26
    clc
    rts
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2552f:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE26C,X
    clc
    rts
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2553d:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2555d
    ldx $87
    lda a:$0034,X
    .a16
    bit #$0060
    bne choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2555d
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE274,X
    clc
    rts
choose_descriptor_twelve_variant_one_hp_event_or_phase_action_c2555d:
    ldx $87
    lda a:$0034,X
    .a16
    and #$FF0F
    sta a:$0034,X
    .a16
    lda #$DB48
    clc
    rts
