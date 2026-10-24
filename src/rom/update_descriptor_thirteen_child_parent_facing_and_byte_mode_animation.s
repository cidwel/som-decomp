; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6A37
update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcs update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a88
    ldy a:$00B0,X
    lda a:$0098,Y
    .a16
    and #$0040
    sta $95
    lda a:$0098,X
    .a16
    and #$FFBF
    ora $95
    sta a:$0098,X
    sep #$20
    lda a:$0089,Y
    cmp a:$00B4,X
    beq update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a84
    sta a:$00B4,X
    .i16
    ldx #$0000
update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a6a:
    cmp f:$C26A8A,X
    beq update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a76
    inx
    .i16
    cpx #$0004
    bcc update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a6a
update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a76:
    rep #$20
    txa
    asl
    tax
    lda f:$C26A8E,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a84:
    rep #$20
    clc
    rts
update_descriptor_thirteen_child_parent_facing_and_byte_mode_animation_c26a88:
    sec
    rts
