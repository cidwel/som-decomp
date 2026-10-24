; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7003
refresh_descriptor_eight_child_parent_state_animation:
    lda a:$007A,Y
    asl
    tax
    lda f:$DCE4A9,X
    ldx $87
    cmp a:$00B4,X
    beq refresh_descriptor_eight_child_parent_state_animation_c27019
    sta a:$00B4,X
    jsr select_boss_animation_and_reset_frame_cursor
refresh_descriptor_eight_child_parent_state_animation_c27019:
    rts
