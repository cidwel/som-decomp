; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child-follow.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3129
initialize_parent_linked_boss_effect_animation_and_following:
    ldx $87
    inc a:$0094,X
    stz a:$0029,X
    stz a:$0030,X
    stz a:$0066,X
    .a16
    lda #$0001
    sta a:$008C,X
    lda a:$00A7,X
    asl
    tax
    lda f:$C23172,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$3182
    sta a:$0090,X
