; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-animation-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $31E0
initialize_animation_linked_child_depth_and_existing_seed:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$07FF
    sta a:$0022,X
    lda a:$009A,X
    jsr select_boss_animation_and_reset_frame_cursor
