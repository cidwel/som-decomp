; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $478F
move_auxiliary_record_until_native54_return_animation:
    ldx $87
    sep #$20
    lda a:$F812,Y
    clc
    .a8
    adc #$02
    sta a:$F812,Y
    lda a:$F80E,Y
    clc
    .a8
    adc #$01
    sta a:$F80E,Y
    rep #$20
    lda a:$F811,Y
    .a16
    cmp #$D800
    bcc move_auxiliary_record_until_native54_return_animation_c247bb
    .a16
    lda #$0008
    sta a:$0094,X
    .a16
    lda #$0073
    jsr select_boss_animation_and_reset_frame_cursor
move_auxiliary_record_until_native54_return_animation_c247bb:
    clc
    rts
