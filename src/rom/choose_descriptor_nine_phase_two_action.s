; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $65AF
choose_descriptor_nine_phase_two_action:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE338,X
    clc
    rts
