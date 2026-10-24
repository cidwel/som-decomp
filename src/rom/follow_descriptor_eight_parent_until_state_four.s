; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_descriptor_eight_child_animation_palette_cycle = $701A
refresh_descriptor_eight_child_parent_state_animation = $7003

.segment "CODE"
.org $6FC3
follow_descriptor_eight_parent_until_state_four:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0004
    bcs follow_descriptor_eight_parent_until_state_four_c26fe4
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sta a:$0032,X
    jsr refresh_descriptor_eight_child_parent_state_animation
    jsr dispatch_descriptor_eight_child_animation_palette_cycle
    clc
    rts
follow_descriptor_eight_parent_until_state_four_c26fe4:
    inc a:$0094,X
    clc
    rts
