; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $679E
choose_descriptor_thirteen_variant_one_random_action:
    .a16
    lda #$0006
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE38A,X
    clc
    rts
