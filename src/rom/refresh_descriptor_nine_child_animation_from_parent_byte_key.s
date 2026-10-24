; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6678
refresh_descriptor_nine_child_animation_from_parent_byte_key:
    sep #$30
    .i8
    ldx #$00
refresh_descriptor_nine_child_animation_from_parent_byte_key_c2667c:
    lda f:$DCE34A,X
    cmp $99
    beq refresh_descriptor_nine_child_animation_from_parent_byte_key_c2668d
    inx
    .i8
    cpx #$04
    bne refresh_descriptor_nine_child_animation_from_parent_byte_key_c2667c
    rep #$30
    sec
    rts
refresh_descriptor_nine_child_animation_from_parent_byte_key_c2668d:
    txa
    rep #$30
    .a16
    and #$00FF
    asl
    tax
    lda f:$DCE34E,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    clc
    rts
