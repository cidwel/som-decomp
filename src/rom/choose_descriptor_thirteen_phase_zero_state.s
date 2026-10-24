; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $66EB
choose_descriptor_thirteen_phase_zero_state:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne choose_descriptor_thirteen_phase_zero_state_c26704
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE356,X
    rts
choose_descriptor_thirteen_phase_zero_state_c26704:
    ldx $87
    .a16
    lda #$0005
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE366,X
    rts
