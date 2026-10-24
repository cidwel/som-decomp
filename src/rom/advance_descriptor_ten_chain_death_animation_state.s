; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7886
advance_descriptor_ten_chain_death_animation_state:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$9811
    sta a:$0098,X
    .a16
    lda #$015C
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    clc
    rts
