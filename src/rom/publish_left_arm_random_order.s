; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-action-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7C6D
publish_left_arm_random_order:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    .a16
    ora #$8000
    ldx $87
    sta a:$00B4,X
    .a16
    lda #$012F
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B2,X
    rts
