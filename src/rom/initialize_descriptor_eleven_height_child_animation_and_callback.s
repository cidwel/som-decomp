; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8E46
initialize_descriptor_eleven_height_child_animation_and_callback:
    ldx $87
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$015A
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    .a16
    lda #$8E92
    sta a:$0090,X
    stz a:$00B2,X
