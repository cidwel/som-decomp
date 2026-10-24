; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7F8A
recover_left_child_after_twenty_four_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc recover_left_child_after_twenty_four_ticks_c27fb3
    lda a:$0190,X
    bmi recover_left_child_after_twenty_four_ticks_c27fa7
    dec a:$0094,X
    .a16
    lda #$0118
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    clc
    rts
recover_left_child_after_twenty_four_ticks_c27fa7:
    inc a:$0094,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
recover_left_child_after_twenty_four_ticks_c27fb3:
    clc
    rts
