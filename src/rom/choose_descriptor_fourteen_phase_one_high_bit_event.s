; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $5248
choose_descriptor_fourteen_phase_one_high_bit_event:
    ldx $87
    lda a:$007E,X
    .a16
    bit #$8000
    beq choose_descriptor_fourteen_phase_one_high_bit_event_c25256
    .a16
    lda #$D911
    rts
choose_descriptor_fourteen_phase_one_high_bit_event_c25256:
    .a16
    ora #$8000
    sta a:$007E,X
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$C2DADE,X
    clc
    rts
