; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $53BD
refresh_descriptor_fourteen_child_variant_parent_mode_animation:
    lda a:$00B2,X
    bne refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253da
    lda a:$007A,Y
    asl
    tax
    lda f:$DCE1EA,X
    ldx $87
    cmp a:$00B4,X
    beq refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253f0
    sta a:$00B4,X
    jsr select_boss_animation_and_reset_frame_cursor
    bra refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253f0
refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253da:
    lda a:$007A,Y
    asl
    tax
    lda f:$DCE21C,X
    ldx $87
    cmp a:$00B4,X
    beq refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253f0
    sta a:$00B4,X
    jsr select_boss_animation_and_reset_frame_cursor
refresh_descriptor_fourteen_child_variant_parent_mode_animation_c253f0:
    rts
