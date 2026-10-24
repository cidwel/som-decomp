; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7F3C
wait_left_child_initial_sixty_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$003C
    bcc wait_left_child_initial_sixty_ticks_c27f52
    .a16
    lda #$011A
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    stz a:$0096,X
wait_left_child_initial_sixty_ticks_c27f52:
    clc
    rts
