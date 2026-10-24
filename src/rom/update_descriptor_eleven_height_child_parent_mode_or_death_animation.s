; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8E60
update_descriptor_eleven_height_child_parent_mode_or_death_animation:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcs update_descriptor_eleven_height_child_parent_mode_or_death_animation_c28e85
    lda a:$007A,Y
    asl
    tax
    lda f:$C28EE8,X
    ldx $87
    cmp a:$00B2,X
    beq update_descriptor_eleven_height_child_parent_mode_or_death_animation_c28e83
    sta a:$00B2,X
    jsr select_boss_animation_and_reset_frame_cursor
update_descriptor_eleven_height_child_parent_mode_or_death_animation_c28e83:
    clc
    rts
update_descriptor_eleven_height_child_parent_mode_or_death_animation_c28e85:
    inc a:$0094,X
    .a16
    lda #$0133
    jsr select_boss_animation_and_reset_frame_cursor
    clc
    rts
