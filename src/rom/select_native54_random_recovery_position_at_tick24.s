; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $49AF
select_native54_random_recovery_position_at_tick24:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bne select_native54_random_recovery_position_at_tick24_c249f1
    .a16
    lda #$0001
    sta a:$0094,X
    .a16
    lda #$0074
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$0042,X
    xba
    lsr
    lsr
    sta $95
    .a16
    lda #$000B
    jsr draw_boss_frame_random_number
    asl
    asl
    clc
    adc $95
    tax
    lda f:$C249F3,X
    sta $95
    lda f:$C249F5,X
    sta $97
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
select_native54_random_recovery_position_at_tick24_c249f1:
    clc
    rts
