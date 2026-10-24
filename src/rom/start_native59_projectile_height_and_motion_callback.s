; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $89F2
start_native59_projectile_height_and_motion_callback:
    ldx $87
    lda a:$009E,X
    bne start_native59_projectile_height_and_motion_callback_c28a17
    inc a:$0094,X
    .a16
    lda #$010D
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0010
    sta a:$0066,X
    .a16
    lda #$001E
    sta a:$00C6,X
    sta a:$00B4,X
    .a16
    lda #$3F4C
    sta a:$0090,X
start_native59_projectile_height_and_motion_callback_c28a17:
    clc
    rts
