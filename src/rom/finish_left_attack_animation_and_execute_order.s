; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_left_attack_by_variant_and_order = $81A9
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8191
finish_left_attack_animation_and_execute_order:
    ldx $87
    lda a:$009E,X
    bne finish_left_attack_animation_and_execute_order_c281a7
    dec a:$0094,X
    .a16
    lda #$011D
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$00B4,X
    jsr dispatch_left_attack_by_variant_and_order
finish_left_attack_animation_and_execute_order_c281a7:
    clc
    rts
