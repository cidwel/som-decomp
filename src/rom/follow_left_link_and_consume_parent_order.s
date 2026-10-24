; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16

follow_mirrored_linked_child_with_sine_direction_offset = $8322
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $815D
follow_left_link_and_consume_parent_order:
    ldx $87
    jsr follow_mirrored_linked_child_with_sine_direction_offset
    ldy a:$00B2,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    beq follow_left_link_and_consume_parent_order_c2818f
    ldy a:$00B2,X
    lda a:$00B4,Y
    .a16
    bit #$8000
    beq follow_left_link_and_consume_parent_order_c2818d
    .a16
    and #$00FF
    sta a:$00B4,X
    inc a:$0094,X
    .a16
    lda #$011C
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0000
    sta a:$00B4,Y
follow_left_link_and_consume_parent_order_c2818d:
    clc
    rts
follow_left_link_and_consume_parent_order_c2818f:
    sec
    rts
