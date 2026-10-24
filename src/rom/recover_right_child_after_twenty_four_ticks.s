; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-right-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $80D9
recover_right_child_after_twenty_four_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc recover_right_child_after_twenty_four_ticks_c28104
    lda a:$0190,X
    bmi recover_right_child_after_twenty_four_ticks_c280f6
    dec a:$0094,X
    .a16
    lda #$0118
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    clc
    rts
recover_right_child_after_twenty_four_ticks_c280f6:
    inc a:$0094,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    clc
    rts
recover_right_child_after_twenty_four_ticks_c28104:
    clc
    rts
