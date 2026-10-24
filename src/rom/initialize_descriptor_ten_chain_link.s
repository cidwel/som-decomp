; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $77D7
initialize_descriptor_ten_chain_link:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    ldy a:$00B0,X
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sta a:$0032,X
    .a16
    lda #$013C
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    sta a:$0000,X
    inc a:$0094,X
    .a16
    lda #$7938
    sta a:$0090,X
    clc
    rts
