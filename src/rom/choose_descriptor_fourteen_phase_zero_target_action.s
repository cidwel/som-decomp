; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $51DC
choose_descriptor_fourteen_phase_zero_target_action:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$007E,X
    .a16
    bit #$8000
    beq choose_descriptor_fourteen_phase_zero_target_action_c251ff
    lda a:$00AB,X
    .a16
    cmp #$0001
    bne choose_descriptor_fourteen_phase_zero_target_action_c251ff
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0002
    bcs choose_descriptor_fourteen_phase_zero_target_action_c251ff
    .a16
    lda #$D916
    clc
    rts
choose_descriptor_fourteen_phase_zero_target_action_c251ff:
    lda a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    .a16
    cmp #$0004
    bcc choose_descriptor_fourteen_phase_zero_target_action_c2520f
    .a16
    lda #$D908
    clc
    rts
choose_descriptor_fourteen_phase_zero_target_action_c2520f:
    ldx $87
    lda a:$01B1,X
    .a16
    bit #$0040
    bne choose_descriptor_fourteen_phase_zero_target_action_c2521e
    .a16
    lda #$D906
    clc
    rts
choose_descriptor_fourteen_phase_zero_target_action_c2521e:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0190,Y
    bne choose_descriptor_fourteen_phase_zero_target_action_c2523b
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$C2DADA,X
    clc
    rts
choose_descriptor_fourteen_phase_zero_target_action_c2523b:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    .a16
    lda #$D902
    clc
    rts
