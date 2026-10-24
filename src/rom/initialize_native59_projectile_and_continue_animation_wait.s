; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $89E1
initialize_native59_projectile_and_continue_animation_wait:
    ldx $87
    .a16
    lda #$0001
    sta a:$0000,X
    inc a:$0094,X
    .a16
    lda #$010C
    jsr select_boss_animation_and_reset_frame_cursor
