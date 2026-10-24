; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $6E82
choose_descriptor_eight_action_toggle_or_abort:
    lda a:$007E,X
    .a16
    bit #$0001
    bne choose_descriptor_eight_action_toggle_or_abort_c26eae
    .a16
    eor #$8000
    sta a:$007E,X
    bmi choose_descriptor_eight_action_toggle_or_abort_c26ea0
    .a16
    lda #$0006
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE489,X
    clc
    rts
choose_descriptor_eight_action_toggle_or_abort_c26ea0:
    .a16
    lda #$0008
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE497,X
    clc
    rts
choose_descriptor_eight_action_toggle_or_abort_c26eae:
    .a16
    bit #$8000
    bne choose_descriptor_eight_action_toggle_or_abort_c26eb8
    .a16
    lda #$E894
    clc
    rts
choose_descriptor_eight_action_toggle_or_abort_c26eb8:
    sec
    rts
