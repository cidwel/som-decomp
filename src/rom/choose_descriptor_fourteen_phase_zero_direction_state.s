; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $51A2
choose_descriptor_fourteen_phase_zero_direction_state:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$007E,X
    .a16
    bit #$8000
    beq choose_descriptor_fourteen_phase_zero_direction_state_c251b1
    .a16
    lda #$D902
    rts
choose_descriptor_fourteen_phase_zero_direction_state_c251b1:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_fourteen_phase_zero_direction_state_c251bd
    .a16
    lda #$D902
    rts
choose_descriptor_fourteen_phase_zero_direction_state_c251bd:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$C2DAD2,X
    rts
