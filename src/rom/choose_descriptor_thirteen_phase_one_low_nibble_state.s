; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $6713
choose_descriptor_thirteen_phase_one_low_nibble_state:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne choose_descriptor_thirteen_phase_one_low_nibble_state_c2672c
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE356,X
    rts
choose_descriptor_thirteen_phase_one_low_nibble_state_c2672c:
    ldx $87
    lda a:$007E,X
    .a16
    and #$000F
    asl
    tax
    lda f:$DCE372,X
    ldx $87
    rts
