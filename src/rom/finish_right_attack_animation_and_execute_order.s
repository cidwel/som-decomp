; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_right_attack_by_variant_and_order = $8295
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $827D
finish_right_attack_animation_and_execute_order:
    ldx $87
    lda a:$009E,X
    bne finish_right_attack_animation_and_execute_order_c28293
    dec a:$0094,X
    .a16
    lda #$011D
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$00B4,X
    jsr dispatch_right_attack_by_variant_and_order
finish_right_attack_animation_and_execute_order_c28293:
    clc
    rts
