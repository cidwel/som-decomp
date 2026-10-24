; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7464
initialize_leaping_projectile_animation_and_motion_callback:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$0104
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B2,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$3F4C
    sta a:$0090,X
    clc
    rts
