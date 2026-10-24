; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $6769
choose_descriptor_thirteen_variant_zero_target_status_action:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_descriptor_thirteen_variant_zero_target_status_action_c26790
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0190,Y
    bne choose_descriptor_thirteen_variant_zero_target_status_action_c26790
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE386,X
    clc
    rts
choose_descriptor_thirteen_variant_zero_target_status_action_c26790:
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE37E,X
    clc
    rts
