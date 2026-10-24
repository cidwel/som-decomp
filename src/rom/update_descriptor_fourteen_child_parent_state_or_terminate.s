; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen-child.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_descriptor_fourteen_child_variant_parent_mode_animation = $53BD

.segment "CODE"
.org $538B
update_descriptor_fourteen_child_parent_state_or_terminate:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcs update_descriptor_fourteen_child_parent_state_or_terminate_c2539d
    jsr refresh_descriptor_fourteen_child_variant_parent_mode_animation
    clc
    rts
update_descriptor_fourteen_child_parent_state_or_terminate_c2539d:
    sec
    rts
