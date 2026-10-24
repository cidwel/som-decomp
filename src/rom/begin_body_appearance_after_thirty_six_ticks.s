; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4BF0
begin_body_appearance_after_thirty_six_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0024
    bcc begin_body_appearance_after_thirty_six_ticks_c24c0b
    .a16
    lda #$0001
    sta a:$0094,X
    .a16
    lda #$0077
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    clc
    rts
begin_body_appearance_after_thirty_six_ticks_c24c0b:
    clc
    rts
