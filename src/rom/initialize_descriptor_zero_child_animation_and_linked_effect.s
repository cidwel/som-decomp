; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_parent_linked_boss_effect_and_copy_coordinates = $3385
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3E37
initialize_descriptor_zero_child_animation_and_linked_effect:
    ldx $87
    .a16
    lda #$014E
    sta a:$002B,X
    .a16
    lda #$013E
    sta a:$0032,X
    inc a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$00E7
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    jsr allocate_parent_linked_boss_effect_and_copy_coordinates
