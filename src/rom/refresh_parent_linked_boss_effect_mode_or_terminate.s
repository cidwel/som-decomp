; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child-follow.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3151
refresh_parent_linked_boss_effect_mode_or_terminate:
    ldx $87
    ldy a:$00B0,X
    lda a:$00A7,Y
    beq refresh_parent_linked_boss_effect_mode_or_terminate_c23170
    cmp a:$00A7,X
    beq refresh_parent_linked_boss_effect_mode_or_terminate_c2316e
    sta a:$00A7,X
    asl
    tax
    lda f:$C23172,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
refresh_parent_linked_boss_effect_mode_or_terminate_c2316e:
    clc
    rts
refresh_parent_linked_boss_effect_mode_or_terminate_c23170:
    sec
    rts
