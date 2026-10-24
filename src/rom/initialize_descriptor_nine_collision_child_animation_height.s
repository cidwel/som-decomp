; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $661C
initialize_descriptor_nine_collision_child_animation_height:
    ldx $87
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$00C7
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0066,X
    inc a:$0094,X
