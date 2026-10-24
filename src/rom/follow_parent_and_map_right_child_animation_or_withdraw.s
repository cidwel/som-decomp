; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16

match_right_child_animation_pointer_and_seed_linked_effect = $842E
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8403
follow_parent_and_map_right_child_animation_or_withdraw:
    ldx $87
    ldy a:$00B2,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    beq follow_parent_and_map_right_child_animation_or_withdraw_c28421
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sta a:$0032,X
    jsr match_right_child_animation_pointer_and_seed_linked_effect
    clc
    rts
follow_parent_and_map_right_child_animation_or_withdraw_c28421:
    .a16
    lda #$0133
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    clc
    rts
