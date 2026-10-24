; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $6B33
choose_descriptor_four_state_pointer:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$007E,X
    bne choose_descriptor_four_state_pointer_c26b53
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq choose_descriptor_four_state_pointer_c26b4f
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE3E0,X
    rts
choose_descriptor_four_state_pointer_c26b4f:
    .a16
    lda #$E5D6
    rts
choose_descriptor_four_state_pointer_c26b53:
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    beq choose_descriptor_four_state_pointer_c26b5f
    .a16
    lda #$E5DC
    rts
choose_descriptor_four_state_pointer_c26b5f:
    .a16
    lda #$E5D9
    rts
