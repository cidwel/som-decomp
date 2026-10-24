; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $842E
match_right_child_animation_pointer_and_seed_linked_effect:
    ldy a:$00B0,X
    lda a:$00A0,Y
    sta $95
    .i16
    ldx #$0000
match_right_child_animation_pointer_and_seed_linked_effect_c28439:
    lda f:$C2F000,X
    cmp $95
    beq match_right_child_animation_pointer_and_seed_linked_effect_c2844a
    inx
    inx
    .i16
    cpx #$0006
    bne match_right_child_animation_pointer_and_seed_linked_effect_c28439
    sec
    rts
match_right_child_animation_pointer_and_seed_linked_effect_c2844a:
    lda f:$C2F006,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    clc
    rts
