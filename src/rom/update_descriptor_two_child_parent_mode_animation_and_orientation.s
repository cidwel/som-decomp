; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $40C3
update_descriptor_two_child_parent_mode_animation_and_orientation:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcc update_descriptor_two_child_parent_mode_animation_and_orientation_c240d2
    sec
    rts
update_descriptor_two_child_parent_mode_animation_and_orientation_c240d2:
    lda a:$007A,Y
    sta $9D
    lda a:$00AB,Y
    sta $9F
    lda $9D
    cmp a:$00B2,X
    bne update_descriptor_two_child_parent_mode_animation_and_orientation_c240ea
    lda $9F
    cmp a:$00AB,X
    beq update_descriptor_two_child_parent_mode_animation_and_orientation_c24141
update_descriptor_two_child_parent_mode_animation_and_orientation_c240ea:
    lda $9D
    sta a:$00B2,X
    lda $9F
    sta a:$00AB,X
    lda a:$0042,Y
    bne update_descriptor_two_child_parent_mode_animation_and_orientation_c24103
    lda a:$00B2,X
    tax
    lda f:$DCE0A8,X
    bra update_descriptor_two_child_parent_mode_animation_and_orientation_c2410b
update_descriptor_two_child_parent_mode_animation_and_orientation_c24103:
    lda a:$00B2,X
    tax
    lda f:$DCE0D0,X
update_descriptor_two_child_parent_mode_animation_and_orientation_c2410b:
    .a16
    and #$00FF
    beq update_descriptor_two_child_parent_mode_animation_and_orientation_c24141
    .a16
    cmp #$00FF
    bne update_descriptor_two_child_parent_mode_animation_and_orientation_c2411c
    ldx $87
    stz a:$0000,X
    clc
    rts
update_descriptor_two_child_parent_mode_animation_and_orientation_c2411c:
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$00B2,X
    tax
    lda f:$DCE103,X
    .a16
    and #$00C0
    sta $95
    ldx $87
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $95
    sta a:$0098,X
    .a16
    lda #$0001
    sta a:$0000,X
update_descriptor_two_child_parent_mode_animation_and_orientation_c24141:
    clc
    rts
