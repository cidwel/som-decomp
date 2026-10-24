; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6FAC
initialize_descriptor_eight_child_animation_and_cycle:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$00FA
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    sta a:$0000,X
    stz a:$00B2,X
    stz a:$00B4,X
