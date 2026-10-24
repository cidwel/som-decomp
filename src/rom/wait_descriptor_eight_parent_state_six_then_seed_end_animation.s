; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6FE9
wait_descriptor_eight_parent_state_six_then_seed_end_animation:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcc wait_descriptor_eight_parent_state_six_then_seed_end_animation_c26fff
    .a16
    lda #$0133
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
wait_descriptor_eight_parent_state_six_then_seed_end_animation_c26fff:
    clc
    rts
