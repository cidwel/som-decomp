; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-definitions.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6D7D
initialize_target_tracking_boss_child:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$00E5
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B2,X
    stz a:$0066,X
    .a16
    lda #$0001
    sta a:$0000,X
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$000B,Y
    sta a:$000B,X
    rep #$20
    .a16
    lda #$3F4C
    sta a:$0090,X
